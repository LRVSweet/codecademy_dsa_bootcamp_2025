#include <iostream>
#include <vector>
using namespace std;

class Board
{
private:
    static vector<vector<char>> empty_board =
    {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    }

    vector<vector<char>> board;

public:
    Board(vector<vector<char>> input_board = Board::empty_board)
    {
        board = input_board;
    }
    
    Board makeMove(int horizontal, int vertical, int player)
    {
        
    }
    
    
    void storeMove(int horizontal, int vertical, int player);
    vector<vector<char>> getBoard();
    int checkForCompletion();
};