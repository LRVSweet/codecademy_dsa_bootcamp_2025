#include <iostream>
#include <vector>

#include "ComLineInterface.hpp"
#include "Board.hpp"

using namespace std;


void testDisplayBoard (ComLineInterface &interface)
{
    cout << "Testing ComLineInterface.displayBoard with an empty board." << endl;
    Board empty_board = Board();
    interface.displayBoard(empty_board);

    cout << "Testing ComLineInterface.displayBoard() with a board with the top row full of X, the middle row empty, and the bottom row full of Y." << endl;
    vector<vector<char>> test_board = {
        {'X', 'X', 'X'},
        {' ', ' ', ' '},
        {'O', 'O', 'O'},
    };

    Board populated_board = Board(test_board);
    interface.displayBoard(populated_board);
}


vector<int> getNextMove(char user);
void testGetNextMove(ComLineInterface &interface)
{
    cout << "Testing ComLineInterface.getNextMove()." << endl;

    vector<int> result = interface.getNextMove('X');

    cout << "Result is the vector: {" << result.at(0) << ", " << result.at(1) << "}." << endl;
}


void testDisplayWelcome (ComLineInterface &interface)
{
    interface.displayWelcome();
}

void testAnnounceResult(ComLineInterface &interface)
{
    cout << "Testing ComLineInterface.announceResult() with the game being won by X." << endl;
    interface.announceResult(1);
    cout << endl << endl;

    cout << "Testing ComLineInterface.announceResult() with the game being won by O." << endl;
    interface.announceResult(2);
    cout << endl << endl;

    cout << "Testing ComLineInterface.announceResult() with the game being tied." << endl;
    interface.announceResult(3);
    cout << endl << endl;
}

int main()
{
    ComLineInterface test_interface = ComLineInterface();

    testDisplayBoard(test_interface);

    testDisplayWelcome(test_interface);

    testAnnounceResult(test_interface);

    testGetNextMove(test_interface);

    return 0;
}