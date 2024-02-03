// You are using GCC
#include <iostream>
#include <string>
using namespace std;

#define HASH_TABLE_SIZE 100

unsigned int customHash(string& key) {
    unsigned int hashValue=0;
    for(int i=0;i<key.length();i++)
    {
        hashValue=(hashValue*31)+static_cast<unsigned int>(key[i]);
    }
    return hashValue%HASH_TABLE_SIZE;
}

int main() {
    string key;
    while (true) {
        cin >> key;

        if (key == "exit") {
            break;
        }

        unsigned int hashValue = customHash(key);
        cout << hashValue << endl;
    }

    return 0;
}