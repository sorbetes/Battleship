#ifndef Coordinates_hpp
#define Coordinates_hpp

#include <cstring>
#include <iostream>
#include <stdio.h>

class Coordinates {
    
public:
    std::string alphanumeric;
    int x;
    int y;
    
    Coordinates();
    Coordinates(std::string);
    Coordinates(int, int);
};

#endif /* Coordinates_hpp */
