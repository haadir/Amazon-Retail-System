#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    //iterate thru rawWords look for spaces and punctuation
    //each time there is a space, add that word to the set
    //if there is punc check left and right of punc add if 2 letters
    //return set
    set<string> mySet;

    //for loop loop thru rawWords
    //rawWords[i]
    //isspace or punctuation, count variable
    //ispunct

		//int count = 0;
		string temp = "";
		for (int i = 0; i < rawWords.length(); i++) {
			if ((rawWords[i] == ' ') || (ispunct(rawWords[i]))) {
				if (temp.length() >= 2) {
					mySet.insert(temp);
					temp = "";
					i++;
				}
				else {
					temp = "";
					i++;
				}
			}
			temp += rawWords[i];
		}
		if (temp.length() >= 2) mySet.insert(temp);
		return mySet;

    // int size = rawWords.length();
    // char char_array[n + 1];
    // strcpy(char_array, rawWords.c_str());

    // int count = 0;
    // while (char_array != '\0') {
    //     char_array = buf[i];
    //     if (isspace(char_array))
    //         count++;
    //     }
    //     i++;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
