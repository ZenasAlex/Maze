#pragma once
#include "TMXLayer.h"
#include "TMXTileset.h"

class TMXMap {
public:
	int width;
	int height;
	int tilewidth;
	int tileheight;
	vector<TMXLayer>layers;
	vector<TMXTileset>tilesets;
public:
	TMXMap();
	TMXMap(int width, int height, int tilewidth, int tileheight);
	void computeMapPosition();
	void loadTilesetImage();
	TMXTile *getTile(int gid);
	TMXLayer *getLayer(string name);


};