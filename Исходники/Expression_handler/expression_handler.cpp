
#include "expression_handler.h"

void inicialise_Varriable(){

    Token name = Stream.get();
    if (name.type == type_is_word) {

        if (Stream.get().type == equality) {

            double value = third_order();
            Stream.inicialise_Varriable(name.word, value);

        }
        else throw " Неправильно объявлена переменная! ('var' 'name' '=' 'выражение') \n";

    }
    else throw " Имя переменной занято! \n";

}

bool set_Varriable() {

    Token oper = Stream.get();
    Token new_oper = Stream.get();

    if ( new_oper.type == equality ) {

        double value = third_order();
        Stream.set_Varriable( oper.word, value );
        return true;

    }
    else {

        Stream.putback(new_oper);
        Stream.putback(oper);
        return false;

    }

}

void expression_handler() {

    bool is_set_varriable = false;

    while (cin) {
        cout << promt;
        try {

            Token oper = Stream.get();

            switch (oper.type) {

                case exit_simbol: {
                    return;
                    break;}
                case help: {
                    help_out();
                    continue;
                    break;}
                case type_is_keyword: {
                    if ( oper.word == inicialise_word ) inicialise_Varriable();
                    break;}
                default: {
                    Stream.putback(oper);
                    if ( oper.type == type_is_varriable ) {
                        is_set_varriable = set_Varriable();
                    }
                    if ( !is_set_varriable ) {
                        double result = third_order();
                        cout
                            << print_result
                            << result
                            << '\n';
                    }
                    break;
                }
            }

            if(Stream.get().type != print) {
                throw " Выражение неправильно завершено! Нет ';' \n";
            }

        }

        catch (const char* msg) { error (msg); }

    }
    
}
