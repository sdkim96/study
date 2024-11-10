#include "HashTable.h"

#include <string>
#include <iostream>


MyHashTable::MyHashTable(int size) {
    std::cout<< "HashTable.cpp: construct hashtable with key and value" << std::endl;
    
    std::string *hashArray = new std::string[size];
    this->hashArray = hashArray;
    this->size = size;
    
    for (int i; i<size; i++) {
        this->hashArray[i] = "";
    }
}

MyHashTable::~MyHashTable() {
    std::cout<< "HashTable.cpp: destruct hashtable" << std::endl;
}

MyHashTable MyHashTable::put(const std::string &key, const std::string &value) {
    std::cout<< "HashTable.cpp: put called" << std::endl;
    int hashedString = this->hashString(key);
    
    // 만약 비어있으면
    if (hashArray[hashedString] == "") {
        hashArray[hashedString] = value;
        return *this;
    }

    //FIXME: collision 처리
    for (int i=0; i<this->size; i++) {
        if (hashArray[i] == "") hashArray[hashedString] = value;
    }

    return *this;   
}

MyHashTable MyHashTable::get(const std::string &key) {
    std::cout<< "HashTable.cpp: get called" << std::endl;
    int hashedString = this->hashString(key);
    std::string value = this->hashArray[hashedString];

    return *this;
}

int MyHashTable::hashString(const std::string &key) {
    std::cout<< "HashTable.cpp: hashString called" << std::endl;

    int hash = 0;
    hash = static_cast<int>(key[0]);
    int bin = hash % 5;
    
    return bin;
}

bool MyHashTable::checkEmpty(int bin) {
    std::cout<< "HashTable.cpp: checkEmpty called" << std::endl;
    return this->hashArray[bin] == "";
}