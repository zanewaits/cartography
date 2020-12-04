#include "mapPrint.h"

int main(int argc, char * argv[])
{
	initscr();
	noecho();
	curs_set(0);
	start_color();
	color_build();

	char grov;
	int item;

	std::ifstream cartographer("frupalMap.txt");
	if (cartographer.is_open())
	{
		int curX = 0;
		int curY = 0;
		int curGrov = 0;
		while (cartographer >> grov >> item)
		{
			switch (grov)
			{
				case ('m'):
					curGrov = GRASS_COLOR;
					break;
				case ('s'):
					curGrov = SWAMP_COLOR;
					break;
				case ('b'):
					curGrov = WATER_COLOR;
					break;
				case ('w'):
					curGrov = WALLS_COLOR;
					break;
				case ('r'):
					curGrov = ROYAL_COLOR;
					break;
				case ('h'):
					curGrov = HERO_COLOR;
					break;
				default:
					curGrov = 0;
					break;
			}
			attron(COLOR_PAIR(curGrov));
			mvprintw(curY, curX, "%d", item);
			//mvprintw(curY, curX, " ");
			attroff(COLOR_PAIR(curGrov));
			++curX;
			if (curX >= BORDER_SIZE)
			{
				curX = 0;
				++curY;
			}
			if (curY >= (LINES - 1))
			{
				getch();
				clear();
				curY = 0;
			}
		}
		cartographer.close();
	}
	else
	{
		printw("failed to open map.txt");
	}
	

	getch();
	endwin();
	return 0;
}


void color_build()
{
	init_pair(0, COLOR_BLACK, COLOR_BLACK);
	init_pair(1, COLOR_BLACK, COLOR_GREEN);
	init_pair(2, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(3, COLOR_CYAN, COLOR_BLUE);
	init_pair(4, COLOR_BLACK, COLOR_WHITE);
	init_pair(5, COLOR_YELLOW, COLOR_RED);
	init_pair(6, COLOR_WHITE, COLOR_CYAN);
	return;
}
