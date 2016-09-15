#include <iostream>
#include </home/ubuntu/workspace/board.h>
using namespace std;

int main() {
    board gameBoard;
    gameBoard.initialize();
    gameBoard.showBoard();
    gameBoard.play();
    return 0;
}