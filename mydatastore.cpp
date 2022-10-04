#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include "mydatastore.h"
#include "util.h"
#include <utility>
using namespace std;

MyDataStore::MyDataStore() {

}

MyDataStore::~MyDataStore() {
	std::set<Product*>::iterator it;
	for (it = products.begin(); it != products.end(); ++it) {
		delete *it;
	}
	std::map<std::string, User*>::iterator it2;
	for (it2 = users.begin(); it2 != users.end(); ++it2) {
		delete it2->second;
	}
}

void MyDataStore::addProduct(Product* p) {
	std::set<std::string>::iterator temp;
	// for (auto i : p->keywords()){
	// 	cout << i << endl;
	// }
	// cout << endl;
	set<string> myKeywords = p->keywords();
	for(temp = myKeywords.begin(); temp != myKeywords.end(); ++temp) {
		// cout << *temp << endl;
		if(dataStore.find(*temp) != dataStore.end()) {
			// cout << *temp << endl;
			dataStore[*temp].insert(p);
		}
		else {
			std::set<Product*> tempSet;
			tempSet.insert(p);
			dataStore.insert(make_pair(*temp, tempSet));
		}
		// dataStore[*temp].insert(p);
	}
	products.insert(p);
}

void MyDataStore::addUser(User* u) {
	//make pair
	std::string temp = u->getName();
	users.insert(make_pair(temp, u));
	std::vector<Product*> tempVec;
	cart.insert(make_pair(temp, tempVec));
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {
	//loop thru keywords and add terms to vector
	//for 0 setunion
	//for 1 setintersection
	std::set<Product*> tempSet = dataStore.find(terms[0])->second;
	cout << tempSet.size() << endl;
	// std::vector<std::string>::iterator temp;
	//int count = 0;
	for(unsigned int i = 1; i < terms.size(); i++) {
		if (dataStore.find(terms[i]) != dataStore.end()) {
			set<Product*> secondSet = dataStore.find(terms[i])->second;
			// if (count == 0) {
			// 	tempSet = dataStore[*temp];
			// }
			if(type == 0) {
				tempSet = setIntersection(tempSet, secondSet);
			}
			else {
				tempSet = setUnion(tempSet, secondSet);
			}
			// count++;
		}
	}
	std::vector<Product*> vec(tempSet.begin(), tempSet.end());
	// std::copy(tempSet.begin(), tempSet.end(), vec.begin());
	// cout << "VEC SIZE: " << vec.size();
	return vec;
}

void MyDataStore::dump(std::ostream& ofile) {
	std::set<Product*>::iterator temp;
	ofile << "<products>" << std::endl;
	for(temp = products.begin(); temp != products.end(); temp++) {
		(*temp)->dump(ofile);
	}
	std::map<std::string, User*>::iterator temp1;
	ofile << "<users>" << std::endl;
	for(temp1 = users.begin(); temp1 != users.end(); temp1++) {
		//(*temp1)->dump(ofile);
		temp1->second->dump(ofile);
	}
}

void MyDataStore::addCart(std::string username, Product* p) {
		if (users.find(username) == users.end()) {
			std::cout << "Invalid Request, User Doesn't Exist";
			return;
		}
		// //user doesn't have cart
		// if (cart.find(username) == cart.end()) {
		// 	std::vector<Product*> prods;
		// 	cart.insert(make_pair(username, prods));
		// 	cart[username].push_back(p);
		// }
		//user has cart
		cart[username].push_back(p);
}
		
void MyDataStore::viewCart(string username) {
	int count = 1;
	if(cart.find(username) == cart.end()) {
		cout << "Invalid Username";
	}
	vector<Product*>::iterator temp;
	for(temp = cart[username].begin(); temp != cart[username].end(); ++temp) {
		cout << count << ". " << (*temp)->getName() << endl;
		count++;
	}
}

void MyDataStore::buyCart(string username) {
	vector<Product*>::iterator temp;
	if(cart.find(username) == cart.end()) {
		cout << "Invalid Username";
		return;
	}
	vector<Product*> buyingThis = cart[username];
	vector<Product*> thingsNotToRemove;
	for(temp = buyingThis.begin(); temp != buyingThis.end(); ++temp) {
		if ((*temp)->getQty() > 0 && (users[username]->getBalance()) > (*temp)->getPrice()) {
				(*temp)->subtractQty(1);
				users[username]->deductAmount((*temp)->getPrice());
		}
		else {
			thingsNotToRemove.push_back(*temp);
		}
	}
	cart[username] = thingsNotToRemove;
}

