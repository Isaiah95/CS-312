#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <unordered_map>
#include <set>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<string> readWordsFromFile(const string& filename) {
    vector<string> words;
    ifstream file(filename);
    string word;
    while (file >> word) {
        words.push_back(word);
    }
    return words;
}

string alphabetize(const string &word) {
    string sorted_word = word;
    sort(sorted_word.begin(), sorted_word.end());
    return sorted_word;
}

unordered_map<string, set<string>> loadDictionary(const string &filename) {
    unordered_map<string, set<string>> dictionary;
    ifstream file(filename);
    string word;

    if (!file) {
        cerr << "Unable to open dictionary file." << endl;
        exit(1);
    }

    while (file >> word) {
        string key = alphabetize(word);
        dictionary[key].insert(word);
    }

    file.close();
    return dictionary;
}

vector<string> findAnagrams(const string &inputword, const unordered_map<string, set<string>> &dictionary) {
    string key = alphabetize(inputword);
    vector<string> anagrams;
    if (dictionary.find(key) != dictionary.end()) {
        anagrams.assign(dictionary.at(key).begin(), dictionary.at(key).end());
    }
    return anagrams;
}

vector<string> findAnagramsPlusOne(const string &inputword, const unordered_map<string, set<string>> &dictionary) {
    vector<string> result;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for (char letter : alphabet) {
        string w = inputword + letter;
        string signature = alphabetize(w);
        if (dictionary.find(signature) != dictionary.end()) {
            result.insert(result.end(), dictionary.at(signature).begin(), dictionary.at(signature).end());
        }
    }
    return result;
}

void processInput(const string &inputword, const unordered_map<string, set<string>> &dictionary) {
    cout << "Word: " << inputword << endl;
    vector<string> anagrams = findAnagrams(inputword, dictionary);
    for (const string &anagram : anagrams) {
        cout << anagram << endl;
    }
    cout << endl;

    vector<string> anagramsPlusOne = findAnagramsPlusOne(inputword, dictionary);
    cout << "Anagrams plus one for " << inputword << ":" << endl;
    for (const string &anagram : anagramsPlusOne) {
        cout << anagram << endl;
    }
    cout << endl;
}

int main() {
    unordered_map<string, set<string>> dictionary = loadDictionary("words.txt");

    string inputword;
    cout << "Enter a word: ";
    cin >> inputword;

    processInput(inputword, dictionary);

    return 0;
}