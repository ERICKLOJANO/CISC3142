#include <iostream>
#include "animal.h"

//GETTERS
string Animal::getAnimalName() const{
    return animalName;
}

string Animal::getAnimalFoodGroup(){
    return animalFoodGroup;
}

int Animal::getAge(){
    return animalAge;
}

int Animal::getNumLimbs(){
    return numLimbs;
}

//SETTERS
void Animal::setAnimalName(string animalName){
    this->animalName = animalName;
}

void Animal::setAnimalFoodGroup(string animalFoodGroup){
    this->animalFoodGroup = animalFoodGroup;
}

void Animal::setAge(int animalAge){
    this->animalAge = animalAge;
}

void Animal::setNumLimbs(int numLimbs){
    this->numLimbs = numLimbs;
}

Animal::Animal(string foodGroup){
    this->animalName = " ";
    this->animalFoodGroup = foodGroup;
    this->animalAge = 0;
    this->numLimbs = 0;
}

Animal::Animal(string name, string foodGroup, int age, int limbs){
    this->animalName = name;
    this->animalFoodGroup = foodGroup;
    this->animalAge = age;
    this->numLimbs = limbs;
}

Animal Animal::operator+(Animal animal){
    Animal sumAnimals;
        sumAnimals.animalAge = this->animalAge + animal.animalAge;
        sumAnimals.numLimbs = this->numLimbs + animal.numLimbs;
    
    return sumAnimals;
}

std::ostream& operator <<(std::ostream& os, Animal& animal){
    os << "Animal: " << animal.getAnimalName() << "|| Animal Group: " << animal.getAnimalFoodGroup()
    << "|| Animal Age: " << animal.getAge() << "|| Animal # of Limbs: " << animal.getNumLimbs() <<std::endl;

    return os;
}
