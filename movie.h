#ifndef MOVIE_H
#define MOVIE_H
#include "product.h"

class Movie : public Product {
public:
	Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating);

	std::set<std::string> keywords() const;

	bool isMatch(std::vector<std::string>& searchTerms) const;

	std::string displayString() const;
	// return data members in a string

	void dump(std::ostream& os) const;
	//call product dump
	//product::dump(os)

private:
	std::string genre_;
	std::string rating_;
	std::set<std::string> keywords_;
};
#endif



