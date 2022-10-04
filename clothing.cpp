#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"
#include "clothing.h"
#include "product.h"

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, 
std::string size, std::string brand) : 
    Product(category, name, price, qty)
{
		size_ = size;
		brand_ = brand;
		keywords_.insert(size_);
		std::set<std::string> temp1 = parseStringToWords(name_);
		std::set<std::string> temp2 = parseStringToWords(brand_);
		std::set<std::string>::iterator it1;
		std::set<std::string>::iterator it2;
		for (it1 = temp1.begin(); it1 != temp1.end(); ++it1) {
				keywords_.insert(*it1);
		}
		for (it2 = temp2.begin(); it2 != temp2.end(); ++it2) {
				keywords_.insert(*it2);
		}
}

std::set<std::string> Clothing::keywords() const{
		return keywords_;
}

bool Clothing::isMatch(std::vector<std::string>& searchTerms) const{
		return false;
}

std::string Clothing::displayString() const{
		//return member data nicely in a string
		std::string temp = "name: " + name_ + "\nprice: " + std::to_string(price_) + "\nquantity: " + std::to_string(qty_) + "\nsize: " + 
		size_ + "\nbrand: " + brand_;
		return temp;
}

void Clothing::dump(std::ostream& os) const{
		Product::dump(os);
		os << size_ << "\n" << brand_ << endl;
}