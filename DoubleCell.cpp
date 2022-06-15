#include "DoubleCell.h"

DoubleCell::DoubleCell(double content) {
	this->content = content;
}
void DoubleCell::read(istream& in) {
	in >> content;
}
void DoubleCell::write(ostream& out) const {
	out << content;
}
Cell* DoubleCell::clone() const {
	return new DoubleCell(*this);
}