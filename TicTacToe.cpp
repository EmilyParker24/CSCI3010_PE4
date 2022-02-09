// g++ -std=c++17 -Wall -Werror TicTacToe.cpp -o TicTacToe

#include <iostream>
#include <vector>

enum class Square {Empty, X, O};

std::vector<std::vector<Square>> CreateBoard() {
    std::vector<std::vector<Square>> board = {{Square::Empty, Square::Empty, Square::Empty}, 
                                              {Square::Empty, Square::Empty, Square::Empty}, 
                                              {Square::Empty, Square::Empty, Square::Empty}};
    return board;
}


int main() {
    std::vector<std::vector<Square>> board = CreateBoard();
}