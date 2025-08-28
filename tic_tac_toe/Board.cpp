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


Board::Board(vector<vector<char>> input_board)
{
    board = input_board;
}
    
void Board::storeMove(int vertical, int horizontal, char player)
{
    this->board.at(vertical).at(horizontal) = player;
}

Board Board::makeMove(int vertical, int horizontal, char player)
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
        else if (matching_char_count == 3 && first_char == 'O')
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
        else if (first_row_val == 'O' && second_row_val == 'O' && third_row_val == 'O')
        {
            return 2;
        }  
    }

    return 0;
}

int Board::checkDescDiagonalComp()
{
    char main_diag_top = this->board.at(0).at(0);
    char center = this->board.at(1).at(1);
    char main_diag_bottom = this->board.at(2).at(2);

    if (main_diag_top == ' ' || center == ' ' || main_diag_bottom == ' ')
    {
        return 0;
    }

    if (main_diag_top == center && center == main_diag_bottom)
    {
        if (main_diag_top == 'X') return 1;
        else return 2;
    }

    else return 0;
}

int Board::checkAscDiagonalComp()
{
    char center = this->board.at(1).at(1);
    char rising_diag_top = this->board.at(0).at(2);
    char rising_diag_bottom = this->board.at(2).at(0);

    if (rising_diag_top == ' ' || center == ' ' || rising_diag_bottom == ' ')
    {
        return 0;
    }

    if (rising_diag_top == center && center == rising_diag_bottom)
    {
        if (rising_diag_top == 'X') return 1;
        else return 2;
    }
    else return 0;
}

int Board::checkForCompletion(int moves_elapsed)
{
    int horizontal_check = this->checkHorizontalComp();
    if (horizontal_check != 0)
    {
        return horizontal_check;
    }
    
    int vertical_check = this->checkVerticalComp();
    if (vertical_check != 0)
    {
        return vertical_check;
    }

    int desc_diagonal_check = this->checkDescDiagonalComp();
    if (desc_diagonal_check != 0)
    {
        return desc_diagonal_check;
    }

    int asc_diagonal_check = this->checkAscDiagonalComp();
    if (asc_diagonal_check != 0)
    {
        return asc_diagonal_check;
    }

    if (moves_elapsed == 9) return 3;
    else return 0;
}