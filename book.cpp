#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <map>
#include "util.h"
#include "book.h"
#include "product.h"

Book::Book(const std::string category, const std::string name, double price, int qty, 
std::string isbn, std::string author) : 
    Product(category, name, price, qty)
{
		isbn_ = isbn;
		author_ = author;
		keywords_.insert(isbn_);
		std::set<std::string> temp1 = parseStringToWords(name_);
		std::set<std::string> temp2 = parseStringToWords(author_);
		std::set<std::string>::iterator it1;
		std::set<std::string>::iterator it2;
		for (it1 = temp1.begin(); it1 != temp1.end(); ++it1) {
				keywords_.insert(*it1);
		}
		for (it2 = temp2.begin(); it2 != temp2.end(); ++it2) {
				keywords_.insert(*it2);
		}
		// for (auto i : temp1) {
		// 		keywords_.insert(i);
		// }
		// for (auto i : temp2) {
		// 		keywords_.insert(i);
		// }
}

std::set<std::string> Book::keywords() const{
		//loop over set and print
		// for (auto i : keywords_) {
		// 	cout << i << endl;
		// }
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