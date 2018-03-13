#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Star.h"

using namespace std;

Star::Star(int threadID, int numberOfTerminalRows) {
    // Starting position (x, y) is (ID of thread, 0)
    this -> x = threadID;
    this -> y = 0;
    // Maximum y value is the same as max number of rows in terminal
    this -> yMax = numberOfTerminalRows;
    // Each star can move at start
    this -> canMove = true;
    // Time to move next is random between 0 - 1 seconds
    this -> timeToNextMove = getRandomSleepTime();
}

Star::Star() {

}

int Star::getRandomSleepTime() {
    // Calculate seed from current time and thread ID
    unsigned int seed = time(NULL) + (this -> x);
    // Generate random number in range
    int randNum = rand_r(&seed)%(400);
    // Return found number
    return randNum;
}

void Star::moveByOne() {
    // If y is max, disable move
    if (y >= yMax) {
        canMove = false;
    } else {
      y = y + 1;
    }
}

void Star::validate() {
  if (y >= yMax) {
      canMove = false;
  }
}
