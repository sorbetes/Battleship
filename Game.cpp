#include <iomanip>
#include <iostream>

#include "Game.hpp"


Game::Game() {
    
};

void Game::DrawBoards() {
    
    std::cout << std::endl;
    std::cout << "PLAYER ONE" << std::setw(47) << "PLAYER TWO" << std::endl;
    std::cout << std::setw(5) << "A" << std::setw(4) << "B" << std::setw(4) << "C" << std::setw(4) << "D" << std::setw(4) << "E" << std::setw(4) << "F" << std::setw(4) << "G" << std::setw(4) << "H" << std::setw(4) << "I" << std::setw(4) << "J";
    std::cout << std::setw(10) << "A" << std::setw(4) << "B" << std::setw(4) << "C" << std::setw(4) << "D" << std::setw(4) << "E" << std::setw(4) << "F" << std::setw(4) << "G" << std::setw(4) << "H" << std::setw(4) << "I" << std::setw(4) << "J" << std::endl;
    
    for (int i = 0; i < 10; i++) {
        std::cout << std::setw(2) << i+1 << "|";
        for (int j = 0; j < 10; j++){
            if ((this->BoardGames[0].BoardArray[i][j]) < 6 ) {
                std::cout << "_S_" << "|";
            }
            else if ((this->BoardGames[0].BoardArray[i][j]) == 8) {
                std::cout << "_x_" << "|";
            }
            else if ((this->BoardGames[0].BoardArray[i][j]) == 9) {
                std::cout << "_o_" << "|";
            }
            else std::cout << std::setw(4) << "___|";
        }
        
        std::cout << std::setw(5) << i+1 << "|";
        
        for (int j = 0; j < 10; j++){
            if ((this->BoardGames[1].BoardArray[i][j]) == 8) {
                
                std::cout << "_x_" << "|";
            }
            else if ((this->BoardGames[1].BoardArray[i][j]) == 9) {
                std::cout << "_o_" << "|";
            }
            else std::cout << std::setw(4) << "___|";
        }
        std::cout << std::endl;
    }
}


void Game::AddBoards(Board *One, Board *Two) {
    this->BoardGames[0] = *One;
    this->BoardGames[1] = *Two;
}

bool Game::Hit(int boardnum, int x, int y) {
    if (((this->BoardGames[boardnum].BoardArray[x-1][y-1]) < 6 )) {
        this->BoardGames[boardnum].ShipList[this->BoardGames[boardnum].BoardArray[x-1][y-1]].hitcount++;
        this->BoardGames[boardnum].BoardArray[x-1][y-1] = 8; //hit, ship
        return true;
    }
    //need to do another expression for when tile has already been hit
    //(return 0 for hit ship, 1 for hit water, 2 for already hit or invalid coordinates)
    
    else {
        this->BoardGames[boardnum].BoardArray[x-1][y-1] = 9; //hit, water
        return false;
    }
    
}



