#include "inverted_index.hh"
#include <sstream>
#include <algorithm>

void InvertedIndex::addDocument(int docId, const std::string& content) {
    std::istringstream iss(content);
    std::string word;
    while (iss >> word) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        index[word].insert(docId);
    }
}

std::vector<int> InvertedIndex::search(const std::string& query) {
    std::istringstream iss(query);
    std::string word;
    std::set<int> result;
    bool first = true;

    while (iss >> word) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (first) {
            result = index[word];
            first = false;
        } else {
            result = intersect(result, index[word]);
        }
    }

    return std::vector<int>(result.begin(), result.end());
}

std::set<int> InvertedIndex::intersect(const std::set<int>& set1, const std::set<int>& set2) {
    std::set<int> result;
    std::set_intersection(set1.begin(), set1.end(),
                          set2.begin(), set2.end(),
                          std::inserter(result, result.begin()));
    return result;
}