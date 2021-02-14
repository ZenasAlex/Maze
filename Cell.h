#pragma once


class TMXCell {
public:
	int gid;
	int x;
	int y;

public:
	TMXCell();
	TMXCell(int gid);
	int getGid();
	void setPosition(int x, int y);
};