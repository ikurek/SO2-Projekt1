#ifndef FALLINGSTARS_STAR_H
#define FALLINGSTARS_STAR_H


class Star {

private:
    int yMax;
    int getRandomSleepTime();

public:
    Star(int threadID, int numberOfTerminalRows);
    Star();
    void moveByOne();
    bool canMove;
    int timeToNextMove;
    int x;
    int y;


};


#endif //FALLINGSTARS_STAR_H
