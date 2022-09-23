// TODO: remove and replace this file header comment
// This is a .h file you will edit and turn in.

// Remove starter comments and add your own
// comments on each function and on complex code sections.

#pragma once

#include <iostream>
#include <set>
#include <map>
#include <cctype>
using namespace std;


// TODO: Add a function header comment here to explain the
// behavior of the function and how you implemented this behavior
string cleanToken(string &s) {
    string clean = "";
    bool flag = false;

    for(int i = 0; i < s.size(); i++){
        if(isalpha(s.at(i)))  {flag = true;}
    }
    if(!flag) {return "";}

    for( int i = 0; i < s.size(); i++){ // Testing for empty string and returning empty string;
        tolower(s[i]);
        if(!ispunct(s[i]))  {clean.push_back(tolower(s.at(i)));}
        // if(isalpha(s[i]) != 0) {return "";}
    }
    cout << endl;
    s = clean;
    return clean;

}

// TODO: Add a function header comment here to explain the
// behavior of the function and how you implemented this behavior
set<string> gatherTokens(string text) {
    set<string> tokens;
    
    
    // TODO:  Write this function.
    
    
    return tokens;  // TODO:  update this.
}

// TODO: Add a function header comment here to explain the
// behavior of the function and how you implemented this behavior
int buildIndex(string filename, map<string, set<string>>& index) {
    
    
    // TODO:  Write this function.
    
    
    return 0;
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


