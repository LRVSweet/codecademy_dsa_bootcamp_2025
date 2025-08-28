#include <iostream>
#include <vector>

#include "Board.hpp"

using namespace std;

bool testGetBoard()
{
    cout << "Beginning test of Board.getBoard()" << endl;
    
    // --- Step 1: Arrange ---
    vector<vector<char>> expected_board = {
        {'X', 'O', 'X'},
        {'O', ' ', 'X'},
        {' ', ' ', ' '}
    };

    Board test_board(expected_board);

    // --- Step 2: Act ---
    vector<vector<char>> actual_board = test_board.getBoard();

    // --- Step 3: Assert ---
    if (actual_board == expected_board)
    {
        cout << "   PASS: actual_board matches expected_board." << endl << endl;
        return true;
    }
    else
    {
        cout << "   FAIL: actual_board does not match expected_board" << endl << endl;
        return false;
    }
}

bool testBoardConstructorBlank()
{
    cout << "Beginning a test of the default Board constructor." << endl;
    // --- Step 1: Arrange ---
    vector<vector<char>> expected_board = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '},
    };

    // --- Step 2: Act ---
    Board board_for_test;
    vector<vector<char>> actual_board = board_for_test.getBoard();

    // --- Step 3: Assert ---
    if (actual_board == expected_board)
    {
        cout << "   PASS: The actual_board matched the expected_board" << endl << endl;
        return true;
    }
    else
    {
        cout << "   FAIL: The actual_board did not match the expected_board" << endl << endl;
        return false;
    }
}

bool testBoardConstructorFilled()
{
    cout << "Beginning a test of the Board constructor with an input board supplied." << endl;
    // --- Step 1: Arrange ---
    vector<vector<char>> expected_board = {
        {'X', 'O', ' '},
        {' ', 'O', ' '},
        {'X', 'O', 'X'},
    };



    // --- Step 2: Act ---
    Board board_for_test(expected_board);
    vector<vector<char>> actual_board = board_for_test.getBoard();

    // --- Step 3: Assert ---
    if (actual_board == expected_board)
    {
        cout << "   PASS: The actual_board matched the expected_board" << endl << endl;
        return true;
    }
    else
    {
        cout << "   FAIL: The actual_board did not match the expected_board" << endl << endl;
        return false;
    }
}

bool testMakeMove()
{
    cout << "Beginning test for Board.makeMove()" << endl;
    
    // --- Step 1: Arrange ---
    vector<vector<char>> expected_board = {
        {' ', ' ', ' '},
        {' ', 'X', ' '},
        {' ', ' ', ' '}
    };

    // --- Step 2: Act ---
    Board test_board;
    Board new_board = test_board.makeMove(1, 1, 'X');
    vector<vector<char>> actual_board = new_board.getBoard();

    // --- Step 3: Assert ---
    if (actual_board == expected_board)
    {
        cout << "   PASS: actual_board matched expected_board." << endl << endl;
        return true;
    }
    else
    {
        cout << "   FAIL: actual_board did not match expected_board." << endl << endl;
        return false;
    }
}

bool testStoreMove()
{
    cout << "Beginning test of Board.storeMove()" << endl;

    // --- Step 1: Arrange ---
    vector<vector<char>> expected_board = {
        {' ', ' ', ' '},
        {' ', 'X', ' '},
        {' ', ' ', ' '}
    };

    Board test_board;

    // --- Step 2: Act ---
    test_board.storeMove(1, 1, 'X');
    vector<vector<char>> actual_board = test_board.getBoard();

    // --- Step 3: Assert ---
    if (actual_board == expected_board)
    {
        cout << "   PASS: actual_board matches expected_board." << endl << endl;
        return true;
    }
    else
    {
        cout << "   FAIL: actual_board does not match expected_board." << endl << endl;
        return false;
    }
}

bool testCheckForCompletionHorizontal ()
{
    cout << "Beginning a test of Board.checkForCompletion() with a horizontal homogenous row." << endl;

    // --- Step 1: Arrange ---
    vector<vector<char>> input_board = {
        {' ', 'O', ' '},
        {'X', 'X', 'X'},
        {' ', ' ', 'O'},
    };

    Board test_board(input_board);

    int expected_result = 1;

    // --- Step 2: Act ---
    int actual_result = test_board.checkForCompletion(5);

    // --- Step 3: Assert ---
    if (expected_result == actual_result)
    {
        cout << "   PASS: actual_result matches expected_result." << endl << endl;
        return true;
    }
    else
    {
        cout << "   FAIL: actual_result does not match the expected_result." << endl;
        cout << "   actual_result: " << actual_result << endl;
        cout << "   expected_result: " << expected_result << endl << endl;
        return false;
    }
}

bool testCheckForCompletionVertical ()
{
    cout << "Beginning a test of Board.checkForCompletion() with a vertical homogenous row." << endl;

    // --- Step 1: Arrange ---
    vector<vector<char>> input_board = {
        {' ', 'O', ' '},
        {'X', 'O', 'X'},
        {' ', 'O', ' '},
    };

    Board test_board(input_board);

    int expected_result = 2;

    // --- Step 2: Act ---
    int actual_result = test_board.checkForCompletion(5);

    // --- Step 3: Assert ---
    if (expected_result == actual_result)
    {
        cout << "   PASS: actual_result matches expected_result." << endl << endl;
        return true;
    }
    else
    {
        cout << "   FAIL: actual_result does not match the expected_result." << endl;
        cout << "   actual_result: " << actual_result << endl;
        cout << "   expected_result: " << expected_result << endl << endl;
        return false;
    }
}

bool testCheckForCompletionMainDiagonal ()
{
    cout << "Beginning a test of Board.checkForCompletion() with a homogenous row on the descending diagonal." << endl;

    // --- Step 1: Arrange ---
    vector<vector<char>> input_board = {
        {'X', 'O', ' '},
        {' ', 'X', ' '},
        {' ', 'O', 'X'},
    };

    Board test_board(input_board);

    int expected_result = 1;

    // --- Step 2: Act ---
    int actual_result = test_board.checkForCompletion(5);

    // --- Step 3: Assert ---
    if (expected_result == actual_result)
    {
        cout << "   PASS: actual_result matches expected_result." << endl << endl;
        return true;
    }
    else
    {
        cout << "   FAIL: actual_result does not match the expected_result." << endl;
        cout << "   actual_result: " << actual_result << endl;
        cout << "   expected_result: " << expected_result << endl << endl;
        return false;
    }
}

bool testCheckForCompletionRisingDiagonal ()
{
    cout << "Beginning a test of Board.checkForCompletion() with a homogenous row on the ascending diagonal." << endl;

    // --- Step 1: Arrange ---
    vector<vector<char>> input_board = {
        {'X', ' ', 'O'},
        {' ', 'O', ' '},
        {'O', 'X', ' '},
    };

    Board test_board(input_board);

    int expected_result = 2;

    // --- Step 2: Act ---
    int actual_result = test_board.checkForCompletion(5);

    // --- Step 3: Assert ---
    if (expected_result == actual_result)
    {
        cout << "   PASS: actual_result matches expected_result." << endl << endl;
        return true;
    }
    else
    {
        cout << "   FAIL: actual_result does not match the expected_result." << endl;
        cout << "   actual_result: " << actual_result << endl;
        cout << "   expected_result: " << expected_result << endl << endl;
        return false;
    }
}

bool testCheckForCompletionIncomplete ()
{
    cout << "Beginning a test of Board.checkForCompletion() with an incomplete board." << endl;

    // --- Step 1: Arrange ---
    vector<vector<char>> input_board = {
        {'X', ' ', 'O'},
        {' ', ' ', ' '},
        {'O', 'X', ' '},
    };

    Board test_board(input_board);

    int expected_result = 0;

    // --- Step 2: Act ---
    int actual_result = test_board.checkForCompletion(5);

    // --- Step 3: Assert ---
    if (expected_result == actual_result)
    {
        cout << "   PASS: actual_result matches expected_result." << endl << endl;
        return true;
    }
    else
    {
        cout << "   FAIL: actual_result does not match the expected_result." << endl;
        cout << "   actual_result: " << actual_result << endl;
        cout << "   expected_result: " << expected_result << endl << endl;
        return false;
    }
}

bool testCheckForCompletionDraw ()
{
    cout << "Beginning a test of Board.checkForCompletion() with a drawn board." << endl;

    // --- Step 1: Arrange ---
    vector<vector<char>> input_board = {
        {'X', 'O', 'O'},
        {'O', 'X', 'X'},
        {'O', 'X', 'O'},
    };

    Board test_board(input_board);

    int expected_result = 3;

    // --- Step 2: Act ---
    int actual_result = test_board.checkForCompletion(9);

    // --- Step 3: Assert ---
    if (expected_result == actual_result)
    {
        cout << "   PASS: actual_result matches expected_result." << endl << endl;
        return true;
    }
    else
    {
        cout << "   FAIL: actual_result does not match the expected_result." << endl;
        cout << "   actual_result: " << actual_result << endl;
        cout << "   expected_result: " << expected_result << endl << endl;
        return false;
    }
}


int main ()
{
    bool overall_result = true;
    
    bool get_board = testGetBoard();
    if (!get_board)
    {
        overall_result = false;
    }
    
    bool blank_constructor = testBoardConstructorBlank();
    if (!blank_constructor)
    {
        overall_result = false;
    }

    bool filled_constructor = testBoardConstructorFilled();
    if (!filled_constructor)
    {
        overall_result = false;
    }

    bool make_move = testMakeMove();
    if (!make_move)
    {
        overall_result = false;
    }

    bool store_move = testStoreMove();
    if (!store_move)
    {
        overall_result = false;
    }

    bool check_for_comp_horiz = testCheckForCompletionHorizontal();
    if (!check_for_comp_horiz)
    {
        overall_result = false;
    }

    bool check_for_comp_vert = testCheckForCompletionVertical();
    if (!check_for_comp_vert)
    {
        overall_result = false;
    }

    bool check_for_comp_main_diag = testCheckForCompletionMainDiagonal();
    if (!check_for_comp_main_diag)
    {
        overall_result = false;
    }

    bool check_for_comp_rising_diag = testCheckForCompletionRisingDiagonal();
    if (!check_for_comp_rising_diag)
    {
        overall_result = false;
    }

    bool check_for_comp_incomplete = testCheckForCompletionIncomplete();
    if (!check_for_comp_incomplete)
    {
        overall_result = false;
    }

    bool check_for_comp_draw = testCheckForCompletionDraw();
    if (!check_for_comp_incomplete)
    {
        overall_result = false;
    }
    
    if (!overall_result)
    {
        cout << "OVERAL RESULT: FAIL" << endl;
    }
    else
    {
        cout << "OVERALL RESULT: PASS" << endl;
    }

    return 0;
}