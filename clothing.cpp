#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"
#include "clothing.h"
#include "product.h"
using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, 
std::string size, std::string brand) : 
    Product(category, name, price, qty)
{
		size_ = size;
		brand_ = brand;
		keywords_.insert(size_);
		std::set<std::string> temp1 = parseStringToWords(name_);
		std::set<std::string> temp2 = parseStringToWords(brand_);
		for (auto i : temp1) {
				keywords_.insert(i);
		}
		for (auto i : temp2) {
				keywords_.insert(i);
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