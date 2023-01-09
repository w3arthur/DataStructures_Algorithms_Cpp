#include "HashtableChaining.h"

int HashtableChaining::hashFunction(int key) {
    return key % HASHTABLE_LENGTH;
}

list<Pair> HashtableChaining::getList(int key) {
    return hashtable[key];
}

bool HashtableChaining::isEmpty() const {
    for (int i{}; i < HASHTABLE_LENGTH; ++i) if(!hashtable[i].empty()) return false;
    return true;
}

void HashtableChaining::insert(int key, const string &value) {
    auto& cell = hashtable[hashFunction(key)];
    bool keyExists = false;
    //for(auto it = begin(cell);it != end(cell); it++){
    for(auto& it : cell)
        if(it.key == key) /*first in pair*/
        {
            keyExists = true;
            it.value = value; //new value
            break;
        }
    if(!keyExists) cell.emplace_back(Pair(key, value)); //?
}


void HashtableChaining::remove(int key) {
    auto& cell = hashtable[hashFunction(key)];
    bool keyExists = false;

    for(auto it = begin(cell);it != end(cell); it++)
        if(it->key == key)   /*first in pair*/
        {
            keyExists = true;
            cell.erase(it); //new iterator
            break;
        }
    if(!keyExists) {cout << "item not found to delete " << to_string(key) << endl; } //?
}

string HashtableChaining::print() const {
    string str{};
    for(int i{}; i < HASHTABLE_LENGTH; ++i){
        if(hashtable[i].empty()) continue;
        for(auto& it :hashtable[i]) str += "the key:" + to_string(it.key) + " value: " + it.value +"\n";
    }
    return str;
}
