#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "datastore.h"
#include <map>

class MyDataStore : public DataStore { 
public:

		MyDataStore();
		~MyDataStore();

    /**
     * Adds a product to the data store
     */
    void addProduct(Product* p);

    /**
     * Adds a user to the data store
     */
    void addUser(User* u);

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    std::vector<Product*> search(std::vector<std::string>& terms, int type);

    /**
     * Reproduce the database file from the current Products and User values
     */
    void dump(std::ostream& ofile);

		void addCart(std::string username, Product* p);
		
		void viewCart(std::string username);

		void buyCart(std::string username);

	private:
	std::map<std::string, std::set<Product*>> dataStore;
	
	std::set<Product*> products;
	
	//string username and user
	std::map<std::string, User*> users;

	//username and vector of prods
	std::map<std::string, std::vector<Product*>> cart;
};