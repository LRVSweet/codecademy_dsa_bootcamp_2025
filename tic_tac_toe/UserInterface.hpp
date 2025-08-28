#pragma once

#include <vector>

#include "Board.hpp"

using namespace std;

/**
 * Represents a generic user interface.
 */
class UserInterface 
{
protected:
    /**
     * An empty constructor.
     */
    UserInterface();

public:
    /**
     * Displays the current board to the user.
     */
    virtual void displayBoard(Board &board) = 0;

    /**
     * Get's a user's move and returns a vector containing the coordinates that they played.
     */
    virtual vector<int> getNextMove(char user) = 0;

    /**
     * Display welcome message and gameplay instructions.
     */
    virtual void displayWelcome() = 0;

    /**
     * Announces the result of the game.
     */
    virtual void announceResult(int result) = 0;
};