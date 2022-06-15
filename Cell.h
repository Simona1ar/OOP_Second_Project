#pragma once
#include <iostream>
using namespace std;

class Cell {
public:
	enum CellType {
		EMPTY, //0
		INT, //1
		DOUBLE, //2
		STRING //3
	};
	virtual void read(istream& in) = 0;
	virtual void write(ostream& out) const = 0;

	virtual Cell* clone() const = 0;
	virtual ~Cell() = default;
};