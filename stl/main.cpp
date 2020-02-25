
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <iterator>

int main() {
    // 1
    std::ifstream input("james.txt");
    input >> std::noskipws;
    std::vector<char> vec{std::istream_iterator<char>{input}, std::istream_iterator<char>{}};

    // 2
    std::cout << "Char count: " << vec.size() << std::endl;

    // 3
    std::cout << "Newline count: " << std::count(vec.begin(), vec.end(), '\n') << std::endl;

    // 4
    auto count = 0;
    std::string alpha = "abcdefghijklmnopqrstuvwxyz";
    std::for_each(alpha.begin(), alpha.end(), [&](char c) { count += std::count(vec.begin(), vec.end(), c); });
    std::cout << "Alphabetical characters: " << count << std::endl;

    // 5
    std::for_each(vec.begin(), vec.end(), [](char& c) { c = std::tolower(c); });

    // 6
    std::map<char, int> index;
    std::for_each(alpha.begin(), alpha.end(), [&](const char c) { index[c] = std::count(vec.begin(), vec.end(), c); });

    // 7.1
    std::cout << "\nAll alphabetical characters sorted alphabetically: " << std::endl;
    std::for_each(index.begin(), index.end(),
                  [](const auto& character) { std::cout << character.first << ": " << character.second << std::endl; });

    // 7.2
    std::map<int, char> valueSortedIndex;
    std::for_each(index.begin(), index.end(),
                  [&](const auto& entry) { valueSortedIndex.insert(std::pair<int, char>(entry.second, entry.first)); });
    std::cout << "\nAll alphabetical characters sorted by number of occurences: " << std::endl;
    std::for_each(valueSortedIndex.begin(), valueSortedIndex.end(),
                  [](const auto& character) { std::cout << character.second << ": " << character.first << std::endl; });

    // 8.
    std::cout << "Top 10 most frequent words: " << std::endl;
    std::map<std::string, int_fast32_t> words;
    bool word = false;
    std::string current = "";
    std::for_each(vec.begin(), vec.end(), [&](const char& c) {
        if (c >= 'a' && c <= 'z') {
            word = true;
            current += c;
        } else if (word) {
            if (words.count(current)) {
                words[current]++;
            } else {
                words[current] = 1;
            }
            word = false;
            current = "";
        }
    });
    if (word) {
        if (words.count(current)) {
            words[current]++;
        } else {
            words[current] = 1;
        }
        word = false;
        current = "";
    }
    std::map<int_fast32_t, std::string> occurenceWords;
    std::for_each(words.begin(), words.end(), [&](const auto& entry) {
        occurenceWords.insert(std::pair<int_fast32_t, std::string>(entry.second, entry.first));
    });
    std::map<int_fast32_t, std::string>::reverse_iterator it;
    it = occurenceWords.rbegin();
    int_fast8_t amount = 10;
    while (amount) {
        std::cout << it->second << ": " << it->first << std::endl;
        it++;
        amount--;
    }

    return 0;
}
