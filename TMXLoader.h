#pragma once
#include "TMXMap.h"
#include "TMXLayer.h"
#include "TMXTileset.h"
#include "TMXTile.h"
#include "Cell.h"
#include "ofxXmlSettings.h"
#include "ofUtils.h"

class TMXLoader {
public:
	ofxXmlSettings xmlFile;
	TMXMap map;
	TMXMap loadMap(string fileName);

	bool loadMapAttributes();
	void loadTileSets();
	void loadTilesetAttributes();

	void loadLayers();
	void loadCells(TMXLayer &layer);

	//private:
	//static loadXML(string tileName)

};