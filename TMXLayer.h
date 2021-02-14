#pragma once
#include <string>
#include <vector>
#include "Cell.h"

using namespace std;

class TMXLayer {
public:
	string name;
	int width;
	int height;
	int x;
	int y;
	int tileWidth;
	int tileHeight;
public:
	vector<TMXCell> cells;
	TMXLayer();
	TMXLayer(string name, int width, int height);
	string getName();
	int getWidth();
	int getHeight();

	// regresa una celda del layer dado un indice

	TMXCell *getCell(int index);
	// regresa una celda de layer dada una posicion 

	TMXCell *getCell(int x, int y);

	void computeCellsPosition();
};