#pragma once
#include "Cell.h"

class IntCell : public Cell {
private:
	int content;
public:
	IntCell(int content);
	virtual void read(istream& in) override;
	virtual void write(ostream& out) const override;

	virtual Cell* clone() const override;
};