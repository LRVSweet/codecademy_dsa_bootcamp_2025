#include <vector>
#include <iostream>

#include "ComLineInterface.hpp"
#include "Board.hpp"

using namespace std;

ComLineInterface::ComLineInterface()
{
    // The ComLineInterface class only executes methods and does not need to store data.
}

/**
 * Displays the current board to the user.
 */
void ComLineInterface::displayBoard(Board &board)
{
    vector<vector<char>> board_vector = board.getBoard();

    // Visual divider
    cout << "___________________________________" << endl << endl << endl << endl;

    // Row 0
    cout << "    1   2   3" << endl;
    cout << "  =============" << endl;
    cout << "1 | " << board_vector.at(0).at(0) << " | " << board_vector.at(0).at(1) << " | " << board_vector.at(0).at(2) << " |" << endl;

    // Row 1
    cout << "  =============" << endl;
    cout << "2 | " << board_vector.at(1).at(0) << " | " << board_vector.at(1).at(1) << " | " << board_vector.at(1).at(2) << " |" << endl;

    // Row 2
    cout << "  =============" << endl;
    cout << "3 | " << board_vector.at(2).at(0) << " | " << board_vector.at(2).at(1) << " | " << board_vector.at(2).at(2) << " |" << endl;
    cout << "  =============" << endl;
}

/**
 * Get's a user's move and returns a vector containing the coordinates that they played.
 */
vector<int> ComLineInterface::getNextMove(char user)
{
    cout << endl << endl << "User " << user << ", it's your turn.  Please enter the coordinates of the square that you would like to play." << endl;
    int horizontal, vertical;
    cin >> horizontal >> vertical;

    vector<int> nextMove = {vertical - 1, horizontal - 1};
    return nextMove;
}

/**
 * Display welcome message and gameplay instructions.
 */
void ComLineInterface::displayWelcome()
{
    cout << endl << endl << endl << "============================================" << endl << endl << endl;
    cout << "Welcome to Logan's Command Line Tic Tac Toe game!" << endl;
    cout << "To play, you will enter the coordinates that you want to play on with the horizontal coordinate first." << endl;
    cout << "There should be a space between the coordinates like this: 2 3" << endl << endl;
    cout << "LET THE GAME COMMENCE!!!" << endl << endl;
}

/**
 * Announces the result of the game.
 */
void ComLineInterface::announceResult(int result)
{
    cout << endl << endl << endl << endl;

    switch (result)
    {
        case 1:
            cout << "!!! PLAYER X IS THE WINNER !!!" << endl << endl;
            cout << "Good game all.  Play again soon!" << endl;
            break;
        
        case 2:
            cout << "!!! PLAYER O IS THE WINNER !!!" << endl << endl;
            cout << "Good game all.  Play again soon!" << endl;
            break;
        
        case 3:
            cout << "¯\\_(ツ)_/¯ IT'S A TIE  ¯\\_(ツ)_/¯" << endl << endl;
            cout << "Good game all.  Play again soon!" << endl;
            break;
    }
}