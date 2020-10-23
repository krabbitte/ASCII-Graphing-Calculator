#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#define BUFFERSIZEX 400
#define BUFFERSIZEY 400
#define WINDOWDEFY 185
#define WINDOWWIDTHY 30
#define WINDOWDEFX 150
#define WINDOWWIDTHX 100

typedef struct point {
	float x, y;
	int coorx, coory;
}point;

void calcpoints();
void createplane();
void plotpoints();
void printplane(char n);

int h, v;

char plane[BUFFERSIZEX][BUFFERSIZEY];

point points[BUFFERSIZEX];

int main()
{
	calcpoints();
	createplane();
	plotpoints();
	printplane(0);

	char n;

	for (;;)
	{
		n = _getch();
		system("cls");

		if (n == 'e')
		{
			break;
		}

		printplane(n);
	}
}

void calcpoints()
{
	float x, y;

	for (int j = 0; j < BUFFERSIZEX; j++)
	{
		x = (-BUFFERSIZEX / 2) + j;
		points[j].x = x;

		points[j].y = x;
	}

	for (int j = 0; j < BUFFERSIZEX; j++)
	{
		points[j].coorx = points[j].x + (BUFFERSIZEX / 2);
		points[j].coory = BUFFERSIZEY - (round(points[j].y) + (BUFFERSIZEY / 2));
	}
}

void plotpoints()
{
	for (int j = 0; j < BUFFERSIZEX; j++)
	{
		if (points[j].coory < BUFFERSIZEY && points[j].coory > 0) {
			plane[j][points[j].coory] = 'o';
		}
	}
}

void createplane()
{
	for(int j = 0; j < BUFFERSIZEX; j++)
		for (int i = 0; i < BUFFERSIZEY; i++)
		{
			plane[j][i] = ' ';
		}

	for(int j = 0; j < BUFFERSIZEX; j++)
		plane[j][BUFFERSIZEY/2] = '-';

	for (int i = 0; i < BUFFERSIZEY; i++)
		plane[BUFFERSIZEX / 2][i] = '|';

	char message[] = "WASD to Scroll, E to Exit!";

	for (int i = 0; i < sizeof(message)/sizeof(message[0]); i++)
	{
		plane[i+WINDOWDEFX + 70][213] = message[i];
	}
}

void printplane(char n)
{
	switch (n)
	{
		case 'd':
			h++;
			break;
		case 'a':
			h--;
			break;
		case 'w':
			v++;
			break;
		case 's':
			v--;
			break;
	}

	//prints a section of the plane based on the the horizontal and vertical values
	for(int i = WINDOWDEFY + v; i < WINDOWDEFY + WINDOWWIDTHY + v; i++)
	{
		for (int j = WINDOWDEFX - h; j < WINDOWDEFX + WINDOWWIDTHX - h; j++)
			printf("%c", plane[j][i]);

		printf("\n");
	}
}