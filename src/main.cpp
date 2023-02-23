#include "mainwindow.h"
#include <QApplication>
#include "Game/Board.h"

void startGame() {
    Board *board = new Board();
    board->printBoard();
}

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();
    (void) argc;
    (void) argv;
    startGame();
    return 0;
}
