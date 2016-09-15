
class square {
    public:
    void setBomb() { //If square isn't a bomb, it makes it a bomb. If it is a bomb, it makes it not a bomb
        bomb = !bomb; 
    }
    bool isBomb() { //Tells if square is a bomb
        return bomb;
    }
    void flag() { //If square isn't flagged, it flags it. If it is flagged, it unflags it
        flagged = !flagged;
    }
    bool isFlagged() { //Tells if square is a bomb
        return flagged;
    }
    void reveal() { //reveals square
        revealed = true;
    }
    bool isRevealed() { //Tells is square is revealed
        return revealed;
    }
    void setNumAdjBombs(int num) { //Sets how many bombs are adacent to square
        numAdjBombs = num;
    }
    int getNumAdjBombs() { //Tells how many bombs are adjacent to square
        return numAdjBombs;
    }
    private:
    bool bomb = false;
    bool revealed = false;
    bool flagged = false;
    int numAdjBombs = 0;
    //int position[2]; //will be useful for recursive autoreveal.
};