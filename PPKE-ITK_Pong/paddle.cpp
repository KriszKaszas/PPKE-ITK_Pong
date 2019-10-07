#include "paddle.h"

Paddle::Paddle(int yCor, int xCor, int sizeY, int sizeX)
{
    this->xCor = xCor;
    this->yCor = yCor;
    this->sizeX = sizeX;
    this->sizeY = sizeY;
}

int Paddle::getXCor()
{
    return xCor;
}

int Paddle::getYCor()
{
    return yCor;
}

int Paddle::getSizeX()
{
   return sizeX;
}

int Paddle::getSizeY()
{
   return sizeY;
}

void Paddle::setYCor(int newCor)
{
    yCor = newCor-30;
}

void Paddle::move(int movement)
{
    yCor += movement;
}
