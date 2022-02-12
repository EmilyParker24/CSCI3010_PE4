// g++ -std=c++17 -Wall -Werror TicTacToe.cpp -o TicTacToe

#include <iostream>
#include <vector>
#include <string>

enum class Square {Empty, X, O};

std::vector<std::vector<Square>> CreateBoard() {
    std::vector<std::vector<Square>> board = {{Square::Empty, Square::Empty, Square::Empty}, 
                                              {Square::Empty, Square::Empty, Square::Empty}, 
                                              {Square::Empty, Square::Empty, Square::Empty}};
    return board;
}

void DisplayBoard(const std::vector<std::vector<Square>> board) {
    for (int i=0; i<3; i++) {
        if (i != 0) {std::cout << "-----------" <<std::endl;}
        for (int j=0; j<3; j++) {
            if (j != 0) {std::cout << "|";}
            switch(board[i][j]) {
                case Square::Empty : std::cout << "   ";  break;
                case Square::X : std::cout << " X "; break;
                case Square::O : std::cout << " O ";  break;
            }
        }
        std::cout << std::endl;
    }
}

void GetPlayerChoice(Square player, int arr[]) {
    std::string name;
    switch(player) {
        case Square::Empty : name = "?";  break;
        case Square::X : name = "X"; break;
        case Square::O : name = "O";  break;
    }
    std::cout << name << " select row 0, 1, or 2 top to bottom: ";
    std::string c;
    std::cin >> c;
    arr[0] = stoi(c);
    std::cout << name << " select column 0, 1, or 2 left to right: ";
    std::cin >> c;
    arr[1] = stoi(c);
}

void PlaceMaker(std::vector<std::vector<Square>>* board, int arr[], square player) {
    board->at(arr[0]).at[arr[1]] = player;
}

int main() {
    std::vector<std::vector<Square>> board = CreateBoard();
    DisplayBoard(board);
}
