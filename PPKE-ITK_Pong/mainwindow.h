#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gameengine.h"

#include <QGraphicsScene>
#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *sc;
    GameEngine *engine;
    QTimer *gameTimer;
    QMessageBox *rules;
    QMessageBox *winner;

    void reset();
    void drawGame();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);


private slots:
    void frame();
    void on_singlePlayer_clicked();
    void on_multiPlayer_clicked();
    void on_playButton_clicked();
    void on_instructionsButton_clicked();
};
#endif // MAINWINDOW_H
