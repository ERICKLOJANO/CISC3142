#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <set>
#include <map>

int CountVowels(const std::string & word){
  //int isVowel;
  int counter = 0;
  //char x;

  // isVowel = (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u');  

  for(int i = 0; i < word.length(); i++){
    if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u'){
      // std::cout << word[i] << "is a vowel" << std::endl;
      counter++;
    }
  }
  return counter;
}

int CountZ(const std::string & word){
  int counter = 0; 

  for(int i = 0; i < word.length(); i++){
    if(word[i] == 'z'){
      counter++;
    }
  }
  return counter;
}

bool wordExists(const std::set<std::string> & repeatedWords, std::string cursor){
  bool doesExist = false;

  for(auto i = repeatedWords.begin(); i != repeatedWords.end(); i++){
    if(*i == cursor){
      return true;
    }
  }
  return doesExist;
}

void wordInfo(std::map<std::string, std::vector<int>> & wordBank, const std::string & word){
  
  std::vector<int> wordData;

  int wordLength = word.length();

  int wordVowels = CountVowels(word);

  int wordZ = CountZ(word);

  wordData.push_back(wordLength);
  wordData.push_back(wordVowels);
  wordData.push_back(int(word.at(0)));
  wordData.push_back(wordZ);

  wordBank.insert({word, wordData});
}


int main(){
  std::string word;

  std::ifstream input("sample.txt");
  std::ofstream output("features.csv");
  std::set<std::string> repeatedWords;
  std::map<std::string, std::vector<int>> wordBank;

  if(input.is_open()){
    while(getline(input, word)){

      std::transform(word.begin(), word.end(),word.begin(), ::tolower);

      word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());

      if(!wordExists(repeatedWords, word)){
        wordInfo(wordBank, word);
        repeatedWords.insert(word);
      }
    }
  }

  output << "WORD: ";
  output << "WORD CHARS: ";
  output << "ASCII VALUE: ";
  output << "WORD VOWELS: ";
  output << "HAS Z: " <<std::endl;

  for(auto i = repeatedWords.begin(); i != repeatedWords.end(); i++){
    output << "WORD: " << *i << ", ";
    output << "WORD CHARS: "<< wordBank.at(*i).at(0) << ", ";
    output <<"ASCII VALUE: "<< wordBank.at(*i).at(2) << ", ";
    output << "WORD VOWELS: "<< wordBank.at(*i).at(1) << ", ";
    output << "HAS 'Z' : "<< wordBank.at(*i).at(3) << "\n";
  }

  input.close();
  output.close();

  return 0;
}
