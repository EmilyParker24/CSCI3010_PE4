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

void DisplayBoard(std::vector<std::vector<Square>> board) {
    std::cout << board.at(0) << " " << board.at(1) << " " << board.at(2) << std::endl;
    std::cout << board.at(3) << " " << board.at(4) << " " << board.at(5) << std::endl;
    std::cout << board.at(6) << " " << board.at(7) << " " << board.at(8) << std::endl;
}

void PlaceMaker(std::vector<std::vector<Square>>* board, int arr[], square player) {
    board->at(arr[0]).at[arr[1]] = player;
}


int main() {
    std::vector<std::vector<Square>> board = CreateBoard();
}