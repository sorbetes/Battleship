#include <iostream>
#include <cstring>
#include <iomanip>
#include <ctime>

#include "Game.hpp"
#include "Board.hpp"
#include "Coordinates.hpp"
#include "EnemyPlayer.hpp"


int main(int argc, const char * argv[]) {
    
    std::string possiblecoords_an[] = {
        "A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10",  //0-9
        "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10",    //10-19
        "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10",    //20-29
        "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10",    //30-39
        "E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8", "E9", "E10",    //40-49
        "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10",    //50-59
        "G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8", "G9", "G10",    //60-69
        "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10",    //70-79
        "I1", "I2", "I3", "I4", "I5", "I6", "I7", "I8", "I9", "I10",    //80-89
        "J1", "J2", "J3", "J4", "J5", "J6", "J7", "J8", "J9", "J10"};   //90-99
    
    std::map<int, std::string> coords_table;
    for (int i = 0; i < 99; ++i) {
        coords_table.insert({i,possiblecoords_an[i]});
    }
    //-------
    
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
        
        for (int i = 0; i < 1; i++) {
            Ship *ship = new Ship();                    //gotta delete
            std::cout << "Ship Size: " << ShipSizes[i] << std::endl;
            std::cout << "Enter starting coordinates (A1, A2, A3...): ";
            std::cin.ignore();
            std::getline(std::cin, coords);
            Coordinates shipcoords(coords);
            ship->x = shipcoords.x;
            ship->y = shipcoords.y;
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
        int hitstatus = 0;
        
        do {
            std::cout << "Where would you like to hit (A1, A2, A3... ): ";
            std::getline(std::cin, coords);
            Coordinates shipcoords(coords);
            hitstatus = RunningGame.Hit(1, shipcoords.x, shipcoords.y);
            while (hitstatus > 1) { //returns 2 or 3 if invalid hit so keep looping until hitstatus returns a 0 or 1
                std::cout << "Where would you like to hit (A1, A2, A3... ): ";
                std::getline(std::cin, coords);
                Coordinates shipcoords(coords);
                hitstatus = RunningGame.Hit(1, shipcoords.x, shipcoords.y);
            }
            
            if (RunningGame.BoardGames[1].AllShipsSank() == true) { //can place this inisde hit function this if statement inside Hit()
                endgame = true;
                RunningGame.DrawBoards();
                std::cout << "Win - Player One. \n";
                break;
            }
            
            //Player Two
            Coordinates hitcoords = PlayerTwo.GetNextHitCoordinates();
            hitstatus = RunningGame.Hit(0, hitcoords.x, hitcoords.y);
            PlayerTwo.UpdateGameStatus(hitstatus, coords_table);
            
            if (RunningGame.BoardGames[0].AllShipsSank() == true) {
                endgame = true;
                std::cout << "Win - Player Two. \n";
            }
            
            RunningGame.DrawBoards();
            
        } while (!endgame);

    }
    
    //else if (option == 2)
        //Player 1 SetUp
        //Player 2 Setup
        //StartGame
    
    else std::cout << "Not a valid option.\n";
    
    return 0;
}
