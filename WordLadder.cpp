#include "WordLadder.h"


WordLadder::WordLadder(const string& fileName) {
    
    //opens text file
    ifstream dictionaryFile;
    dictionaryFile.open(fileName);
    if (!dictionaryFile.is_open()){
        cout << "File failed to open" << endl;
        return;
    } 

    //reading words to dict list
    string temp = "";
    while (dictionaryFile >> temp){
        if (temp.size() != 5){
            cout << temp << " is not 5 letters" << endl;
            return;
        }
        dict.push_back(temp);
    }
    dictionaryFile.close();
}


bool WordLadder::isOneLetterOff(const string& start, const string& end) { // returns true if the words are only one letter apart
    int counter = 0;
    int iterator = 0;
    for (char testLetter : start){
        if (testLetter != end[iterator]){
            counter++;
        }
        iterator++;
    }
    if (counter == 1){
        return true;
    }
    return false;
}



void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile){

  //creating and opening answer file
  ofstream answerFile;
  answerFile.open(outputFile);
  if (!answerFile.is_open()){
      cout << "Error Opening " << outputFile << endl;
      return;
  }

  if (start == end){
      answerFile << start;
      return;
  }

  //checks for either word not existing in dictionary
  bool found = false;

      //checks starting word
  for (list<string>::iterator i = dict.begin(); i != dict.end(); i++){
      if (start == *i){
          found = true;
          break;
      }
  }
  if (start == *dict.end()){
      found = true;
  }
  if (found == false){
      cout << "Starting word was not found in Dictionary" << endl;
      return;
  }

  found = false; // resets the "found" bool

      //checks ending word
  for (list<string>::iterator i = dict.begin(); i != dict.end(); i++){
      if (end == *i){
          found = true;
          break;
      }
  }
  if (start == *dict.end()){
      found = true;
  }
  if (found == false){
      cout << "Ending word was not found in Dictionary" << endl;
      return;
  }
  
  if (isOneLetterOff(start, end)){
      answerFile << start << endl << end << endl;
      return;
  }
        

  // Actual "Word-Ladder Finding" Begins After This //


  list<string> name(4);
  list<string> first;
  first.push_back(start);

  list<list<string>> queue;
  queue.push_back(first);

  list<string> wordstoremove; //list of words to remove from list

  while (!queue.empty()){

    wordstoremove.clear(); // clears list of words to remove from dict
    string tempword = queue.front().back(); // starting word

    // for every word in dict, check it against the tempword
    for (string wordindex : dict){ 
      if (isOneLetterOff(wordindex, tempword)){ //if wordindex is one letter away from tempword
        if(isOneLetterOff(wordindex, end)){     //if wordindex is also one letter away from the end word (solved problem)
            for (string words : queue.front()){
            answerFile << words << endl;
            }
            answerFile << wordindex << endl << end << endl;
            return;
        }
        list<string>* temp = new list<string>;
        *temp = queue.front();
        temp->push_back(wordindex);
        queue.push_back(*temp);
        wordstoremove.push_back(wordindex); //This adds the current wordindex to the list of words to remove
      }
    }

    //removes words used from the dictionary list
    for (string tempwrod : wordstoremove){
        dict.remove(tempwrod);
    }

    //dequeue front stack of queue
    queue.pop_front();

  }
  answerFile << "No Word Ladder Found."; 
  








}