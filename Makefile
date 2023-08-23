CXX = clang++ -Wall -Wextra  -std=c++17
#CXX = clang++ -Wall -Wextra -Werror -std=c++17

SRC = ./src/*.cpp
HEADERS = -I ./header


SFML_INC = -I /opt/homebrew/Cellar/sfml/2.6.0/include
SFML_LIB = -L /opt/homebrew/Cellar/sfml/2.6.0/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

run:
	@echo "building and compiling the game..."
	$(CXX) $(SRC) $(HEADERS) $(SFML_INC) $(SFML_LIB) -o bin/game
	@echo "running the game..."
	./bin/game

compile:
	$(CXX) $(SRC) $(HEADERS) $(SFML_INC) $(SFML_LIB) -o bin/game

clean:
	@echo "removing exe.."
	rm bin/game
