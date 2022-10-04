#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"
#include "movie.h"
#include "product.h"

Movie::Movie(const std::string category, const std::string name, double price, int qty, 
std::string genre, std::string rating) : 
    Product(category, name, price, qty)
{
		genre_ = genre;
		rating_ = rating;
		keywords_.insert(genre_);
		keywords_.insert(rating_);
		std::set<std::string> temp1 = parseStringToWords(name_);
		std::set<std::string>::iterator it1;
		for (it1 = temp1.begin(); it1 != temp1.end(); ++it1) {
				keywords_.insert(*it1);
		}
}

std::set<std::string> Movie::keywords() const{
		return keywords_;
}

bool Movie::isMatch(std::vector<std::string>& searchTerms) const{
		return false;
}

std::string Movie::displayString() const{
		//return member data nicely in a string
		std::string temp = "name: " + name_ + "\nprice: " + std::to_string(price_) + "\nquantity: " + std::to_string(qty_) + "\ngenre: " + 
		genre_ + "\rating: " + rating_;
		return temp;
}

void Movie::dump(std::ostream& os) const{
		Product::dump(os);
		os << genre_ << "\n" << rating_ << endl;
}