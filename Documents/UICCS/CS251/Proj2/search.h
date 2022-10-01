// Luis de Santos - Search Engine / Invertex Index
// CS251 Data Structures, Fall 2022
// uin : ldesa3
// Developed on a ARM MacOSX using VSCode


#pragma once

#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <cctype>
#include <sstream>
using namespace std;


// cleanToken will take a string, and clean the front and back of the string by getting rid of junk
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

    while(ispunct(s.back())){ // Shaving the end of string
        s.pop_back();
    }

    return s;
}

// using the cleanToken function, and getline's delimter, this function will clean tokens in a long string with spaces.
set<string> gatherTokens(string text) {
    set<string> tokens;

    stringstream ss(text);
    string substr = "";

    while(getline(ss, substr, ' ')){ // Using the delimter we can parse through the string, and call clean token every time
        if(cleanToken(substr) != ""){
            tokens.insert(cleanToken(substr));
            }
    }

    return tokens; 
}

// BuildIndex first reads in the file data, and uses gatherTokens then creates an regular index, but then inverts it, returning the inverted index
int buildIndex(string filename, map<string, set<string>>& index){

    map<string, set<string>> invertedIndex;
    fstream fileInput;
    fileInput.open(filename);

    if(!fileInput.is_open()){ // Incase wrong filename is opened
        cout << "Invalid file name. Try again.\n";
        return 0;
    }

    int counter = 0; // Initializing
    string key;
    string token;
    while(getline(fileInput, key)){ // This loop creates a regular index and increments counter
        getline(fileInput, token);
        index.emplace(key, gatherTokens(token));
        counter++;
    }


    set<string> temp; // Here we will be inverting the index, we loop through the map and every value in the set at the positon of the map.
    for(auto map = index.begin(); map != index.end(); map++){
        temp.emplace(map->first);

        for(auto set = map->second.begin(); set != map->second.end(); set++){
            if(invertedIndex.count(*set) <= 0){ // We are we checking if the key exists already or not
                invertedIndex.emplace(*set, temp); // Create key and insert set
            }else{
                invertedIndex[*set].insert(map->first); // Key already exists so, just insert set
            }
        }
        temp.clear();
    }

    index = invertedIndex;
    
    return counter;
}

// Unions the set for the query
void setUnion(const map<string, set<string>>& index, set<string>& product, string key){

    for(auto it = index.at(key).begin();it != index.at(key).end(); it++ ){ // Simpling looking through and adding to set
        product.emplace(*it);
    }
    return;
}

// Gets set difference for the query
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
// Gets set intersection
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
// Using the previous set functions created, we will create a query and return it to the user
set<string> findQueryMatches(const map<string, set<string>>& index, string sentence) {
    set<string> result;
    

    stringstream ss(sentence);
    string substr; 
    while(getline(ss, substr, ' ')){
        if(isalpha(substr[0])){ // Long if-else statements to check which set operation the user wants
            setUnion(index, result, cleanToken(substr));
        }
        else if(substr[0] == '-' && result.size() != 0){
            setDifference(index, result, cleanToken(substr));
        }
        else if(substr[0] == '+' && result.size() != 0){
            setIntersection(index, result, cleanToken(substr));
        }else{ 
            result = index.at(cleanToken(substr));
        }
    }

    return result; 
}

void stopWords(map<string, set<string>> &index){
    string stop[15] = {"a", "the", "an", "another", "for", "an", "nor", "but", "or", "yet", "so", "in", "under", "towards", "before"}; // Array of stop words

    for(int i = 0; i < 15; i++){ // Looping through stop words
        if(index.find(stop[i]) != index.end()){ // Checking if the stop words exist
            index.erase(stop[i]); // Erase if stop words exists
        }
    }
}



// searchEngine brings all the previous functions together for the user
void searchEngine(string filename) { 
    string input = "-1"; // Initializing variables
    map <string, set<string>> InvertedIndex;
    set <string> query;
    int ProcessCount = buildIndex(filename, InvertedIndex);

    cout << "Stand by while building index...\n";
    cout << "Indexed " << InvertedIndex.size() << " pages containing " << ProcessCount << " unique terms\n" << endl;

    
    while(input != ""){
        cout << "Enter querey sentence (press enter to quit): ";
        getline(cin, input);
        query = findQueryMatches(InvertedIndex, input); // Building query

        if(input == ""){ // If user wants to exit
            break;
        }

        cout << "Found " << query.size() << " matching pages\n"; // Printing query
        for(auto s = query.begin(); s != query.end(); s++){
            cout << *s << endl;
        }
        cout << endl;
    }
    cout << "Thank you for searching!\n";
    return;
}


