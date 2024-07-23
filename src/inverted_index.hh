#ifndef INVERTED_INDEX_HH
#define INVERTED_INDEX_HH

#include <unordered_map>
#include <vector>
#include <set>
#include <string>

class InvertedIndex {
private:
  std::unordered_map<std::string, std::set<int>> index;

  std::set<int> intersect(const std::set<int>& set1, const std::set<int>& set2);

public:
  void addDocument(int docId, const std::string& content);
  std::vector<int> search(const std::string& query);
};

#endif