#include "Cell.h"

TMXCell::TMXCell()
{
	this->gid = -1;
	this->x = 0;
	this->y = 0;
}

TMXCell::TMXCell(int gid)
{
	this->gid = gid;
}

int TMXCell::getGid()
{
	return gid;
}

void TMXCell::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}
