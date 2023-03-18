#include "standart_function_for_cpp.h"

void error(string msg) {

    cin.clear();
    cin.ignore(32000, '\n');

    cerr << msg;

}

string get_word_from_string() {

	string word = "";
	char c;

	c = getchar();
	if (isalpha(c))cin.putback(c);
	else throw "Error in function 'get_word_from_string' in down level\n";

	while (cin) {

		c = getchar();
		if (isalpha(c) || c == '_' /*|| isnumber(c)*/) {
			
			word.push_back(c);

		}
		else {

			cin.putback(c);
			return word;

		}
	}

	return word;

}

bool isnumber(char _char) {

	switch(_char){
		
	case '0':	case '1':	case '2':	case '3':	case '4':	case '5':	case '6':	case '7':	case '8':	case '9':
		return true;
		break;
	default:
		return false;
	}

}
