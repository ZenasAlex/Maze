#include "TMXLayer.h"
#include <iostream>

using namespace std;

TMXLayer::TMXLayer()
{
	this->name = " ";
	this->width = 0;
	this->height = 0;
	this->tileWidth = 0;
	this->tileHeight = 0;
	this->x = 0;
	this->y = 0;
}

TMXLayer::TMXLayer(string name, int width, int height)
{
	this->name = name;
	this->width = width;
	this->height = height;
}

string TMXLayer::getName()
{
	return name;
}

int TMXLayer::getWidth()
{
	return width;
}

int TMXLayer::getHeight()
{
	return height;
}

TMXCell * TMXLayer::getCell(int index)
{
	if (index >= 0 && index < cells.size()) {
		return &cells[index];
	}
	return NULL;
}


TMXCell * TMXLayer::getCell(int x, int y)
{
	//i representa la columna
	int i= floor(x / tileWidth);
	//j representa el renglon
	int j = floor(y / tileHeight);

	cout << "i, j: " << i << "," << j << endl;

	int index = j * width + i;
	cout << "index" << index << endl;
	return getCell(index);

	// Calculo los indices del i y j del tile que se requiere
	//i =(int) x/ancho de mapa;
	//j =(int) y /alto de mapa ;
	//calculo el indice del arreglo unidimensional
	//indice =i*ancho de mapa+j
	// regresa la celda correspondiente del indice solicitado

}

void TMXLayer::computeCellsPosition()
{
	int cellIndex = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int posx = x + j * tileWidth;
			int posy = y + i * tileHeight;
			cells[cellIndex].setPosition(posx, posy);
			cellIndex++;
		}
	}
}
