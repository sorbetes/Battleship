#include "Coordinates.hpp"

Coordinates::Coordinates():x(0), y(0), alphanumeric(""){
};


Coordinates::Coordinates(std::string coords) {
    
    alphanumeric = coords;
    if (coords[0] <= 90) y = int(coords[0] - 64);
    else y = int(coords[0] - 96);
    if (coords.length() == 3) x = 10;
    else x = int(coords[1]) - 48;
};

Coordinates::Coordinates(int _x, int _y) {
    //x, y to alphanumeric coordinates
    
};
