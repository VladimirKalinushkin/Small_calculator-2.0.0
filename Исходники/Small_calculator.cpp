
#include "Small_calculator.h"


int main() {

    welcome_words();
    inicialiseStream(Stream);

    try {

        main_menu();

    }
    catch(const char* err){

        cerr << err << "Произошла неизвестная ошибка!";
        system("pause");

    }
    
    return 0;
	
}
