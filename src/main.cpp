#include "mainwindow.h"
#include <QApplication>
#include "Game/Board.h"

using namespace std;

void startGame() {
    Board *board = new Board();
    board->printBoard();
    cout << board->movePiece(8, 16) << endl;
    cout << board->movePiece(8, 16) << endl;
    cout << board->movePiece(16, 17) << endl;
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
