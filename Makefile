mapTest: printMap.cpp
	g++ -Wall -Werror -o map printMap.cpp -lncurses

clean:
	rm ./map
