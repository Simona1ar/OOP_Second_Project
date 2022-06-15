#include "StringSell.h"

StringCell::StringCell(String content) {
	this->content = content;
}
void StringCell::read(istream& in) {
	in >> content;
}
void StringCell::write(ostream& out) const {
	out << content;
}
Cell* StringCell::clone() const {
	return new StringCell(*this);
}