#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

vector<string> readWordsFromFile(const string& filename) {
    vector<string> words;
    ifstream file(filename);
    string word;
    while (file >> word) {
        words.push_back(word);
    }
    return words;
}

vector<string> findAnagrams(const string& inputword, const vector<string>& words) {
    vector<string> anagrams;
    string sortedword = inputword;
    sort(sortedword.begin(), sortedword.end());
    for (const string& word : words) {
        string sortedword2 = word;
        sort(sortedword2.begin(), sortedword2.end());
        if (sortedword == sortedword2) {
            anagrams.push_back(word);
        }
    }
    return anagrams;
}

int main() {
    vector<string> words = readWordsFromFile("words.txt");
    string inputword;
    while (true) {
        cout << "Enter a word (or type 'exit' to quit): ";
        cin >> inputword;
        if (inputword == "exit") {
            break;
        }
        cout << "You entered: " << inputword << endl;
        vector<string> anagrams = findAnagrams(inputword, words);
        for (const string& anagram : anagrams) {
            cout << anagram << endl;
        }
    }
    return 0;
}

//Running time Analysis: reading from file is O(n) because it reads the file once and stores the words in a vector. Then findAnaagrams
// is O(n) because it goes through the vector of words and sorts the words. The main function or user input is O(n) because it goes through the vector
// of words and prints the anagrams. Therefore, the running time is O(n).