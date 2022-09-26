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
    int lastCounter = s.size() - 1;
    bool flag;

    for(int i = 0; i < s.size(); i++){ // Checks for empty string or valid string
        if(isalpha(s[i])) {flag = true;}
    }

    if(!flag)   {return "";}

    while(ispunct(s[0])){ // Shaving front of string
        s.erase(0, 1);
    }

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

    cout << "Entering loop.\n";
    while(getline(ss, substr, ' ')){
        cleanToken(substr);
        if(substr != ""){tokens.insert(substr);}
    }

    return tokens; 
}

// TODO: Add a function header comment here to explain the
// behavior of the function and how you implemented this behavior
int buildIndex(string filename, map<string, set<string>>& index) {

    fstream fileInput;
    fileInput.open(filename);
    set<string> temp;

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
    
    
    // TODO:  Write this function.
    
    
    return counter;
}

// TODO: Add a function header comment here to explain the
// behavior of the function and how you implemented this behavior
set<string> findQueryMatches(map<string, set<string>>& index, string sentence) {
    set<string> result;
    
    
    // TODO:  Write this function.
    
    
    return result;  // TODO:  update this.
}

// TODO: Add a function header comment here to explain the
// behavior of the function and how you implemented this behavior
void searchEngine(string filename) {

    
    // TODO:  Write this function.
    
    
}


