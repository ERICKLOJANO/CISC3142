#include "compare.h"

//CHECKS WHICH IS BIGGER, IF THEYRE THE SAME NUMBER
//IF THE NUMBERS ARE THE SAME, RETURN BOOLEAN "SAME"
//AND THEN RETURNS THE BIGGER NUM BY COMPARING
int whichIsBigger(int a, int b, bool & same){
    if(a == b){
        same = true;
    }
    else{
        same = false;
    }
    
    return a > b? a : b;
}

//MAKEFIRSTBIGGER CHECKS IF THE SECOND NUM IS BIGGER,
//IF IT IS, SWAP NUMS.
void makeFirstBigger(int & a, int & b, bool & swap) {
    if(b > a){
        //the swap of numbers begins
        swap = true;
        int store = b;
        b = a;
        a = store;
    }
    else{
        swap = false;
    }
}

//MAKEBOTHSAME, STORES B INTO PREVIOUS VARIABLE,
//AND THEN A INTO B, RETURN PREVIOUS VAR
int makeBothSame (int a, int & b){
    int prev = b;
    b = a;
    return prev;
}