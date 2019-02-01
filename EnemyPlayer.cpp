#include "EnemyPlayer.hpp"

//change random so that if it's a hit, it tries to sink the surrounding
//next hit will be the surroundings until next succesful hit, counter (up to ?, from top going clockwise)?
//has to know - if success hit, previous hit, sizes of ships still not sank, distance from hit to border (if ship fits), the direction it should go after conscutive hits

//not just success hit..
//go around the hit until you get another success hit,
//if the ship hasn't fully sank, keep hitting in same direction
//GetNextCoordinates(previods coordinates, counter?, direction? (can use counter?), );


EnemyPlayer::EnemyPlayer() {
    status = "";
}

void EnemyPlayer::UpdateGameStatus(bool hit) {
    //ship can also extend both ways
    //hit the other side after miss on the direction you're going (depending on shipsizes left?)
    //have to check if valid coordinates
    Coordinates prev, next; //0, 0, ""
    
    this->previouscoords = this->nextcoords;
    
    if (hit) {
        this->status += "h"; //append h
        if (this->status.length() == 1) {            //it's a hit, first hit
            this->nextcoords.y--;
        }
        
        else {                                      // it's "h(however no. of m's)h"
            //you hit in the same direction
            if (this->status.length() == 2) {       //hh
                this->nextcoords.y--;
            }
            else if (this->status.length() == 3) {  //hmh
                this->nextcoords.x++;
            }
            else if (this->status.length() == 4) {  //hmmh
                this->nextcoords.y++;
            }
            else if (this->status.length() == 5) {  //hmmmh
                this->nextcoords.x--;
            }
            this->status.pop_back();
        }
    }

    else if ((!hit) && (this->status.length() < 5)) { //and it's only been hmmm
        //you hit clockwise
        this->status += "m";
        if (this->status.length() == 2) {
            this->nextcoords.x++;
        }
        else if (this->status.length() == 3) {
            this->nextcoords.y++;
        }
        else if (this->status.length() == 4) {
            this->nextcoords.x--;
        }
    }
    
    else if ((!hit) && (this->status.length() > 5)) {
        this->status = "";
        //check the other side?
        //should i store starting hit?
    }
    
    else {     //&&
        this->status = "";
        this->nextcoords.x = rand() % 10 + 1;
        this->nextcoords.y = rand() % 10 + 1;
    }
    
}

Coordinates EnemyPlayer::GetNextHitCoordinates() {
    return this->nextcoords;
}
