#ifndef AI_H
#define AI_H


class AI
{
public:
    AI();
    int move();

private:
    int movement(int ballXCor, int paddleHeight);
};

#endif // AI_H
