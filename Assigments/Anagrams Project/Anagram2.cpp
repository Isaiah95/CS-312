#include <iostream>
#include <fstream>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

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

void processInputList(const vector<string> &inputList, const unordered_map<string, set<string>> &dictionary) {
    for (const string &inputword : inputList) {
        cout << "Word: " << inputword << endl;
        vector<string> anagrams = findAnagrams(inputword, dictionary);
        for (const string &anagram : anagrams) {
            cout << anagram << endl;
        }
        cout << endl;
    }
}

int main() {
    unordered_map<string, set<string>> dictionary = loadDictionary("words.txt");

    vector<string> inputlist1 = {"nut", "excuse", "selection", "detail", "glamorous", "fat", "reason", "price", "afford", "rare"};
    vector<string> inputlist2 = {"graceful", "drop", "trousers", "tank", "can", "purple", "obedient", "tug", "courageous", "change", 
    "barbarous", "brash", "mug", "dust", "creature", "pine", "print", "superficial", "equal", "illegal"};
    vector<string> inputlist3 = {"joyous", "peaceful", "icky", "flood", "dispensable", "sprout", "serve", "tow", "kitty",
     "play", "peep", "greedy", "provide", "overconfident", "aware", "materialistic", "servant", "alike", "building", 
     "subtract", "wealth", "wood", "wreck", "squeak", "tender", "abusive", "camera", "telling", "addition", "oven"};

    processInputList(inputlist1, dictionary);
    processInputList(inputlist2, dictionary);
    processInputList(inputlist3, dictionary);

    return 0;
}