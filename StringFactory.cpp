
#include "StringFactory.h"

std::string StringFactory::generateRandomWord() {
    // Wylosuj indeks słowa
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, word_count - 1);
    int randomIndex = distribution(generator);

    return words[randomIndex];
}

StringFactory::StringFactory(const std::string& path_to_source_file) :path_to_source_words(path_to_source_file){
    std::ifstream inputFile(path_to_source_file);

    if (!inputFile) {
        throw std::runtime_error("Błąd otwarcia pliku");
    }

    // Zlicz liczbę słów w pliku
    int wordCount = 0;
    std::string line;
    while (std::getline(inputFile, line)) {
        wordCount++;
        words.push_back(std::move(line));
    }

    if (wordCount == 0) {
        throw std::runtime_error("brak słów w pliku");
    }

    this->word_count = wordCount;
}
