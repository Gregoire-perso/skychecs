#ifndef CELL_H
#define CELL_H
#include "Enums.h"
#include "Pieces/King.h"
#include "Pieces/Queen.h"
#include "Pieces/Bishop.h"
#include "Pieces/Knight.h"
#include "Pieces/Rook.h"
#include "Pieces/Pawn.h"

/**
 * @class Cell
 * @brief The class that create the different cells of a Board
 */
class Cell {
private:
    /// Position in the board
    int m_position;

    /// The board to which the cell is connected
    Board *m_board;

    /// The cell state
    CellState m_state;

    /// The piece in this cell, NULL if empty
    BasePiece *m_piece;

public: 
    /**
     * @brief This contructor init an empty cell
     *
     * @param *board   The pointer to which board the cell is linked
     * @param position The position of this cell on the board
     */
    Cell(Board *board, int position);

    /**
     * @brief This constructor init a cell with the given piece characteristics
     *
     * @param *board   The pointer to which board the cell is linked
     * @param position The position of this cell on the board
     * @param type     The type of the piece to init
     * @param color    The color of the piece to init
     */
    Cell(Board *board, int position, PieceType type, PlayerColor color);

    /**
     * @brief Getter of the position of this cell
     *
     * @return The position of this cell
     */
    int getPosition() { return m_position; };
    
    /**
     * @brief Getter of the state of this cell
     *
     * @return The state of this cell
     */
    CellState getState() { return m_state; };
    
    /**
     * @brief Getter of the piece
     *
     * @return A pointer to the piece currently on this cell
     */
    BasePiece *getPiece() { return m_piece; };
    
    /**
     * @brief Setter of the non-Busy states
     *
     * @param newState The new state
     *
     * @warning Should not pass the state Busy to this function, because the
     * Busy state should assure that the m_piece member is not NULL
     */
    void setState(CellState newState);
    
    /**
     * @brief Setter of the Busy state
     *
     * @param *new_piece A pointer to the piece that should be on this cell
     *
     * @pre The pointer should not be NULL
     * @warning No verification are made about the legality of the change if the
     * cell was already Busy
     */
    void setState(BasePiece *new_piece);
};

#endif
