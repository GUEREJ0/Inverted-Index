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

    while(ispunct(s[lastCounter])){ // Shaving the end of string
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

void setUnion(const map<string, set<string>>& index, set<string>& product, string key){

    for(auto it = index.at(key).begin();it != index.at(key).end(); it++ ){
        product.emplace(*it);
    }
    return;
}

void setDifference(const map<string, set<string>> &index, set<string> &product, string key){
    set<string> substract;
    cout << key << endl;
    for(auto it = index.at(key).begin(); it != index.at(key).end(); it++){ // Grabbing URLs that contain key
        substract.emplace(*it);
    }

    for(auto it = substract.begin(); it != substract.end(); it++){ // Erase results set that have the same 
        if(product.find(*it) != product.end()){
            product.erase(*it);
        }
    }
    return;
}

void setIntersection(const map<string, set<string>> &index, set<string> &product, string key){
    set<string> intersection;
    set<string> final;
    for(auto it = index.at(key).begin(); it != index.at(key).end(); it++){
        intersection.emplace(*it);
    }

    for(auto it = intersection.begin(); it != intersection.end(); it++){
        if(product.find(*it) != product.end()){
            final.emplace(*it);
        }
    }
    product = final;
    return;
}
// TODO: Add a function header comment here to explain the
// behavior of the function and how you implemented this behavior
set<string> findQueryMatches(const map<string, set<string>>& index, string sentence) {
    set<string> result;

    stringstream ss(sentence);
    string substr; 
    while(getline(ss, substr, ' ')){
        cout << substr << endl;
        if(isalpha(substr[0])){
            cout << "inserting.\n";
            setUnion(index, result, cleanToken(substr));
        }
        if(substr[0] == '-'){
            cout << "getting difference.\n";
            setDifference(index, result, cleanToken(substr));
        }
        if(substr[0] == '+'){
            setIntersection(index, result, cleanToken(substr));
        }
    }

    
    
    // TODO:  Write this function.
    cout << "Before printing.\n";

    for(auto set = result.begin(); set != result.end(); set++){
        cout << *set << endl;
    }
    
    
    return result;  // TODO:  update this.
}



// TODO: Add a function header comment here to explain the
// behavior of the function and how you implemented this behavior
void searchEngine(string filename) {

    
    // TODO:  Write this function.
    
    
}


