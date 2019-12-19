#pragma once
#include <SFML\Graphics.hpp>

const int HEIGHT_MAP = 16;
const int WIDTH_MAP = 16; 


sf::String Map[HEIGHT_MAP] = {
	"0000000000000000",  	
	"0              0",	 
	"0              0",  
	"0              0",	 
	"0              0",	 
	"0              0",     
	"0              0",	 
	"0              0",  
	"0              0",	
	"0              0",	 
	"0              0", 
	"0              0",  
	"0              0",  
	"0              0",  
	"0              0",  
	"0000000000000000",  
};
/*void sizeMap(int n) {
	int countSize = n; int i
	switch (n)
	{case 6: if 

	}
	
			countSize--;
		
	
}*/
void trapMap(int n) {

	int randElX = 0;
	int randElY = 0;
	srand(time(0));	
	int countTrap = n;

	while (countTrap > 0) {
		randElX = 1 + rand() % (WIDTH_MAP - 1);
		randElY = 1 + rand() % (HEIGHT_MAP - 1);

		if (Map[randElY][randElX] == ' ' && Map[randElX][randElY] != 'b' && Map[randElX][randElY] != 'p') {
			Map[randElY][randElX] = 't'; 
			
			countTrap--;
		}
	}
}

void playerMap(int n) {

	int randElX = 0;
	int randElY = 0;
	srand(time(0));
	int countPlayer = n;

	while (countPlayer > 0) {
		randElX = 1 + rand() % (WIDTH_MAP - 1);
		randElY = 1 + rand() % (HEIGHT_MAP - 1);

		if (Map[randElY][randElX] == ' ' && Map[randElX][randElY] != 'b' && Map[randElX][randElY] != 't') {
			Map[randElY][randElX] = 'p';

			countPlayer--;
		}
	}
}
void bestMap() {

	int randElX = 0;
	int randElY = 0;
	srand(time(0));
	int countPlayer = 1;
	while (countPlayer > 0) {
		randElX = 1 + rand() % (WIDTH_MAP - 1);
		randElY = 1 + rand() % (HEIGHT_MAP - 1);

		if (Map[randElY][randElX] == ' ' && Map[randElX][randElY] != 't' && Map[randElX][randElY] != 'p') {
			Map[randElY][randElX] = 'b';
			countPlayer--;
		}
	}
}