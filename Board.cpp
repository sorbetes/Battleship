#include <iostream>
#include <iomanip>
#include <vector>
#include "Board.hpp"
#include "Coordinates.hpp"



//1-5 for ship player, 8 hit ship, 9 for hit water

Board::Board() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++){
            BoardArray[i][j] = 7;
        }
    }
};

void Board::DrawBoard() {
    
    std::cout << std::endl;
    std::cout << std::setw(5) << "A" << std::setw(4) << "B" << std::setw(4) << "C" << std::setw(4) << "D" << std::setw(4) << "E" << std::setw(4) << "F" << std::setw(4) << "G" << std::setw(4) << "H" << std::setw(4) << "I" << std::setw(4) << "J" << std::endl;
    
    
    for (int i = 1; i <= 10; i++) {
        std::cout << std::setw(2) << i << "|";
        for (int j = 1; j <= 10; j++){
            if ((this->BoardArray[i-1][j-1]) < 6 ) {
                std::cout << "_" << (this->BoardArray[i-1][j-1]) << "_" << "|";
            }
            else if ((this->BoardArray[i-1][j-1]) == 8) {
                std::cout << "_x_" << "|";
            }
            else if ((this->BoardArray[i-1][j-1]) == 9) {
                std::cout << "_o_" << "|";
            }
            else std::cout << std::setw(4) << "___|";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool Board::AddShip (Ship *ship) {
    
    int x = ship->x;
    int y = ship->y;
    
    //check first if valid
    for (int i = 0; i < ship->size; i++) {
        if (this->ValidTile(x-1, y-1)) {
            switch(ship->direction) {
                case('u'):
                    x--;
                    break;
                case('d'):
                    x++;
                    break;
                case('l'):
                    y--;
                    break;
                case('r'):
                    y++;
                    break;
                default:
                    return false;
            }
        }
        else return false;
    }
    
    x = ship->x;
    y = ship->y;
    
    //change the board
    for (int i = 0; i < ship->size; i++) {
        switch(ship->direction) {
            case('u'):
                this->BoardArray[x-1][y-1] = ship->size;
                x--;
                break;
            case('d'):
                this->BoardArray[x-1][y-1] = ship->size;
                x++;
                break;
            case('l'):
                this->BoardArray[x-1][y-1] = ship->size;
                y--;
                break;
            case('r'):
                this->BoardArray[x-1][y-1] = ship->size;
                y++;
                break;
        }
    }

    this->ShipList[(ship->shipnumber - 1)] = *ship;
    return true;
}

void Board::RandomShipGenerator() {
    /*
     //temporary
    this->BoardArray[0][0] = 6;
    this->BoardArray[0][1] = 6;
    this->BoardArray[0][2] = 6;
    this->BoardArray[0][3] = 6;
    this->BoardArray[0][4] = 6;
    */
    
    std::cout << "Generating enemy board... \n";
    
    int ShipSizes[5] = {5, 4, 3, 3, 2};
    char directions[] = "udlr";
    for (int i = 0; i < 5; i++) {
        Ship *ship = new Ship();
        srand(time(NULL));
        ship->x = rand() % 10 + 1;
        ship->y = rand() % 10 + 1;
        ship->direction = directions [rand() % 4];
        ship->shipnumber = i+1;
        ship->size = ShipSizes[i];
        
        if (!this->AddShip(ship)) {
            i--;
        }
    }
                                      
}

bool Board::AllShipsSank() {
    
    //Board can have a counter for ships sank. instead of this fuction? /counting every player turn
    //can just have a counter for 5+4+3+3+2 hits, all ship sank if hitcount = 17 for the board
    //is the player supposed to know the type of ship he/she just sank??
    //should i output every turn the hitcount of each ship for player information?
    int shipsSank = 0;
    for (int i = 0; i < 5; i++) {
        if (this->ShipList[i].hitcount == this->ShipList[i].size) {
            shipsSank++;
        }
    }
    
    if (shipsSank == 5) return true;
    else return false;
}

bool Board::ValidTile(int x, int y) {
    if ((x > 9) || (y > 9) || (x < 0) || (y < 0)) return false; //out of bounds
    if (this->BoardArray[x][y] != 7) return false;              //not an empty tile
    return true;
}
