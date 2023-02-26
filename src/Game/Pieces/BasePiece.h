#ifndef BASE_PIECE_H
#define BASE_PIECE_H
#include <vector>
#include "../Enums.h"

/**
 * @class BasePiece
 * @brief An abstract class that will be the base of each piece
 */
class BasePiece {
protected: 
    /// The piece type
    PieceType m_type;

    /// The board to which the piece is linked
    Board *m_board;

    /// The current cell to which the piece is positionned
    Cell *m_cell;

    /// The color of this piece
    PlayerColor m_color;

    /**
     * @brief This function check if the move is possible
     *
     * @param new_pos The new position to test
     *
     * @return True if the @p new_pos position is valid, false otherwise
     */
    virtual bool checkMove(int new_pos);

    /**
     * @brief Remove all the potential positions that are already occupied by a
     * friendly piece.
     *
     * @param *candidates A pointer to the vector of potential positions
     */
    void pruneCandidates(std::vector<int> *candidates);

public:
    /**
     * @brief The constructor of a lambda piece
     *
     * @param *cell  A pointer to the cell where the piece is positionned
     * @param *board A pointer to the board to which the piece is connected
     * @param color  The color of this piece
     */
    BasePiece(Cell *cell, Board *board, PlayerColor color);
    
    /**
     * @brief Destroy this piece
     * @remark Make sure that the cell that currently contains this piece is
     * freed
     */
    virtual ~BasePiece();
    
    /**
     * @brief Move a piece to its new position @p new_pos
     *
     * @param new_pos The new position
     * 
     * @remark This function make all the verification without throwing errors
     *
     * @return True if the move is done, false otherwise
     */
    virtual bool move(int new_pos);
    
    /**
     * @brief List all the possible moves
     *
     * @return The vector of all the potential new positions
     */
    virtual std::vector<int> possibleMoves() = 0;

    /**
     * @return The cell of this piece
     */
    Cell *getCell() { return m_cell; };
    
    /**
     * @return The color of this piece
     */
    PlayerColor getColor() { return m_color; };
    
    /**
     * @return The type of this piece
     */
    PieceType getType() { return m_type; };
};

#endif


