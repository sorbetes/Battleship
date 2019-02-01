#include <iostream>
#include <cstring>
#include <iomanip>
#include <ctime>

#include "Game.hpp"
#include "Board.hpp"
#include "Coordinates.hpp"
#include "EnemyPlayer.hpp"


int main(int argc, const char * argv[]) {
    
    int option;
    int ShipSizes[5] = {5, 4, 3, 3, 2};
    
    Game RunningGame;
    Board BoardOne, BoardTwo;
    
    std::cout << "One player or two players (1 or 2): ";
    std::cin >> option;
    
    if (option == 1) {
        //SETUP
        std::string coords;

        BoardOne.DrawBoard();
        
        std::cout<< "Spaces needed for each ship: Carrier (5), Battleship (4), Cruiser (3), Submarine (3), Destroyer (2). \n";
        std::cout<< "Where would you like to place your ships? Make sure it does not go outside the board. \n";
        //ask if they want to have the game randomly place their ships?
        
        for (int i = 0; i < 5; i++) {
            Ship *ship = new Ship();                    //gotta delete
            std::cout << "Ship Size: " << ShipSizes[i] << std::endl;
            std::cout << "Enter starting coordinates (A1, A2, A3...): ";
            std::cin.ignore();
            std::getline(std::cin, coords);
            Coordinates shipcoords(coords);
            ship->x = shipcoords.x;
            ship->y = shipcoords.y;
            //have to check if coordinates are valid
            std::cout<< "Enter the direction (u, d, l, r):  ";
            std::cin >> ship->direction;
            ship->shipnumber = i+1;
            ship->size = ShipSizes[i];
            
            if (!BoardOne.AddShip(ship)) {
                i--;
                std::cout<< "Enter valid coordinates. \n";
            }
            else BoardOne.DrawBoard();
        }
        
        std::cin.ignore();
        
        EnemyPlayer PlayerTwo;
        BoardTwo.RandomShipGenerator();
        
        //should make a copy constructor
        RunningGame.AddBoards(&BoardOne, &BoardTwo);
        
        //START GAME
        bool endgame = false;
        bool hit = false;
        
        do {
            std::cout << "Where would you like to hit (A1, A2, A3... ): ";
            std::getline(std::cin, coords);
            Coordinates shipcoords(coords);
            RunningGame.Hit(1, shipcoords.x, shipcoords.y);         //check if valid coordinates
            
            if (RunningGame.BoardGames[1].AllShipsSank() == true) { //can place this insde hit function
                endgame = true;
                std::cout << "Win Player One. \n";
                break;
            }
            
            
            Coordinates hitcoords = PlayerTwo.GetCoordinates();
            hit = RunningGame.Hit(0, hitcoords.x, hitcoords.y);
            
            PlayerTwo.UpdateGameStatus(hit);
            
            RunningGame.DrawBoards();
            if (RunningGame.BoardGames[0].AllShipsSank() == true) {
                endgame = true;
                std::cout << "Win Player Two. \n";
            }
            
        } while (!endgame);

    }
    
    //else if (option == 2)
        //Player 1 SetUp
        //Player 2 Setup
        //StartGame
    
    else std::cout << "Not a valid option.\n";
    
    return 0;
}
