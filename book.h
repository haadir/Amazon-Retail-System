#ifndef BOOK_H
#define BOOK_H
#include "product.h"
using namespace std;

class Book : public Product {
public:
	Book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author);

	std::set<std::string> keywords() const;

	bool isMatch(std::vector<std::string>& searchTerms) const;

	std::string displayString() const;
	// return data members in a string

	void dump(std::ostream& os) const;
	//call product dump
	//product::dump(os)

private:
	std::string isbn_;
	std::string author_;
	std::set<std::string> keywords_;
};
#endif



