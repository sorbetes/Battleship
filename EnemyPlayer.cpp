#include "EnemyPlayer.hpp"

//go around the hit until you get another success hit,
//if the ship hasn't fully sank, keep hitting in same direction

//Compare ship sizes to firsthitcoord->border(another ship already hit or board border)

//ship can also extend both ways
//hit the other side after miss on the direction you're going (depending on shipsizes left?) (compare length to ship sizes left)

EnemyPlayer::EnemyPlayer() {
    status = "";
    direction = 'u';
    nextcoords.x = rand() % 10 + 1;
    nextcoords.y = rand() % 10 + 1;
    /*
    possiblecoords = {"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10",  //0-9
                    "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10",    //10-19
                    "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10",    //20-29
                    "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10",    //30-39
                    "E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8", "E9", "E10",    //40-49
                    "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10",    //50-59
                    "G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8", "G9", "G10",    //60-69
                    "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10",    //70-79
                    "I1", "I2", "I3", "I4", "I5", "I6", "I7", "I8", "I9", "I10",    //80-89
                    "J1", "J2", "J3", "J4", "J5", "J6", "J7", "J8", "J9", "J10"};   //90-99
     */
}

void EnemyPlayer::UpdateGameStatus(int hit) {
    std::cout << "Status: " << this->status << std::endl;
    
    //have to check if valid coordinates
    //Coordinates 0, 0, ""
    
    // hit = 0, it's a hit on ship
    // hit = 1, it's a hit on water
    // hit = 2, invalid outside board
    // hit = 3, invalid already been hit
    
    //faster if enemyplayer random picks from vector of coords so that hits are valid (hasn't been already hit) and doesn't have to keep redoing random hit
    //remove successful hit coords (ship or water) from possible coords list
    //make sure nextcoords doesn't go outside board somehow
    
    if (hit == 0) {
        this->status += "h"; //append h
        if (this->status.length() == 1) {            //it's a hit, first hit
            //save first coords
            this->nextcoords.y--; //go up
        }
        
        else {                                      // it's "h(however no. of m's)h"
            //you hit in the same direction
            if (this->direction == 'u') {           //hh
                this->nextcoords.y--;
            }
            else if (this->direction == 'r') {      //hmh
                this->nextcoords.x++;
            }
            else if (this->direction == 'd') {      //hmmh
                this->nextcoords.y++;
            }
            else if (this->direction == 'l') {      //hmmmh
                this->nextcoords.x--;
            }
        }
    }

    else if ((hit == 1) && ((this->status.length() == 1 ) || (this->status.back() == 'm'))) {
        //you hit clockwise
        this->status += "m";
        if (this->direction == 'u') {
            this->direction = 'r';
            this->nextcoords.x++;
        }
        else if (this->direction == 'r') {
            this->direction = 'd';
            this->nextcoords.y++;
        }
        else if (this->direction == 'd') {
            this->direction = 'l';
            this->nextcoords.x--;
        }
    }
    
    else if ((hit == 1) && ((this->status.back() == 'm') && (this->status.length() > 1 ))) {
        //already finished hitting in one direction
        this->status = "";
        this->direction = 'u';
        this->nextcoords.x = rand() % 10 + 1;
        this->nextcoords.y = rand() % 10 + 1;
        //store starting hit so that I can check the other side, need to know ship sizes left?
    }
    
    else {
        this->status = "";
        this->direction = 'u';
        this->nextcoords.x = rand() % 10 + 1;
        this->nextcoords.y = rand() % 10 + 1;
    }
    
}

Coordinates EnemyPlayer::GetNextHitCoordinates() {
    return this->nextcoords;
}
