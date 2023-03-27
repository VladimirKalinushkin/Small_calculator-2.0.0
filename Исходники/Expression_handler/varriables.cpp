
#include "varriables.h"


void set_new_varriable(TokenStream &Stream){

    Token name = Stream.get();
    if (name.type == type_is_word) {

        if (Stream.get().type == equality) {

            double value = third_order(Stream);
            Stream.inicialise_Varriable(name.word, value);

        }
        else throw " Неправильно объявлена переменная! ('var' 'name' '=' 'выражение') \n";

    }
    else throw " Имя переменной занято! \n";

}

bool set_Varriable(TokenStream &Stream) {

    Token oper = Stream.get();
    Token new_oper = Stream.get();

    if ( oper.type == type_is_varriable && new_oper.type == equality) {

        double value = third_order(Stream);
        Stream.set_Varriable( oper.word, value );
        return true;

    }
    else {

        Stream.putback(new_oper);
        Stream.putback(oper);
        return false;

    }

}
