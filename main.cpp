#include "WordLadder.h"

using namespace std;

int main(){

    string start, end;
    cin >> start >> end;
    WordLadder test = WordLadder("dictionary.txt");
    test.outputLadder(start, end, "answer.txt");

    return 0;
}
