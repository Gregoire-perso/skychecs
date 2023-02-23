#ifndef ENUMS_H
#define ENUMS_H

// Store the enums and the types used in this project

enum PlayerColor { White, Black };

enum PieceType: char { TKing = 'K', TQueen = 'Q', TBishop = 'B', 
                       TKnight = 'k', TRook = 'R', TPawn = 'P' };

enum CellState { Free, Busy };

class Board;
class Cell;
class BasePiece;
class King;
class Queen;
class Bishop;
class Knight;
class Rook;
class Pawn;

#endif


