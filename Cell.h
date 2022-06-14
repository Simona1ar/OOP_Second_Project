#pragma once
#include <iostream>
using namespace std;

class Cell {
public:
	enum CellType {
		EMPTY,
		INT,
		DOUBLE,
		STRING
	};
	virtual void read(istream& in) = 0;
	virtual void write(ostream& out) const = 0;

	virtual Cell* clone() const = 0;
	virtual ~Cell() = default;
};