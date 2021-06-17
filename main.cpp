//ERICK LOJANO
//CISC 3142
//HW2

#include <iostream>

#include "animal.h"


int main(){

    Animal a1; //default constructor is called

    //FUNCTIONAL FORM
    Animal a2("Great White Shark", "Carnivore", 5, 0); 

    // ASSIGNMENT INIT
    Animal a3 = { "Chimpanzee", "Omnivore", 7, 4};

    //UNIFORM INIT
    Animal a4 {"Elephant", "Herbivore", 7, 4};

    //+ operator
    Animal a5 = a1 + a2;

    //operator<<<
    std::cout << a5 << std::endl;



}