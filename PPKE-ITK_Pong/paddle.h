#ifndef PADDLE_H
#define PADDLE_H


class Paddle
{
public:
    Paddle(int yCor, int xCor, int sizeY, int sizeX);
    int getXCor();
    int getYCor();
    int getSizeX();
    int getSizeY();
    void setYCor(int newCor);
    void move(int movement);

private:
    int xCor;
    int yCor;
    int sizeX;
    int sizeY;
};

#endif // PADDLE_H
