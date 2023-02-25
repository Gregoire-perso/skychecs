#include "mainwindow.h"
#include <QApplication>
#include "Game/Board.h"

using namespace std;

void pawnTest(Board *board) {

    cout << "PAWN MOVES TEST" << endl;
    board->printBoard();
    cout << " 8 -> 16 = true : " << board->movePiece(8, 16) << endl;
    cout << " 8 -> 16 = false: " << board->movePiece(8, 16) << endl;
    cout << "16 -> 17 = false: " << board->movePiece(16, 17) << endl;
    cout << "16 -> 24 = true : " << board->movePiece(16, 24) << endl;
    board->printBoard();

    cout << endl << endl << endl;
}

void rookTest(Board *board) {

    cout << "ROOK MOVES TEST" << endl;
    board->printBoard();
    cout << " 0 -> 16 = true : " << board->movePiece(0, 16) << endl;
    cout << "16 -> 24 = false: " << board->movePiece(16, 24) << endl;
    cout << "16 -> 25 = false: " << board->movePiece(16, 25) << endl;
    cout << "16 -> 22 = true : " << board->movePiece(16, 22) << endl;
    board->printBoard();

    cout << endl << endl << endl;
}

void startGame() {
    Board *board = new Board();
    pawnTest(board);
    rookTest(board);
}

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();
    (void) argc;
    (void) argv;
    cout << boolalpha;
    startGame();
    return 0;
}
