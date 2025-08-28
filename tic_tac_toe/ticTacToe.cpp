#include <iostream>
#include <vector>

#include "Board.hpp"
#include "UserInterface.hpp"
#include "ComLineInterface.hpp"

using namespace std;

char alternate_player (char current_player)
{
    if (current_player == 'X')
    return 'O';
    else return 'X';
}

bool move_is_valid (Board &board, vector<int> new_move)
{
    int row = new_move.at(0);
    int col = new_move.at(1);
    
    return (board.getBoard().at(row).at(col) == ' ');
}

int main ()
{
    ComLineInterface interface = ComLineInterface();
    Board board = Board();
    
    bool game_is_active = true;
    int moves_elapsed = 0;
    char current_player = 'X';
    int result = 0;
    
    interface.displayWelcome();
    
    while (game_is_active)
    {
        interface.displayBoard(board);
        vector<int> new_move = interface.getNextMove(current_player);

        // Validate move
        if (!move_is_valid(board, new_move))
        {
            cout << "That square is already occupied.  Please pick another." << endl << endl;
            continue;
        }

        board.storeMove(new_move.at(0), new_move.at(1), current_player);

        moves_elapsed++;
        
        result = board.checkForCompletion(moves_elapsed);

        if (result)
        {
            game_is_active = false;
        }

        current_player = alternate_player(current_player);
    }

    interface.displayBoard(board);
    interface.announceResult(result);
    
    return 0;
}