#include </home/ubuntu/workspace/square.h>
#include <iostream>
#include <cstdlib>
using namespace std;

class board {
    private:
    
    const static int bombCount = 20;
    int ySize, xSize;
    square** boardGrid = new square*[20]; //Initializes 2D square array as a double pointer
    
    public:
    
    void initialize(int x_Size = 10, int y_Size=10) {
    	xSize = x_Size;
    	ySize = y_Size;
		for (int i = 0; i < xSize; i++) {   	 //Creates 2D array of squares as pointers for
			    boardGrid[i] = new square[ySize];//Dynamic allocation
		}
        int i = 0;
        while (i <= bombCount) {
            int xPos = rand() % 10;
            int yPos = rand() %10;
            if (!boardGrid[xPos][yPos].isBomb()) { //If it is a bomb, no increment, loop again.
                boardGrid[xPos][yPos].setBomb(); //If it isn't a bomb, make it bomb and increment
                i++;
            }
        	//tell each square how many bombs are adjacent to it
        	//(yes, that's all that this quagmire of if statements does)
            int numAdjBombs = 0;
			for (int x = 0; x < xSize; x++) { //Assigning numbers to Squares, denoting the number of adjacent bombs
				for (int y = 0; y < ySize; y++) {
					if (x == 0 || x == xSize - 1 || y == 0 || y == ySize - 1) { //Edge and corner cases
						if (x == 0 && y == 0) { 								//corner case
							if (boardGrid[x + 1][y].isBomb()) {numAdjBombs++;} 
							if (boardGrid[x][y + 1].isBomb()) {numAdjBombs++;}
							if (boardGrid[x + 1][y + 1].isBomb()) {numAdjBombs++;}  
						} else if (x == 0 && y == ySize - 1) { 				//corner case
							if (boardGrid[x][y - 1].isBomb()) {numAdjBombs++;}
							if (boardGrid[x + 1][y].isBomb()) {numAdjBombs++;}
							if (boardGrid[x + 1][y - 1].isBomb()) {numAdjBombs++;}
						} else if (x == xSize - 1 && y == 0) {				//corner case
							if (boardGrid[x - 1][y].isBomb()) {numAdjBombs++;}
							if (boardGrid[x][y + 1].isBomb()) {numAdjBombs++;}
							if (boardGrid[x - 1][y + 1].isBomb()) {numAdjBombs++;}
						} else if (x == xSize - 1 && y == ySize - 1) { 		//corner case
							if (boardGrid[x - 1][y].isBomb()) {numAdjBombs++;}
							if (boardGrid[x][y - 1].isBomb()) {numAdjBombs++;}
							if (boardGrid[x - 1][y - 1].isBomb()) {numAdjBombs++;}
						} else if (x == 0) { 									//edge case
							if (boardGrid[x][y + 1].isBomb()) {numAdjBombs++;}
							if (boardGrid[x + 1][y + 1].isBomb()) {numAdjBombs++;}
							if (boardGrid[x + 1][y].isBomb()) {numAdjBombs++;}
							if (boardGrid[x + 1][y - 1].isBomb()) {numAdjBombs++;}
							if (boardGrid[x][y - 1].isBomb()) {numAdjBombs++;}
						} else if (x == xSize - 1) { 							//edge case
							if (boardGrid[x][y + 1].isBomb()) {numAdjBombs++;}
							if (boardGrid[x - 1][y + 1].isBomb()) {numAdjBombs++;}
							if (boardGrid[x - 1][y].isBomb()) {numAdjBombs++;}
							if (boardGrid[x - 1][y - 1].isBomb()) {numAdjBombs++;}
							if (boardGrid[x][y - 1].isBomb()) {numAdjBombs++;}
						} else if (y == 0) { 									//edge case
							if (boardGrid[x + 1][y].isBomb()) {numAdjBombs++;}
							if (boardGrid[x + 1][y + 1].isBomb()) {numAdjBombs++;}
							if (boardGrid[x][y + 1].isBomb()) {numAdjBombs++;}
							if (boardGrid[x - 1][y + 1].isBomb()) {numAdjBombs++;}
							if (boardGrid[x - 1][y].isBomb()) {numAdjBombs++;}
						} else if (y == ySize - 1) { 							//edge case
							if (boardGrid[x + 1][y].isBomb()) {numAdjBombs++;}
							if (boardGrid[x + 1][y - 1].isBomb()) {numAdjBombs++;}
							if (boardGrid[x][y - 1].isBomb()) {numAdjBombs++;}
							if (boardGrid[x - 1][y - 1].isBomb()) {numAdjBombs++;}
							if (boardGrid[x - 1][y].isBomb()) {numAdjBombs++;}
						}
					} else { 													//normal case
						if (boardGrid[x + 1][y].isBomb()) {numAdjBombs++;}
						if (boardGrid[x + 1][y - 1].isBomb()) {numAdjBombs++;}
						if (boardGrid[x][y - 1].isBomb()) {numAdjBombs++;}
						if (boardGrid[x - 1][y - 1].isBomb()) {numAdjBombs++;}
						if (boardGrid[x - 1][y].isBomb()) {numAdjBombs++;}
						if (boardGrid[x - 1][y + 1].isBomb()) {numAdjBombs++;}
						if (boardGrid[x][y + 1].isBomb()) {numAdjBombs++;}
						if (boardGrid[x + 1][y + 1].isBomb()) {numAdjBombs++;}
					}
					boardGrid[x][y].setNumAdjBombs(numAdjBombs);
					numAdjBombs = 0;
				}
			}
    	}
            
    }
    
    void showBoard() { //Displays Minesweeper Board
        cout << "  [Minesweeper Board]\n There are " << 20 << " bombs left.";
        for (int x=xSize-1;x>=0;x--) {
            cout << "\n" << x+1;
            if (x < 9) {
            	cout << " ";
            }
            cout << " ";
            for (int y=0;y<ySize;y++){
            	if (y!=0) {cout << "  ";}
                square cSquare = boardGrid[x][y];
                if (cSquare.isRevealed()) {
                    if (cSquare.isBomb()) {
                        cout << "*";
                    } else {
                        cout << cSquare.getNumAdjBombs();
                    }
                } else if (cSquare.isFlagged()) {
                    cout << "%";
                } else {
                    cout << "#";
                }
            }
        }
        cout << "\n   ";
        for (int i = 1; i < ySize+1; i++) {
        	if (i < 10) {
        		cout << i << "  ";
        	} else {
        		cout << i << " ";
        	}
        }
        cout << "\n";
    }
    
    square getBoard(int x, int y) { //Returns square at specific xy position in grid
        return boardGrid[x][y];
    }
    
    void play() { //Runs the game
    	while (true) {
    		string ans;
    		int x, y;
    		cout << "What would you like to do? (r)eveal, (f)lag or (q)uit? ";
    		cin >> ans;
    		if (ans == "r") {
    			cout << "X-Position: ";
    			cin >> y;
    			cout << "Y-Position: ";
    			cin >> x;
    			boardGrid[x-1][y-1].reveal();
    		} else if (ans == "f") {
    			cout << "X-Position: ";
    			cin >> y;
    			cout << "Y-Position: ";
    			cin >> x;
    			boardGrid[x-1][y-1].flag();
    		} else if (ans == "q") {
    			break;
    		}
    		showBoard();
    	}
    	delete boardGrid;
    	cout << "Thanks For Playing. Funny!!!!\n";
    }
};