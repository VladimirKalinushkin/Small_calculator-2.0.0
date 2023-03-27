
#include "expression_handler.h"

void expression_handler(TokenStream &Stream){

    Token oper = Stream.get();
    Stream.putback(oper);

    if(oper.type == type_is_keyword)
        key_word_handler(Stream);

    else if ( set_Varriable(Stream) );

    else {

        double result = third_order(Stream);
        cout
            << print_result
            << result
            << '\n';

    }

    if(Stream.get().type != print) {
        throw " Выражение неправильно завершено! Нет ';' \n";
    }

}

void key_word_handler(TokenStream &Stream)
{

    Token key_word = Stream.get();

    if ( key_word.word == inicialise_word ) 
        set_new_varriable(Stream);

}

