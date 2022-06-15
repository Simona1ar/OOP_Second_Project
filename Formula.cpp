#include "Formula.h"

Formula::Formula(String content) {
	this->content = content;
}

void Formula::read(istream& in) {
	in >> content;
}
void Formula::write(ostream& out) const {
	out << content;
}
Cell* Formula::clone() const {
	return new Formula(*this);
}

//...