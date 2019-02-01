#include "EnemyPlayer.hpp"

//change random so that if it's a hit, it tries to sink the surrounding
//next hit will be the surroundings until next succesful hit, counter (up to ?, from top going clockwise)?
//has to know - if success hit, previous hit, sizes of ships still not sank, distance from hit to border (if ship fits), the direction it should go after conscutive hits

//not just success hit..
//go around the hit until you get another success hit,
//if the ship hasn't fully sank, keep hitting in same direction
//GetNextCoordinates(previods coordinates, counter?, direction? (can use counter?), );


EnemyPlayer::EnemyPlayer() {
    succesfulhit = false;
}

void EnemyPlayer::UpdateGameStatus() {
    
}

Coordinates EnemyPlayer::GetCoordinates(bool) {
    
    Coordinates coords;
    
    
    return coords;
}
