#ifndef GAME_H
#define GAME_H
#include "Enums.h"
#include <string>

/**
 * @class Game
 * @brief This will manage a chess game
 *
 * This object will manage the whole game and its statistics
 */
class Game {
private:
    /// The number of turns that have been done
    int m_turnNumber;

    /// Which player must do the next move
    PlayerColor m_currentPlayer;

    /// Which player won this game
    PlayerColor m_winner;

    /// The board of the game
    Board *m_board;

public:
    /**
     * @brief Init an empty game
     *
     * Init an empty game using the default Board constructor.
     * See Board() for more details on the layout of a default game
     */
    Game();

    /**
     * @brief Init a game based on a save
     *
     * Init a game using the save Board constructor.
     * See Board(filename) for more details
     * 
     * @param number the number of the save (?)
     * @todo the whole function and save system
     */
    Game(int number);

    /**
     * @brief A function to save the game
     * @todo do the function
     * @todo Add the called functions to the doc
     */
    void save();

    /**
     * @brief Move a piece from @p before to @p after
     *
     * @throw ImpossibleMove Throw this exception if @p before or @p after are
     * illogical
     *
     * @param before The cell number of the piece to move
     * @param after  The destination cell
     *
     * @return True if the move is done successfuly
     */
    bool move(int before, int after);
};


#endif


