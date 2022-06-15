#pragma once
#include "Cell.h"

class DoubleCell :public Cell {
private:
	double content;
public:
	DoubleCell(double content);
	virtual void read(istream& in) override;
	virtual void write(ostream& out) const override;
	Cell* clone() const override;
};