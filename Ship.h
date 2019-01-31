#ifndef Ship_h
#define Ship_h

class Ship {
    
public:
    int x;
    int y;
    char direction; //u, d, l, r
    int size;
    int shipnumber;
    int hitcount;
    
    
    Ship();
    //~Ship();
    Ship(int, int, char, int, int);
};

#endif /* Ship_h */
