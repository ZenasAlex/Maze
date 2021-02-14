#include "TMXTileset.h"
#include "TMXLog.h"


TMXTileset::TMXTileset()
{
	name = "name";
	columns = 0;
	tilecount = 0;
	margin = 0;
	spacing = 0;
	firstgid = 0;
	tilewidth = 0;
	tileheight = 0;
	imgName = "";
	imgWidth = 0;
	imgHeight = 0;
}


TMXTileset::TMXTileset(string name, int columns, int tilecount, int margin, int spacing, int firstgid, int tilewidth, int tileheight, string imgName, int imgWidth, int imgHeight)
{

}

string TMXTileset::getName()
{
	return string();
}

string TMXTileset::getImageName()
{
	return string();
}

TMXTile * TMXTileset::getTile(int gid)
{
	for (TMXTile &t : tiles) 
	{
		if (gid == t.getId()) 
		{
			return &t;
		}
	}
	return NULL;
}

void TMXTileset::loadImage()
{
	if (!imgName.empty()) {
		if (img.load(imgName)) {

			Log::print("se cargo imagen: " + imgName);
		}
		else {
			Log::print("no se cargo imagen: "+ imgName);
		}
	}
	
}

void TMXTileset::setTileImage()
{
	//se valida si la imagenesta cargada 
	if (img.isAllocated()) 
	{
		int tileIndex = 0;
		//se calcula el #de renglones
		int rows = tilecount / columns ;
		//se recorren todos los elementos del tileset en forma de cuadricula
		for (int i = 0; i < rows; i++) 
		{
			for (int j = 0; j < columns; j++) 
			{

				int x = j*tilewidth;
				int y = i*tileheight;
				ofImage temp ;
				temp.allocate(32, 32, OF_IMAGE_COLOR);
				//se corta la imagen para el tileset
				temp.cropFrom(img, x, y, tilewidth, tileheight);
				//se asigna la imagen al tileset
				tiles[tileIndex].setImage(temp);

				tileIndex++;
			}
		}

	}
	cout << "se dividio el tileset"<<endl;

}


void TMXTileset::printData()
{
	Log::print("Tileset info: ");
	Log::print("Nombre: " + name);
	Log::print("firstgid: " + ofToString(firstgid));
	Log::print("tilewidth: " + ofToString(tilewidth));
	Log::print("tileheight: "+ ofToString(tileheight));
	Log::print("columns: "+ ofToString(columns));
	Log::print("tilecount: " + ofToString(tilecount));
	Log::print("img name: " + imgName);
	Log::print("img width: " + imgWidth);
	Log::print("img height: " + imgHeight);
}

void TMXTileset::draw()
{
	int x = 64;
	for (TMXTile &t : tiles) 
	{
		t.getImage()->draw(x, 50);
		x += 32;
	}
}
