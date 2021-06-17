#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <algorithm>


template <class X>
void printStackRemoveElement3(X& stack){
    std::vector<int> storage;

    int i = 0;

    //removes 3rd element
    while(!stack.empty()){
      if(i == 2){
        //adds values to vector
        //std::cout<< "value added to vector: " << stack.top()<< std::endl;
        stack.pop();
      }
      else{
        storage.push_back(stack.top());
        stack.pop();
      }
      i++;
    }
    //prints values from vector
    for(int j : storage){
        std::cout<< j << ", ";
      }

      for(int k = 0; k < storage.size(); k++){
        stack.push(storage.at(k));
      }

}

template <class X, class Y, class Z>
void myReplace(X& container, Y oldValue, Z newValue){

  std::list<int>::iterator findIt = std::find(container.begin(), container.end(), oldValue);

  container.insert(findIt, newValue);
  container.erase(findIt);

  std::list<int>::iterator it = container.begin();

  for(it = container.begin(); it != container.end(); ++it){
    std::cout<< *it << ", ";
  }
  std::cout << "\n";

}

template <class X, class A>
void myRemove(X& vector, A value){
  std::vector<int> storage;

  std::vector<int>::iterator it = vector.begin();

  for(int i = 0; i < vector.size(); i++){
    if(vector[i] != value){
      storage.push_back(vector[i]);
    }
  }

  for(int i = 0; i < storage.size(); i++){
    std::cout << storage[i] << ", ";
  }
}

template<class X, class A>
int myCount(X& vector, A value){
  int counter = 0;

  std::vector<int>::iterator it;

  for(it = vector.begin(); it != vector.end(); it++){
    if(*it == value){
      counter = counter + 1;
    }
  }
  return counter;
}



int main(){
    std::vector <int> myVector;
    myVector = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout<<"this is the vector:" << std::endl;

    for(int i = 0; i < myVector.size(); i++){
      std::cout<< myVector.at(i) << ", ";
    }

    std::cout << std::endl;

    myVector.erase(myVector.begin() + (2));

    for(int i : myVector){
      std::cout<< i << ", ";
    }

    std::cout << std::endl;

    std::vector<int>::iterator vectorIt = myVector.begin();

    advance(vectorIt,2);

    myVector.insert(vectorIt, 2);
    for(int i : myVector){
      std::cout<< i << ", ";
    }


    std::cout << std::endl;
    std::cout << std::endl;



    //LIST

     std::cout<<"this is the LIST:" << std::endl;
    std::list<int> myList;
    myList = {0, 2, 4, 6, 8, 10};

    for(int i : myList){
      std::cout<< i << ", ";
    }

    std::cout << std::endl;

    std::list<int>::iterator it = myList.begin();

    advance(it, 2);

    myList.erase(it);

    // for(int i : myList){
    //   std::cout<< i << ", ";
    // }
    for (it = myList.begin(); it != myList.end(); ++it)
        std::cout << *it << ", ";
    std::cout << '\n';


  advance(it, 3);
  myList.insert(it, 4);

  for (it = myList.begin(); it != myList.end(); ++it)
        std::cout << *it << ", ";
    std::cout << '\n';

    std::cout << std::endl;
    //STACK
    std::stack<int> myStack;
    for(int i = 0; i < 10; i++){
      myStack.push(i);
    }

    std::cout<<"this is the stack:" << std::endl;


    printStackRemoveElement3<std::stack<int>>(myStack);
    std::cout<< std::endl;

    
    
    std::cout << std::endl;
    //MAP
    std::cout<<"this is the MAP:" << std::endl;

    std::map<int, std::string> myMap;
    myMap.insert(std::make_pair(1, "Orange Juice"));
    myMap.insert(std::make_pair(2, "Water"));
    myMap.insert(std::make_pair(3, "Iced Tea"));
    myMap.insert(std::make_pair(4, "Coffee"));
    myMap.insert(std::make_pair(5, "Pepsi"));


    myMap.erase(3);

    for(auto &k : myMap){
      std::cout << "("<< k.first << ")"
      << k.second << " "; 
    }

  std::map<int, std::string>::iterator mapIt;

  mapIt = myMap.begin();
  advance(mapIt, 2);

  myMap.insert(mapIt, std::pair<int,std::string>(3, "Iced Tea"));

  std::cout << std::endl;

  for(auto &k : myMap){
      std::cout << "("<< k.first << ")"
      << k.second << " "; 
    }

  std::cout << std::endl;
  std::cout << std::endl;




  std::cout<< "this is the SET"<<std::endl;
  //SET
  //init set and values
  std::set<int> mySet{0, 5, 10, 15, 20, 25, 30, 35, 40, 45};
  //delete 3rd element
  mySet.erase(10);
  //print
  for(auto it = mySet.begin(); it != mySet.end(); ++it){
    std::cout<< *it << ", ";
  }
  //inserting 3rd element back
  std::cout << "\n";
  mySet.insert(10);

  for(auto it = mySet.begin(); it != mySet.end(); ++it){
    std::cout<< *it << ", ";
  }

  std::cout<<std::endl;
  std::cout<<std::endl;
  std::cout<< "this is myReplace"<<std::endl;

  myReplace<std::list<int>, int, int>(myList, 8, 12);

  std::cout<<std::endl;
  std::cout<< "this is replace using the algo library"<<std::endl;

  std::replace(myList.begin(), myList.end(), 8, 12);
  for(it = myList.begin(); it != myList.end(); ++it){
    std::cout<< *it << ", ";
  }
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";

  std::cout<< "this is myRemove"<<std::endl;

  std::vector<int> randomVector = {0, 1, 2, 3, 4, 5, 6, 7, 4, 8, 9, 11, 12, 4, 4, 4, 4, 26};

  myRemove<std::vector<int>, int>(randomVector, 4);

  std::cout << "\n";
  std::cout << "\n";

   std::cout<< "this is remove using the algo library"<<std::endl;

  std::vector<int>::iterator pend = std::remove(randomVector.begin(), randomVector.end(), 4);

  for(std::vector<int>::iterator it = randomVector.begin(); it != pend; ++it){
    std::cout<< *it << ", " ;
  }


  std::cout<<std::endl;
  std::cout<<std::endl;
  std::cout<< "this is myCount"<<std::endl;

  std::vector<int> randomVector1 = {0, 1, 2, 3, 4, 5, 5, 5};

  int result = myCount<std::vector<int>, int>(randomVector1, 5);
  
  std::cout << "Searching: 5||counter result: " << result << std::endl;

  std::cout<<std::endl;
  std::cout<< "this is count using the algo library"<<std::endl;

  int resultAlgo = std::count(randomVector1.begin(), randomVector1.end(), 5);

  std::cout << "Searching: 5||counter result: " << resultAlgo << std::endl;

}