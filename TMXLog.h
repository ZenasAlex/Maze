#pragma once
#include <iostream>
#include <string>

using namespace std;

class Log {
public:

	static void print(string msg)
	{
		cout << msg << endl;
	}
	static inline void print(int val)
	{
		cout << val << endl;
	}

	static inline void print(float val)
	{
		cout << val << endl;
	}
};