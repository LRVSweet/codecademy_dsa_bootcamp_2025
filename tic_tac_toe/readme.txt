Codecademy DSA in C++ Bootcamp - August 2025
Logan Sweet

I made this a bit more complicated than necessary to practice OOP in C++.
My idea was to make the code modular to allow me to add a GUI as a personal development project at some point.
I would also like to look into adding a computer opponent that plays based on an analysis of which move is the most likely to win or avoid a loss.

In order to run the program, download these files to a common folder:
- Board.cpp
- Board.hpp
- ComLineInterface.cpp
- ComLineInterface.hpp
- UserInterface.cpp
- UserInterface.hpp
- ticTacToe.cpp

Once ready, use this command to compile in your terminal: g++ ticTacToe.cpp Board.cpp UserInterface.cpp ComLineInterface.cpp -o ticTacToeTheGame.out

Finally, enter this command to play a game: ./ticTacToeTheGame.out