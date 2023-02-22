#ifndef CELL_H
#define CELL_H
#include "Board.h"
#include "Pieces/BasePiece.h"
#include "Pieces/King.h"
#include "Pieces/Queen.h"
#include "Pieces/Bishop.h"
#include "Pieces/Knight.h"
#include "Pieces/Rook.h"
#include "Pieces/Pawn.h"


// Free and Busy states are obvious
enum CellState { Free, Busy };

class Cell {
private:
    int m_position;
    Board *m_board;
    CellState m_state;
    BasePiece *m_piece;

public: 
    Cell(Board board, int position);
    Cell(Board board, int position, PieceType type, PlayerColor color);
    int getPosition() { return m_position };
    CellState getState() { return m_state };
    BasePiece *getPiece() { return m_piece };
    void setState(CellState newState);
    
    // Think to remove the old piece if there is one
    void setState(BasePiece *new_piece);
}

#endif
