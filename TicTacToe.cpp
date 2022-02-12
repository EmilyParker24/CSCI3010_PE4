/*
Names: Emily Parker and Greg Martin

A simple command line tic tac toe game assuming fair play

compiled with:
g++ -std=c++17 -Wall -Werror TicTacToe.cpp -o TicTacToe
*/

#include <iostream>
#include <vector>
#include <string>

// enum class to track what's in a square
enum class Square {Empty, X, O};

/**
    A function to create an empty 3x3 board
    @returns a 2d vector of square type
*/
std::vector<std::vector<Square>> CreateBoard() {
    std::vector<std::vector<Square>> board = {{Square::Empty, Square::Empty, Square::Empty}, 
                                              {Square::Empty, Square::Empty, Square::Empty}, 
                                              {Square::Empty, Square::Empty, Square::Empty}};
    return board;
}

/**
    Displays the board nicely based on what is in each square
    
    @param board the 3x3 vector of Board type
*/
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

/** 
    Gets the player's row and column choice and stores in return parameter
    
    @param player the square representing which player is going
    @param arr the return array for the coordinates
*/
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


/**
    places the player's marker on the board at their selected coordinates
    @param board the 3x3 vector representing the board
    @param arr the corrdinates for the location
    @param player which player is going, X or O
*/
void PlaceMarker(std::vector<std::vector<Square>>* board, int arr[], Square player) {
    board->at(arr[0]).at(arr[1]) = player;
}

/**
    The main driver, instanitates object then loops through 9 turns taking turns for each player
*/
int main() {
    Square players[2] = {Square::O, Square::X};
    int coords[2];
    std::vector<std::vector<Square>> board = CreateBoard();

    for (int i=0; i<9; i++) {
        DisplayBoard(board);
        Square player = players[i%2];
        GetPlayerChoice(player, coords);
        PlaceMarker(&board, coords, player);
    }
    DisplayBoard(board);
}
