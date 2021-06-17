#include <iostream>
#include <cstdlib>

#include "compare.h"

int main(int argc, char** argv){
    //INPUT VALUES
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    bool same = false;
    bool swap = false;

    int bigNum = whichIsBigger(a, b, same);
    makeFirstBigger(a, b, swap);

    if(same){
        std::cout << "x and y are the same" << std::endl;
    }
    else{
        std::cout << bigNum << " is larger" << std::endl;
    }

    if(swap){
        std::cout << "X's new value is " << a << " and y's new value is " << b << std::endl;
    }
    else{
        std::cout << "X and Y were not swapped because they were already in the right order" <<std::endl;
    }

    if(!same){
        int oldNum = makeBothSame(a, b);
        std::cout << "Now x and y both equal " << a << ". Previously, y's value was " << oldNum << "." << std::endl;
    }

    return 0;
    
}