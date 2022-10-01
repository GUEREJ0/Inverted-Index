// TODO: remove and replace this file header comment
// This is a .cpp file you will edit and turn in.

// Remove starter comments and add your own
// comments on each function and on complex code sections.

#include <iostream>
#include "search.h"
using namespace std;

int main() {

    searchEngine("cplusplus.txt");
    return 0;
    
    // Use this function to call and test the functions you write inside of
    cout << "going into cleanToken." << endl;
    cout << cleanToken("....!#@#@$#hello$#*&$^#") << endl;
    cout << cleanToken("x)") << endl;
    cout << cleanToken("x,") << endl;
    cout << cleanToken("t>") << endl;
    cout << "End of clean token testing.\n";



    map<string, set<string>> index;
    string fileName = "cplusplus.txt";
    int counter = buildIndex(fileName, index);
    
    // search.h.  If you do not call the functions here, nothing will run.
    string testStr = "vector +container -pointer"; // Change this string for different testing, the loop at the bottom
    // will print out the contents.

    // stopWords(index); // Creative component function, uncomment to test.

    set<string> test = findQueryMatches(index, testStr); // Creative component, uncomment to test, should only change 
    // size of map;
    
    cout << index.size() << endl; // Printing out Map size
    cout << counter << endl; // Printing how many lines were processed.

    return 0;

    
    for(auto map = index.begin(); map != index.end(); map++){ // Testing to print out map and set
        cout << "Key : " << map->first << endl;
        cout << " ====================== URLs ===================\n";
        for(auto set = map->second.begin(); set != map->second.end(); set++){
            cout << *set << endl;
        }
        cout << "================================================\n";
    }

    return 0;
}

