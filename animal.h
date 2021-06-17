#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;


class Animal{
    private:
    string animalName;
    string animalFoodGroup;
    int animalAge;
    int numLimbs;
    vector<int> m_v;

    public:  

    Animal() : animalName("Tiger"), animalFoodGroup("Carnivore"), animalAge(10), numLimbs(4), m_v(vector<int>()) 
    { std::cout << "Default constructor called\n"; }
    explicit Animal(int age) : animalName("Tiger"), animalFoodGroup("Carnivore"), animalAge(age), numLimbs(4), m_v(vector<int>()){
        
    }

    string getAnimalName() const;
    string getAnimalFoodGroup();
    int getAge();
    int getNumLimbs();

    void setAnimalName(string);
    void setAnimalFoodGroup(string);
    void setAge(int);
    void setNumLimbs(int);

    Animal(string);

    Animal(string, string, int, int);

    Animal operator+(Animal Animal);

    friend std::ostream& operator << (std::ostream&, Animal&);
};
#endif