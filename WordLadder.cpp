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





void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile){

  //creating and opening answer file
  ofstream answerFile;
  answerFile.open(outputFile);
  if (!answerFile.is_open()){
      cout << "Error Opening " << outputFile << endl;
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
        

  // Actual "Word-Ladder" Begins After This //
  list<string> name(4);
  list<string> first;
  first.push_back(start);

  list<list<string>> queue;
  queue.push_back(first);

  while (!queue.empty()){
    string tempword = queue.front().back(); // starting word
    list<string> wordstodelete;
    for (string wordindex : dict){ 
      int numberofchanges = 0;
      int counter = 0;
      for (char charindex : wordindex){
        if (charindex != tempword[counter]){
          numberofchanges++;
        }
        counter++;
      }
      if (numberofchanges == 1){
        list<string>* temp = new list<string>;
        *temp = queue.front();
        temp->push_back(wordindex);
        queue.push_back(*temp);
        dict.remove(wordindex); //This might remove the word at wordindex
      }

    }




  }
  








}