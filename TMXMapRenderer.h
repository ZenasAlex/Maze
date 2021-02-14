#pragma once

#include "TMXMap.h"
#include "TMXLoader.h"
#include "ofGraphics.h"



class TMXMapRenderer {
public:
	TMXLoader loader;
	TMXMap *map;
	string path;

	TMXMapRenderer();
	void loadMap(string path);
	void draw();

};