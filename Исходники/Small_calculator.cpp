
#include "Small_calculator.h"


void enable_mode(Settings & _settings)
{
    switch(_settings.get_mode())
    {
        case Arabian:
            expression_handler();
            break;
        case Roman:
            expression_handler_for_Roman_int();
            break;
        default:

            break;
    }
}


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
                    enable_mode(main_settings);
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
