#ifndef ENUMS_H
#define ENUMS_H

// Store the enums and the types used in this project

/**
 * @enum PlayerColor
 * @brief The enumeration to differenciate Black and White pieces
 */
enum PlayerColor { White, Black };

/**
 * @enum PieceType
 * @brief The piece types
 *
 * Associated chars are the chars used by print_board() function
 */
enum PieceType: char { TKing = 'K', TQueen = 'Q', TBishop = 'B', 
                       TKnight = 'k', TRook = 'R', TPawn = 'P' };

/**
 * @enum CellState
 * @brief The differents states a cell can be during the game
 */
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


