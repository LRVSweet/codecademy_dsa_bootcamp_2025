#pragma once

#include <vector>

/**
 * Represents a tic-tac-toe board
 */
class Board
{
private:
    /**
     * empty_board - Stores a 2-d vector of an empty Board.
     */
    static std::vector<std::vector<char>> empty_board;
    
    /**
     * board - Stores a 2-d vector containing the current Board.
     */
    std::vector<std::vector<char>> board;

    /**
     * Checks for homogenous non-empty rows.
     * If a homogenous row of 'X' is found, returns 1
     * If a homogenous row of 'Y' is found, returns 2
     * Else, returns 0
     */
    int checkHorizontalComp();

    /**
     * Checks for homogenous non-empty columns.
     * If a homogenous column of 'X' is found, returns 1
     * If a homogenous column of 'Y' is found, returns 2
     * Else, returns 0
     */
    int checkVerticalComp();

    /**
     * Checks for homogenous non-empty diagonals.
     * If a homogenous diagonal of 'X' is found, returns 1
     * If a homogenous diagonal of 'Y' is found, returns 2
     * Else, returns 0
     */
    int checkDiagonalComp();

public:
    
    /**
     * Contructor - Accepts an optional board parameter in the form of a 2-d vector.
     * This parameter defaults to emtpy_board.
     */
    Board(std::vector<std::vector<char>> input_board = empty_board);
    
    /**
     * Return a new Board based on the current board plus the move specified in the parameters.
     * makeMove() does not mutate the current board.
     */
    Board makeMove(int vertical, int horizontal, char player);
    
    /**
     * Adds the specified move to the current board.
     */
    void storeMove(int vertical, int horizontal, char player);
    
    /**
     * Returns a 2-d vector representing the current board.
     */
    std::vector<std::vector<char>> getBoard();
    
    /**
     * Returns an integer representing the completion state of the current board:
     * 0: Incomplete (there are still legal moves to make).
     * 1: Player 1 (X) wins.
     * 2: Play 2 (O) wins.
     * 3: Cat's game or tie.
     */
    int checkForCompletion(int moves_elapsed);
};