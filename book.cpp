#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"
#include "book.h"
#include "product.h"
using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, 
std::string isbn, std::string author) : 
    Product(category, name, price, qty)
{
		isbn_ = isbn;
		author_ = author;
		keywords_.insert(isbn_);
		std::set<std::string> temp1 = parseStringToWords(name_);
		std::set<std::string> temp2 = parseStringToWords(author_);
		for (auto i : temp1) {
				keywords_.insert(i);
		}
		for (auto i : temp2) {
				keywords_.insert(i);
		}
}

std::set<std::string> Book::keywords() const{
		return keywords_;
}

bool Book::isMatch(std::vector<std::string>& searchTerms) const{
		return false;
}

std::string Book::displayString() const{
		//return member data nicely in a string
		std::string temp = "name: " + name_ + "\nprice: " + std::to_string(price_) + "\nquantity: " + std::to_string(qty_) + "\nisbn: " + 
		isbn_ + "\nauthor: " + author_;
		return temp;
}

void Book::dump(std::ostream& os) const{
		Product::dump(os);
		os << isbn_ << "\n" << author_ << endl;
}