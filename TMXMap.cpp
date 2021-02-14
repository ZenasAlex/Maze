#include "TMXMap.h"

TMXMap::TMXMap()
{

}

TMXMap::TMXMap(int width, int height, int tilewidth, int tileheight)
{
	this->width;
	this->height;
	this->tilewidth;
	this->tileheight;
}

void TMXMap::computeMapPosition()
{
	
	for (TMXLayer &l : layers)
	{
		l.tileWidth = tilewidth;
		l.tileHeight = tileheight;
		l.computeCellsPosition();
	}

}

void TMXMap::loadTilesetImage()
{
	for(TMXTileset &t: tilesets){
		t.loadImage();
		t.setTileImage();

	}
}

TMXTile * TMXMap::getTile(int gid)
	
{
	for (int i = tilesets.size() - 1; i > -1; --i)
	{
		if (gid >= tilesets[i].firstgid)
		{
			TMXTileset &temp = tilesets[i];
			return temp.getTile(gid - temp.firstgid);
		}
	}
	return NULL;
}

TMXLayer * TMXMap::getLayer(string name)
{
	//Recorre el arreglo de layers 
	for (TMXLayer &layer : layers) {
		// si el nombre del layer es igual al layer solocitado   regreso el apuntador a layer
		if (layer.name == name) {
			return &layer;
		}
	}
	//si termina de recorrer arreglo y no encuentra el layer regresa NULL
	return NULL;
}


