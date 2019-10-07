#include "ball.h"

Ball::Ball(int xCor, int yCor, int size)
{
    this->xCor = xCor;
    this->yCor = yCor;
    this->size = size;
    xDir = -1;
    yDir = -1;
    defaultXCor = xCor;
}

int Ball::getXCor()
{
    return xCor;
}

int Ball::getYCor()
{
    return yCor;
}

int Ball::getSize()
{
   return size;
}

void Ball::setXCor()
{
    xCor += xDir;
}

void Ball::setYCor()
{
    yCor += yDir;
}

void Ball::reverseXDir()
{
    xDir *= -1;
}

void Ball::reverseYDir()
{
    yDir *= -1;
}

void Ball::move()
{
    setXCor();
    setYCor();
    if(getYCor() == 0 || getYCor() == 450)
    {
        reverseYDir();
    }
    if(getXCor() == 0 || getXCor() == 750)
    {
        xCor = defaultXCor;
    }

}
