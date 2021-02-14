#include "TMXLoader.h"
#include "TMXLog.h"
#include "of3dUtils.h"

TMXMap TMXLoader::loadMap(string fileName)
{
	
	if (xmlFile.load(fileName)) {
		cout << "si se cargo :" << fileName <<endl;
		loadMapAttributes();
		loadTileSets();
		loadLayers();
		
	}

	else { cout << "no se cargo :" << fileName << endl;
	return TMXMap();
	}
	map.computeMapPosition();
	map.loadTilesetImage();

	return map;
}

void TMXLoader::loadTileSets()
{
	loadTilesetAttributes();
}

bool TMXLoader::loadMapAttributes()
{
	map.width =	xmlFile.getAttribute("map", "width", 0);
	map.height = xmlFile.getAttribute("map", "height", 0);
	map.tilewidth = xmlFile.getAttribute("map", "tilewidth", 0);
	map.tileheight = xmlFile.getAttribute("map", "tileheight", 0);


	cout << "ancho del mapa: " << map.width << endl;
	cout << "alto del mapa: " << map.height << endl;
	cout << "ancho del tile: " << map.tilewidth << endl;
	cout << "alto del tile: " << map.tileheight << endl;



	return false;
}

void TMXLoader::loadTilesetAttributes()
{
	xmlFile.pushTag("map");
	int tilesetCount = xmlFile.getNumTags("tileset");
	TMXTileset tempTileset;


	for (int i = 0; i < tilesetCount; i++) {

		tempTileset.firstgid = xmlFile.getAttribute("tileset", "firstgid", 0, i);
		tempTileset.name = xmlFile.getAttribute("tileset", "name", "none", i);
		tempTileset.tilewidth = xmlFile.getAttribute("tileset", "tilewidth", 0, i);
		tempTileset.tileheight = xmlFile.getAttribute("tileset", "tileheight", 0, i);
		tempTileset.tilecount = xmlFile.getAttribute("tileset", "tilecount", 0, i);
		tempTileset.columns = xmlFile.getAttribute("tileset", "columns", 0, i);
		tempTileset.margin = xmlFile.getAttribute("tileset", "margin", 0, i);
		tempTileset.spacing = xmlFile.getAttribute("tileset", "spacing", 0, i);
		xmlFile.pushTag("tileset");
		tempTileset.imgName = xmlFile.getAttribute("image", "source", "none");
		tempTileset.imgWidth = xmlFile.getAttribute("image", "width", 0);
		tempTileset.imgHeight = xmlFile.getAttribute("image", "height", 0);
		tempTileset.printData();

		for (int j = 0; j < tempTileset.tilecount; j++) 
		{
			TMXTile tile;
			tile.setId(j);
			tempTileset.tiles.push_back(tile);
		}
		int tileCount = xmlFile.getNumTags("tile");

		for (int k= 0; k < tileCount; k++) 
		{
			TMXTile *tempTile;
			int id = xmlFile.getAttribute("tile", "id", -1, k);

			tempTile = tempTileset.getTile(id);//


			xmlFile.pushTag("tile", k);         //se ingresa dentro del nodo tile n
			xmlFile.pushTag("properties");      //se ingresa dentro del nodo properties de ese tile
			int propertyCount = xmlFile.getNumTags("property"); // se pegunta cuantos nodos property tiene ese tile
			for (int g = 0; g < propertyCount; g++) {
				string name = xmlFile.getAttribute("property", "name", "empty", g);
				string value = xmlFile.getAttribute("property", "value", "empty", g);

				tempTile->setProperty(name, value);
				cout << name<< value << endl;
			}
			tempTile->printData();
			//se guarda un tile completo

			xmlFile.popTag(); //salimos del nodo properties
			xmlFile.popTag();//salimos del nodo tile
		}
		xmlFile.popTag();// salimos del nodo tileset
						 // Guardamos el tileset completo en el mapa
		map.tilesets.push_back(tempTileset);
	}
}

void TMXLoader::loadLayers()
{
	//leer el numero de tags con el valor de layer
	int layerCount = xmlFile.getNumTags("layer");
	//desde 0 hasta el numero de layers
	for (int i = 0; i < layerCount; i++)
	{
		//crea un layer temporal
		TMXLayer tempLayer;
		//asigna los valores de nombre, ancho y alto al layertemporal
		//lee del xml atributo de nombre de layer
		tempLayer.name = xmlFile.getAttribute("layer", "name", "none", i);
		//lee del xml atributo de ancho de layer
		tempLayer.width = xmlFile.getAttribute("layer", "width", 0, i);
		//lee del xml atributo de alto de layer
		tempLayer.height = xmlFile.getAttribute("layer", "height", 0, i);
		Log::print("Layer: " + tempLayer.name);
		Log::print(tempLayer.width);
		Log::print(tempLayer.height);


		//ingresa en la jerarquia del nodo layer i pushTag(layer, i)  
		xmlFile.pushTag("layer", i);
		loadCells(tempLayer);
		xmlFile.popTag();
		map.layers.push_back(tempLayer);
	}
}

void TMXLoader::loadCells(TMXLayer & layer)
{
	//ingresa en la jerarquia del nodo data
	xmlFile.pushTag("data");
	//leer el numero de tags con el valor de tile
	int cellCount = xmlFile.getNumTags("tile");
	//desde 0 hasta el numero de tiles
	for (int i = 0; i < cellCount; i++) 
	{
		//crea un tile temporal
		TMXCell cell;
		//lee del xml el atributo gid para el tile n
		cell.gid = xmlFile.getAttribute("tile", "gid", -1, i);
		Log::print("tile gid: ");
		Log::print(cell.gid);
		//guarda el tile temporal en el layer
		layer.cells.push_back(cell);
	}
	//salir de la jerarquia de nodo data 
	xmlFile.popTag();
}
