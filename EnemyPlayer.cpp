#include "EnemyPlayer.hpp"

//go around the hit until you get another success hit,
//if the ship hasn't fully sank, keep hitting in same direction

//=======
//1) Have it go clockwise then one direction
//2) Compare ship sizes to firsthitcoord->border(another ship already hit or board border)
//3)

EnemyPlayer::EnemyPlayer() {
    status = "";
    direction = 'u';
}

void EnemyPlayer::UpdateGameStatus(bool hit) {
    //ship can also extend both ways
    //hit the other side after miss on the direction you're going (depending on shipsizes left?) (compare length to ship sizes left)
    //have to check if valid coordinates
    //Coordinates 0, 0, ""
    
    //this->previouscoords = this->nextcoords;
    
    if (hit) {
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

    else if ((!hit) /*&& ???*/) {                   //AND ((this->status.length() == 1 ) OR (string last letter is 'm')
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
    
    else if ((!hit) /*&& (last string is 'h' AND string is greater than 1 )???*/) {   // already finished hitting in one direction
        this->status = "";
        this->direction = 'u';
        //check the other side?
        //should i store starting hit so that I can check the other side, need to know ship sizes left
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
