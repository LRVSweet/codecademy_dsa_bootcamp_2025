#include <iostream>
#include <vector>

#include "Board.hpp"

using namespace std;

vector<vector<char>> Board::empty_board = 
{
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};


Board::Board(vector<vector<char>> input_board = Board::empty_board)
{
    board = input_board;
}
    
void Board::storeMove(int horizontal, int vertical, char player)
{
    this->board.at(vertical).at(horizontal) = player;
}

Board Board::makeMove(int horizontal, int vertical, char player)
{
    Board new_board = *this;
    new_board.board.at(vertical).at(horizontal) = player;
    return new_board;

}

vector<vector<char>> Board::getBoard()
{
    return this->board;
}

int Board::checkHorizontalComp()
{

    for (vector<char> row : this->board)
    {
        char first_char = row.at(0);
        int matching_char_count = 0;
        
        for (char element : row)
        {
            if (element == ' ') break;
            else if (element != first_char) break;
            else matching_char_count++;
        }

        if (matching_char_count == 3 && first_char == 'X')
        {
            return 1;
        }
        else if (matching_char_count == 3 && first_char == 'Y')
        {
            return 2;
        }
    }

    return 0;
}

int Board::checkVerticalComp()
{
    for (int i = 0; i < 3; i++)
    {
        char first_row_val = this->board.at(0).at(i);
        char second_row_val = this->board.at(1).at(i);
        char third_row_val = this->board.at(2).at(i);

        if (first_row_val == ' ' || second_row_val == ' ' || third_row_val == ' ')
        {
            continue;
        }
        else if (first_row_val == 'X' && second_row_val == 'X' && third_row_val == 'X')
        {
            return 1;
        }
        else if (first_row_val == 'Y' && second_row_val == 'Y' && third_row_val == 'Y')
        {
            return 2;
        }  
    }

    return 0;
}

int Board::checkDiagonalComp()
{
    vector<char> main_diagonal;
    
    for (int i = 0; i < this->board.size(); i++)
    {
        main_diagonal.push_back(this->board.at(i).at(i));
    }
    
    for (char element : main_diagonal)
    {

    }
}

int Board::checkForCompletion(int moves_elapsed)
{
    int result = 0;
    int empty_slots = 0;

    // --- Step 1: Check for horizontal completions ---
    for (vector<char> row : this->board)
    {
        char first_char = row.at(0);
        int matching_char_count = 0;
        
        for (char element : row)
        {
            if (element == ' ') break;
            else if (element != first_char) break;
            else matching_char_count++;
        }

        if (matching_char_count == 3 && first_char == 'X')
        {
            result = 1;
            return result;
        }
        else if (matching_char_count == 3 && first_char == 'Y')
        {
            result = 2;
            return result;
        }
    }

    // --- Step 2
}