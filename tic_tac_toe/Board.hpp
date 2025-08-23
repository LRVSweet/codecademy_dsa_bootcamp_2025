#pragma once

#include <vector>

class Board
{
private:
    static std::vector<std::vector<char>> empty_board;
    std::vector<std::vector<char>> board;

public:
    Board();
    Board makeMove(int horizontal, int vertical, int player);
    void storeMove(int horizontal, int vertical, int player);
    std::vector<std::vector<char>> getBoard();
    int checkForCompletion();
};