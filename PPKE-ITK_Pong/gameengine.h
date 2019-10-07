#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "ball.h"
#include "paddle.h"
#include <QTimer>




class GameEngine
{
public:
    GameEngine();
    Ball *ball;
    Paddle *player1;
    Paddle *player2;
    bool w;
    bool s;
    bool o;
    bool l;
    bool gamemodeSingle;
    void gameControl();
    void scoring();
    int getPlayer1Score();
    int getPlayer2Score();
    void resetPlayerScores();

private:
    QTimer *ballTimer;
    int player1Score;
    int player2Score;
    void playerMoves();
    void gamemode();
    void player2AI();
    bool player1CollDetect();
    bool player2CollDetect();
    void collisionHandle();

private slots:
    void ballEngine();
};

#endif // GAMEENGINE_H
