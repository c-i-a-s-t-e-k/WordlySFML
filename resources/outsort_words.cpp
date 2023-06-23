#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int main() {
    std::ifstream inputFile("/home/ciastek/Dokumenty/studia/C++/projekt/resources/slowa.txt");
    std::ofstream outputFile("/home/ciastek/Dokumenty/studia/C++/projekt/resources/slowa_5liter.txt");

    if (!inputFile) {
        std::cout << "Błąd otwarcia pliku wejściowego." << std::endl;
        return 1;
    }

    if (!outputFile) {
        std::cout << "Błąd otwarcia pliku wyjściowego." << std::endl;
        return 1;
    }

    std::string word;
    std::regex pattern("[a-z]{5}");  // Wzorzec: pięcioliterowe słowo

    while (std::getline(inputFile, word)) {
        // Usuń znaki białe z początku i końca słowa
        word.erase(word.find_last_not_of(" \t\r\n") + 1);

        // Sprawdź, czy słowo ma dokładnie 5 liter
        if (std::regex_match(word, pattern)) {
            // Zapisz słowo do pliku wyjściowego
            outputFile << word << std::endl;
        }
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Sformatowany plik został zapisany jako slowa_5liter.txt." << std::endl;

    return 0;
}