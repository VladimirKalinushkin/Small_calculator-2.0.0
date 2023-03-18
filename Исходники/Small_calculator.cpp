
#include "Small_calculator.h"


int main() {

    welcome_words();
    inicialiseStream(Stream);

    try {

        expression_handler();

    }
    catch(const char* err){

        cerr << err << "Произошла неизвестная ошибка!";
        system("pause");

    }
    
    return 0;
	
}
