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

    for (int i = 0; i < 99; ++i) {
        possiblecoords_n[i]=i;
    }
}

void EnemyPlayer::UpdateGameStatus(int hit, std::map<int, std::string> &coords_table) {


    //REMOVE THE PREVIOUS COORDS (CURRENT NEXTCOORDS) FORM POSSIBLECOORDS_N!!!!

    std::cout << "Status: " << this->status << std::endl;
    
    //have to check if valid coordinates
    //Coordinates 0, 0, ""
    
    // hit = 0, it's a hit on ship
    // hit = 1, it's a hit on water
    // hit = 2, invalid outside board
    // hit = 3, invalid already been hit
    
    //Use that^ main loop instead having internal check? at least random would be... fixed??
    //or if possiblecoords_n.contains(nextcoords) -> use this, else pick another one., have everything in a while loop, do this at the end of loop

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
    
    //check if nextcoords is valid (check if outside of board or if it's already been hit)
    //pick again if not valid
    
    //pick random from possiblecoords_n, remove from the nextcoords from possiblecoords_n
    
}

Coordinates EnemyPlayer::GetNextHitCoordinates() {
    return this->nextcoords;
}
