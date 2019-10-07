#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sc = new QGraphicsScene(0, 0, 770, 470);
    sc->setBackgroundBrush(Qt::black);

    ui->graphicsView->setScene(sc);
    rules = new QMessageBox();
    winner = new QMessageBox();

    engine = new GameEngine();
    ui->singlePlayer->setChecked(true);
    engine->gamemodeSingle = true;
    gameTimer = new QTimer();
    connect(gameTimer, SIGNAL(timeout()), this, SLOT(frame()));
    drawGame();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::frame()
{

    engine->gameControl();
    drawGame();
    if(engine->getPlayer1Score() == 3)
    {
        winner->setText("PLAYER 1 WINS!      ");
        winner->show();
        reset();
    }
    if(engine->getPlayer2Score() == 3)
    {
        winner->setText("PLAYER 2 WINS!      ");
        winner->show();
        reset();
    }

}

void MainWindow::reset()
{
    gameTimer->stop();
    engine->resetPlayerScores();
    ui->playButton->setText("PLAY AGAIN");
    ui->playButton->setEnabled(true);
    ui->singlePlayer->setEnabled(true);
    ui->multiPlayer->setEnabled(true);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_W:
        engine->w = true;
        break;
    case Qt::Key_S:
        engine->s = true;
        break;
    case Qt::Key_O:
        engine->o = true;
        break;
    case Qt::Key_L:
        engine->l = true;
        break;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_W:
        engine->w = false;
        break;
    case Qt::Key_S:
        engine->s = false;
        break;
    case Qt::Key_O:
        engine->o = false;
        break;
    case Qt::Key_L:
        engine->l = false;
        break;
    }
}

void MainWindow::on_playButton_clicked()
{
    gameTimer->start(10);
    ui->singlePlayer->setEnabled(false);
    ui->multiPlayer->setEnabled(false);
    ui->playButton->setEnabled(false);
    ui->instructionsButton->setEnabled(false);
    ui->playButton->setText("GAME IN PROGRESS");
}

void MainWindow::on_singlePlayer_clicked()
{
    engine->gamemodeSingle = true;
}

void MainWindow::on_multiPlayer_clicked()
{
    engine->gamemodeSingle = false;
}

void MainWindow::on_instructionsButton_clicked()
{
    rules->setText("A PONG JÁTÉK LEÍRÁSA: \n\n"
                   "- A játék egy- illetve kétjátékos módban játszható.\n\n"
                   "- Az irányítás a \"W\" és az \"S\", illetve at \"O\" és az \"L\" gombok segítségével történik.\n\n"
                   "- A játékmód kiválasztása a \"Single Player\", illetve \"Multiplayer\" radio gombokra kattintva lehetséges.\n\n"
                   "- A játék célja, hogy a labdát visszaüssük. Pontot csak úgy szerezhetünk, ha az ellenfél nem tudja visszaadni "
                   "a labdát, így az az ő térfelén a falnak ütközik.\n\n"
                   "- A játék három menetből áll. Amelyik játékos előbb szerez három pontot, az nyeri a kört.\n\n"
                   "- A játékmód megváltoztatására csak a körök végén van lenetőség (ha valamelyik játékos győzött).\n\n"
                   "JÁTÉKOSOK:\n\n"
                   "PLAYER1: A KÉPERNYŐ BAL OLDALÁN\n"
                   "PLAYER2: A KÉPERNYŐ JOBB OLDALÁN (Többjátékos módban az AI veszi át a szerepét.)\n\n"
                   "FIGYELEM: AZ ÜTŐK EGYMÁSTÓL FÜGGETLENÜL IS MOZGATHATÓK MINDKÉT JÁTÉKMÓDBAN!");
    rules->show();
}

void MainWindow::drawGame()
{
    sc->clear();
    sc->addRect(0, 0, 770, 470, QPen(Qt::white), QBrush(Qt::black));
    sc->addRect(385, 0, 1, 470,  QPen(Qt::white), QBrush(Qt::white));
    sc->addRect(engine->player1->getXCor(), engine->player1->getYCor(), engine->player1->getSizeX(), engine->player1->getSizeY(), QPen(Qt::white), QBrush(Qt::white));
    sc->addRect(engine->player2->getXCor(), engine->player2->getYCor(), engine->player2->getSizeX(), engine->player2->getSizeY(), QPen(Qt::white), QBrush(Qt::white));
    sc->addEllipse(engine->ball->getXCor(), engine->ball->getYCor(), engine->ball->getSize(), engine->ball->getSize(), QPen(Qt::white), QBrush(Qt::white));
    sc->update();
}




