#include "TMXTile.h"

void TMXTile::setImage(ofImage img)
{
	this->img = img;
}

ofImage *TMXTile::getImage()
{
	return &img;
}


int TMXTile::getId()
{
	return id;
}

void TMXTile::setId(int id)
{
	this->id = id;
}

void TMXTile::setProperty(string name, string value)
{
	Property property;
	property.name = name;
	property.value = value;
	properties.push_back(property);
}

string TMXTile::getProperty(string name)
{
	string value = "empty";

	for (Property &p : properties) 
	{
		if (p.name == name) 
		{
			value = p.value;
			return value;
		}
	}
	return value;
}

void TMXTile::printData()
{
	Log::print("Tile id" + ofToString(id));

	for (Property &p : properties) 
	{
		Log::print("Property Name :" + p.name);
		Log::print("Property value :" + p.value);
	}
}
