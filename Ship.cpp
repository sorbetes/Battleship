#include <iostream>
#include <iomanip>

#include "Ship.h"
#include <stdio.h>


Ship::Ship():
    x(0), y(0), direction('x'), size(0), shipnumber(0), hitcount(0){
};

Ship::Ship(int xCoord, int yCoord, char d, int s, int sn) {
    x = xCoord;
    y = yCoord;
    direction = d;
    size = s;
    shipnumber = sn;
};

