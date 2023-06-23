#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include "appPara.h"

class StringFactory {
private:
    int word_count;
    std::string path_to_source_words;
    std::vector<std::string> words;
public:
    StringFactory(std::string const& path_to_source_file = path_to_words_base);
    std::string generateRandomWord();
};