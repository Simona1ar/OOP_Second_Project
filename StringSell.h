#pragma once
#include "Cell.h"
#include "String.h"

class StringCell :public Cell {
private:
	String content;
public:
	StringCell(String content);
	virtual void read(istream& in) override;
	virtual void write(ostream& out) const override;

	Cell* clone() const override;
};
