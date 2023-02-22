#include "mainwindow.h"
#include <QApplication>

void startGame() {
    Board board = new Board();
    board->printBoard();
}

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();
    startGame();
    return 0;
}
