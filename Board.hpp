#ifndef Board_hpp
#define Board_hpp

#include <vector>
#include <stdio.h>
#include "Ship.h"


class Board {
    
public:
    
    int BoardArray [10][10];
    Ship ShipList[5]; //hashtable? name and size, size-- every hit
    //static constexpr int ShipSizes[5] = {5, 4, 3, 3, 2};
    
    Board();
    //~Board();
    void DrawBoard();
    bool AddShip (Ship *Ship);
    void RandomShipGenerator();
    bool AllShipsSank();
    bool ValidTile(int, int);
    
    
};

#endif 
