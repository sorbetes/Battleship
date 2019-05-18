#ifndef EnemyPlayer_hpp
#define EnemyPlayer_hpp
#include <map>
#include <stdio.h>
#include <vector>
#include "Coordinates.hpp"

class EnemyPlayer {
    
public:
    //Coordinates previouscoords;
    Coordinates nextcoords;
    char direction;
    std::string status;
    
    //int ShipSizes[5] = {5, 4, 3, 3, 2};
    //std::vector <std::string> possiblecoords;
    
    EnemyPlayer();
    void UpdateGameStatus(int, std::map<int, std::string> &);
    Coordinates GetNextHitCoordinates();
    
    int possiblecoords_n[100];
};

#endif
