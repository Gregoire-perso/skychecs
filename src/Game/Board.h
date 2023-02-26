#ifndef BOARD_H
#define BOARD_H
#include "Enums.h"
#include "Cell.h"
#include <iostream>
#include <string>


class Cell;

/**
 * @class Board
 * @brief This class will manage a chess board. 
 */
class Board {
public:
    /// Store the know size of a board
    static const int boardSize = 8;

    /**
     * @brief Build a blank board
     *
     * The constructor add the different pieces in the default chess
     * configuration
     */
    Board();
    
    /**
     * @brief Build a board from a save
     *
     * This constructor load the given file and extract its content to rebuild a
     * saved board
     *
     * @param filename The name of the save
     */
    Board(std::string filename);

    /**
     * @param position The position of the cell in raw major format
     * @returns a pointer to the asked cell
     */
    Cell *getCell(int position);

    /**
     * @brief Move a piece from @p before to @p after
     *
     * @param before The position of the piece beofre the move
     * @param after  The position of the piece after the move
     *
     * @pre @p before and @p after must me in a valid range (e.g. between 0 and
     * 63 for a 64-cells board)
     * 
     * @return true if the move is done succesfully, false otherwise
     */
    bool movePiece(int before, int after);

    /**
     * @brief Does the given color has won ?
     *
     * @param color The color concerned by the potential victory
     * 
     * @return true if the player @p color has won
     */
    bool hasWon(PlayerColor color);

    /**
     * @brief Print the board in the standard output
     */
    void printBoard();

    /**
     * @brief Serialize the current board
     *
     * @param filename The path to the output file
     * 
     * @return if the serialization has been successful or not
     */
    bool serialize(std::string filename);

private:

    /// Cells pointers array in raw major format
    Cell *m_board[boardSize * boardSize];
};

#endif
