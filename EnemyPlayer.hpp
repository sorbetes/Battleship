#ifndef EnemyPlayer_hpp
#define EnemyPlayer_hpp

#include <stdio.h>
#include "Coordinates.hpp"

class EnemyPlayer {
    
public:
    Coordinates previouscoords;
    Coordinates nextcoords;
    char direction;
    std::string status;
    
    int ShipSizes[5] = {5, 4, 3, 3, 2};
    
    EnemyPlayer();
    void UpdateGameStatus(bool);
    Coordinates GetNextHitCoordinates();
};

#endif
