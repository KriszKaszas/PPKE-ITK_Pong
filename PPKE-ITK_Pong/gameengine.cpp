#include "gameengine.h"

GameEngine::GameEngine()
{
    ball = new Ball(385, 235, 20);
    player1 = new Paddle(185, 0, 80, 10);
    player2 = new Paddle(185, 760, 80, 10);
    w = false;
    s = false;
    o = false;
    l = false;
    player1Score = 0;
    player2Score = 0;
}

void GameEngine::gameControl()
{
    scoring();
    gamemode();
}

void GameEngine::playerMoves()
{
    if(w && player1->getYCor() != 0)
        player1->move(-1);
    if(s&& player1->getYCor() != 390)
        player1->move(1);
    if(o && player2->getYCor() != 0 && !gamemodeSingle)
        player2->move(-1);
    if(l && player2->getYCor() != 390 && !gamemodeSingle)
        player2->move(1);
}

void GameEngine::gamemode()
{
    collisionHandle();
    ball->move();
    playerMoves();
    if(gamemodeSingle)
    {
        player2AI();
    }
}

void GameEngine::player2AI()
{
    if(ball->getYCor() > 30 && ball->getYCor() < 420)
        player2->setYCor(ball->getYCor());
}

bool GameEngine::player1CollDetect()
{
    return ball->getXCor() == 10 && (ball->getYCor() > player1->getYCor()-10 && ball->getYCor() < player1->getYCor()+90);
}

bool GameEngine::player2CollDetect()
{
    return ball->getXCor() == 740 && (ball->getYCor() > player2->getYCor()-10 && ball->getYCor() < player2->getYCor()+90);
}

void GameEngine::collisionHandle()
{
    if(player1CollDetect() || player2CollDetect())
    {
        ball->reverseXDir();
    }
}

void GameEngine::scoring()
{
    if(ball->getXCor() == 2)
    {
        player2Score++;
    }
    if(ball->getXCor() == 748)
    {
        player1Score++;
    }
}

int GameEngine::getPlayer1Score()
{
    return player1Score;
}

int GameEngine::getPlayer2Score()
{
    return player2Score;
}

void GameEngine::resetPlayerScores()
{
    player1Score = 0;
    player2Score = 0;
}
