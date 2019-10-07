#ifndef BALL_H
#define BALL_H


class Ball
{
public:
    Ball(int xCor, int yCor, int size);
    int getXCor();
    int getYCor();
    int getSize();
    void reverseXDir();
    void reverseYDir();
    void move();

private:
    int xCor;
    int yCor;
    int size;
    int xDir;
    int yDir;
    int defaultXCor;
    void setXCor();
    void setYCor();

};

#endif // BALL_H
