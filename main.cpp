#include <iostream>
#include <thread>
#include <ncurses.h>
#include "Star.h"

int numberOfTerminalColumns;
int numberOfTerminalRows;

using namespace std;

void fallingStarThread(Star* starInThread) {
    while (starInThread->canMove) {
        this_thread::sleep_for(chrono::milliseconds(starInThread->timeToNextMove));
        starInThread -> moveByOne();
        starInThread -> validate();
    }
}

bool shouldContinuePrinting(Star stars[]) {
  for (int i = 0; i < numberOfTerminalColumns; ++ i) {
    if (stars[i].canMove) return true;
  }
  return false;
}

void uiThread() {
  // Init curses
  initscr();
  // Hide cursor
  curs_set(0);
  // Get screen size
  getmaxyx(stdscr, numberOfTerminalRows, numberOfTerminalColumns);
  // Create array of threads for stars
  thread threads[numberOfTerminalColumns];
  // Create array of stars
  Star stars[numberOfTerminalColumns];
  // Create a single thread for each array element
  for (int  i = 0;  i < numberOfTerminalColumns; ++ i) {
      stars[i] = Star(i, numberOfTerminalRows);
      threads[i] = thread(fallingStarThread, &stars[i]);
  }
  // Loop prints stars until they are all marked as locked
  while(shouldContinuePrinting(stars)) {
    // Print stars in their current position
    for(int  i = 0;  i < numberOfTerminalColumns; ++ i) {
      // If star is moving, draw it
      if(stars[i].canMove) {
        mvprintw(stars[i].y - 1, stars[i].x, " ");
        mvprintw(stars[i].y, stars[i].x, "*");
      }
      // If it finished, draw underscore instead
      else {
        mvprintw(stars[i].y - 1, stars[i].x, "_");
      }
    }
    // Refresh display
    refresh();
  }

  // End curses
  clear();
  printw("Press any button to quit");
  getch();
  endwin();
}

int main() {
    // Create thread for UI
    // And join it to maon thread
    thread(uiThread).join();
    return 0;
}
