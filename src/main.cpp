#include "inverted_index.hh"
#include "inverted_index.cc"
#include <iostream>


int main() {
    InvertedIndex idx;

    // Adding documents
    idx.addDocument(1, "The quick brown fox jumps over the lazy dog");
    idx.addDocument(2, "Quick brown foxes leap over lazy dogs in summer");
    idx.addDocument(3, "The lazy dog sleeps in the sun");
    idx.addDocument(4, "The quick rabbit jumps over the lazy fox");
    idx.addDocument(5, "The summer sun rose brightly over the horizon.");
    idx.addDocument(6, "She danced across the room");
    idx.addDocument(7, "Her laughter echoed through the empty room");
    idx.addDocument(8, "The smell of fresh coffee filled the kitchen.");
   
    // Searching
    std::vector<int> result = idx.search(" room");
    std::cout << "Documents containing 'room': ";
    for (int docId : result) {
        std::cout << docId << " ";
    }
    std::cout << std::endl;

    result = idx.search("summer");
    std::cout << "Documents containing 'summer': ";
    for (int docId : result) {
        std::cout << docId << " ";
    }
    std::cout << std::endl;

    return 0;
}