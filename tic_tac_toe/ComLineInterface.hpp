#pragma once

#include <vector>

#include "UserInterface.hpp"
#include "Board.hpp"

using namespace std;

class ComLineInterface: public UserInterface
{
public:
    /**
     * Constructor
     */
    ComLineInterface();
    
    /**
     * Displays the current board to the user.
     */
    void displayBoard(Board &board);

    /**
     * Get's a user's move and returns a vector containing the coordinates that they played.
     */
    vector<int> getNextMove(char user);

    /**
     * Display welcome message and gameplay instructions.
     */
    void displayWelcome();

    /**
     * Announces the result of the game.
     */
    void announceResult(int result);
};