#include "Game.h"
#include "Board.h"
#include "Cell.h"
#include "Pieces/BasePiece.h"
#include "Utils.h"

Game::Game() : m_turnNumber(0), m_currentPlayer(White), m_board(new Board()) { }

bool Game::move(int before, int after) {
    if (before < 0 || before >= Board::boardSize * Board::boardSize)
        throw Utils::ImpossibleMove("A movement cannot start outside the board");

    if (after < 0 ||  after >= Board::boardSize * Board::boardSize)
        throw Utils::ImpossibleMove("A movement cannot end outside the board");

    if (after == before)
        throw Utils::ImpossibleMove("A movement has to move a piece");

    Cell *cell = m_board->getCell(before);
    if (cell->getState() != Busy && cell->getPiece()->getColor() != m_currentPlayer)
        return false;

    else if (m_board->movePiece(before, after)) {
        m_currentPlayer = (PlayerColor) (((int) m_currentPlayer + 1) % 2);

        if (m_currentPlayer == White)
            m_turnNumber++;

        return true;
    }

    return false;
}
