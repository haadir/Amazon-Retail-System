#ifndef CLOTHING_H
#define CLOTHING_H
#include "product.h"

class Clothing : public Product {
public:
	Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand);

	std::set<std::string> keywords() const;

	bool isMatch(std::vector<std::string>& searchTerms) const;

	std::string displayString() const;
	// return data members in a string

	void dump(std::ostream& os) const;
	//call product dump
	//product::dump(os)

private:
	std::string size_;
	std::string brand_;
	std::set<std::string> keywords_;
};
#endif



