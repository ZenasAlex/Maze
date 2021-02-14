#pragma once
#include <vector>
#include "ofUtils.h"
#include "TMXLog.h"
#include "ofImage.h"

using namespace std;

class Property {
public:
	string name;
	string value;
};

class TMXTile {
private:
	int id;
	vector<Property> properties;
	ofImage img;

	int x;
	int y;
	int tilewidth;
	int tileheight;

public:
	void setImage(ofImage img);
	ofImage *getImage();

	int getId();
	void setId(int id);
	void setProperty(string name, string value);
	string getProperty(string name);
	void printData();

};

