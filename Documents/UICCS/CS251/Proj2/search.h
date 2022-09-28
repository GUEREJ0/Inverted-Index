// TODO: remove and replace this file header comment
// This is a .h file you will edit and turn in.

// Remove starter comments and add your own
// comments on each function and on complex code sections.

#pragma once

#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <cctype>
#include <sstream>
using namespace std;


// TODO: Add a function header comment here to explain the
// behavior of the function and how you implemented this behavior
string cleanToken(string s) {
    bool realString = false;

    for(unsigned int i = 0; i < s.size(); i++){ // Checks for empty string or valid string
        if(isalpha(s[i])){
            s[i] = tolower(s[i]);
            realString = true;
        }
    }

    if(realString == false){
        s = "";
        return s;
    }

    while(ispunct(s[0])){ // Shaving front of string
        s.erase(0, 1);
    }

    int lastCounter = s.size() - 1;

    while(ispunct(s[lastCounter])){
        s.erase(lastCounter, lastCounter - 1);
        lastCounter--;
    }

    return s;
}

// TODO: Add a function header comment here to explain the
// behavior of the function and how you implemented this behavior
set<string> gatherTokens(string text) {
    set<string> tokens;

    stringstream ss(text);
    string substr = "";

    // cout << "Entering loop.\n";
    while(getline(ss, substr, ' ')){
        if(cleanToken(substr) != ""){tokens.insert(cleanToken(substr));}
    }

    return tokens; 
}

// TODO: Add a function header comment here to explain the
// behavior of the function and how you implemented this behavior
int buildIndex(string filename, map<string, set<string>>& index){

    map<string, set<string>> invertedIndex;
    fstream fileInput;
    fileInput.open(filename);

    if(!fileInput.is_open()){
        cout << "Invalid file name. Try again.\n";
        return 0;
    }

    int counter = 0;
    string key;
    string token;
    while(getline(fileInput, key)){
        getline(fileInput, token);
        index.emplace(key, gatherTokens(token));
        counter++;
    }
    set<string> temp;
    for(auto map = index.begin(); map != index.end(); map++){
        temp.emplace(map->first);
        for(auto test = temp.begin(); test != temp.end(); test++){
            cout << *test << endl;
        }

        for(auto set = map->second.begin(); set != map->second.end(); set++){
            if(invertedIndex.count(*set) <= 0){
                invertedIndex.emplace(*set, temp);
            }else{
                invertedIndex[*set].insert(map->first);
            }
            counter++;
        }
        temp.clear();
    }
    
    index = invertedIndex;
    
    return counter;
}

// TODO: Add a function header comment here to explain the
// behavior of the function and how you implemented this behavior
set<string> findQueryMatches(const map<string, set<string>>& index, string sentence) {
    set<string> result;
    
    
    // TODO:  Write this function.
    
    
    return result;  // TODO:  update this.
}

// TODO: Add a function header comment here to explain the
// behavior of the function and how you implemented this behavior
void searchEngine(string filename) {

    
    // TODO:  Write this function.
    
    
}


