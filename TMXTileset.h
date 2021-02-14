#pragma once
#include <string>
#include <vector>
#include "ofImage.h"
#include "TMXTile.h"


using namespace std;

class TMXTileset {

public:
	string name;
	int columns;
	int margin;
	int tilecount;
	int spacing;
	int firstgid;
	int tilewidth;
	int tileheight;
	int imgWidth;
	int imgHeight;
	ofImage img;
	string imgName;
	
	vector<TMXTile> tiles;

public:
	TMXTileset();
	TMXTileset(string name, int columns, int tilecount, int margin, int spacing, int firstgid, int tilewidth, int tileheight, string imgName, int imgWidth, int imgHeight);

	string getName();
	string getImageName();
	TMXTile *getTile(int gid);
	void loadImage();
	void setTileImage();
	void printData();
	void draw();
};