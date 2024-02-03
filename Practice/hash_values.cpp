#include <iostream>
#include <string>

using namespace std;

unsigned int calculateHash(const string& key, int tableSize) {
    unsigned int hashVal = 0;

    for (int i = 0; i < key.length(); ++i) {
        hashVal = (hashVal * 37 + static_cast<unsigned int>(key[i]));
    }

    return hashVal%tableSize;
}

int main() {
    string text;
    int tableSize;
    getline(cin, text);
    cin >> tableSize;
    cout << calculateHash(text, tableSize) << endl;

    return 0;
}

