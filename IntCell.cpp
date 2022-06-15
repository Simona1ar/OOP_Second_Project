#include "IntCell.h"

IntCell::IntCell(int content) {
	this->content = content;
}

void IntCell::read(istream& in) {
	in >> content;
}
void IntCell::write(ostream& out) const {
	out << content;
}

Cell* IntCell::clone() const {
	return new IntCell(*this);
}