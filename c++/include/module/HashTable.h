#ifndef HASHTABLE_H
#define HASHTABLE_H 

#include <string>

class MyHashTable {
    /*
    
    MyHashTable dict = new MyHashTable();
    dict.put("key", "value");
    dict.get("key"); // "value"
    
    
    */
    public:
        MyHashTable(int size);
        ~MyHashTable();

        MyHashTable put(const std::string &key, const std::string &value);
        MyHashTable get(const std::string &key);

    private:
        int size;
        int hashString(const std::string &value);
        bool checkEmpty(int bin);
        std::string *hashArray;
};


#endif //HASHTABLE_H