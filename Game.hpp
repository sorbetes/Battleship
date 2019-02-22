#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "Board.hpp"

class Game {
    
    //each game will have two boards
    //the game will have the draw funtion
    
public:
    
    Game();
    Board BoardGames[2];
    
    
    void DrawBoards();
    void AddBoards (Board*, Board*);
    int Hit (int boardnum, int x, int y);
    
};


#endif
