cmake_minimum_required(VERSION 3.0)
project(MySFMLApp)

set(CMAKE_CXX_STANDARD 14)

# Ścieżka do folderu ze źródłami SFML
set(SFML_DIR "ścieżka/do/folderu/SFML/lib/cmake/SFML")

# Znajdź i dołącz bibliotekę SFML
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

# Dodaj ścieżkę do plików nagłówkowych SFML
include_directories(${SFML_INCLUDE_DIR})

# Utwórz wykonywalny plik
add_executable(MySFMLApp main.cpp GameWindow.h GameWindow.cpp StartWindow.cpp LetterTile.cpp Window.cpp GameManager.h GameManager.cpp Game.cpp Word.h StringFactory.cpp Word.cpp)

# Podłącz bibliotekę SFML do projektu
target_link_libraries(MySFMLApp sfml-graphics)

set_target_properties(MySFMLApp PROPERTIES OUTPUT_NAME "WordlySFML")