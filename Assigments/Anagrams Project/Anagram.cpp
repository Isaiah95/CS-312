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

vector<string> findAnagrams2(const string &inputword, const unordered_map<string, set<string>> &dictionary) {
    string key = alphabetize(inputword);
    vector<string> anagrams;
    if (dictionary.find(key) != dictionary.end()) {
        anagrams.assign(dictionary.at(key).begin(), dictionary.at(key).end());
    }
    return anagrams;
}

void processInputList(const string& listLabel, const vector<string>& inputList, const vector<string>& words, const unordered_map<string, set<string>>& dictionary) {
    auto start1 = high_resolution_clock::now();
    for (const string& inputword : inputList) {
        vector<string> anagrams = findAnagrams(inputword, words);
    }
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(stop1 - start1);
    cout << "Time taken to process " << listLabel << " with solution 1: " << duration1.count() << " milliseconds" << endl;

    auto start2 = high_resolution_clock::now();
    for (const string& inputword : inputList) {
        vector<string> anagrams = findAnagrams2(inputword, dictionary);
    }
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "Time taken to process " << listLabel << " with solution 2: " << duration2.count() << " microseconds" << endl;
}

int main() {
    vector<string> words = readWordsFromFile("words.txt");
    unordered_map<string, set<string>> dictionary = loadDictionary("words.txt");

    vector<string> inputlist1 = {"graceful", "drop", "trousers", "tank", "can", "purple", "obedient", "tug", "courageous", "change",
    "sneeze", "whistle", "guitar", "pencil", "bottle", "window", "phone", "keyboard", "mouse", "monitor"};
    vector<string> inputlist2 = {"joyous", "peaceful", "icky", "flood", "dispensable", "sprout", "serve", "tow", "kitty",
     "play", "peep", "greedy", "provide", "overconfident", "aware", "materialistic", "servant", "alike", "building", 
     "subtract", "wealth", "wood", "wreck", "squeak", "tender", "abusive", "camera", "telling", "addition", "oven"};
    vector<string> inputlist3 = {"glove","painful","sad","violent","duck","whisper","aftermath","jump","impartial","visit",
    "rings","electric","neck","accidental","advertisement","stupendous","wicked","youthful","level","dog","guarded","eatable","discover",
    "ugliest","reading","pie","ignorant","bubble","yellow","line","burn","depend","stamp","brave","spooky",
    "tangible","flagrant","jolly","argue","inconclusive","resolute","numerous","thoughtless","roof","kaput","brief","sin","crooked",
    "whip","amuck","exuberant","stay","abject","ants","glue","hop","helpful","beautiful","endurable","onerous","equal",
    "dramatic","remove","ethereal","quack","hypnotic","distribution","count","incredible","guide","gold","arm","slimy","mine","thread"};

    processInputList("inputlist1", inputlist1, words, dictionary);
    processInputList("inputlist2", inputlist2, words, dictionary);
    processInputList("inputlist3", inputlist3, words, dictionary);

    return 0;
}