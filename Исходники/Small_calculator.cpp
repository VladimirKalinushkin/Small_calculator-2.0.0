
#include "Small_calculator.h"


void main_menu() {


    while (cin) {
        cout << promt;
        try {

            Token oper = Stream.get();

            switch (oper.type) {

                case exit_simbol: 
                    return;
                    break;

                case help: 
                    help_out();
                    continue;
                    break;

                default: 
                    Stream.putback(oper);
                    expression_handler();
                    break;
                
            }

        }

        catch (const char* msg) { error (msg); }

    }
    
}


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
