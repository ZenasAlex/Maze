#include "TMXMapRenderer.h"

TMXMapRenderer::TMXMapRenderer()
{
	path = " ";
}

void TMXMapRenderer::loadMap(string path)
{
	loader.loadMap(path);
	map = &loader.map;
}

void TMXMapRenderer::draw()
{

	for (TMXLayer &l : map->layers)
	{
		int index = 0;
		for (TMXCell &c : l.cells)
		{
			int gid = c.getGid();
			TMXTile * tile = map->getTile(gid);
			if (tile != NULL) {
				tile->getImage()->draw(c.x, c.y);

				ofSetColor(255);
			
			}
			if (l.name == "Maze") {
				//ofDrawBitmapString(ofToString(c.gid), c.x + map->tilewidth / 2, c.y + map->tileheight / 2);
				index++;

			}

		}
	}
}