

#include "class_Token_for_Roman_int.h"

Token_for_Roman_int get(istream &is)
{

    Token_for_Roman_int buffer;

    is >> buffer.type;

    switch (buffer.type)
    {
        case print:case equality: case '-': case '+': case '*': case '/':
            break;
            
        default:

            is.putback(buffer.type);
            is >> buffer.value;

            if(!buffer.value.empty())
                buffer.type = type_is_Roman_int;

            else
                throw "Ошибка ввода!";
            
            break;
            
        }

    return buffer;

}
Token_for_Roman_int Token_for_Roman_int::get(ifstream &ifs){

    Token_for_Roman_int buffer;

    ifs >> buffer.type;

    switch (buffer.type)
    {
        case print:case equality: case '-': case '+': case '*': case '/':
            break;
            
        default:

            ifs.putback(buffer.type);
            ifs >> buffer.value;

            if(!buffer.value.empty())
                buffer.type = type_is_Roman_int;

            else
                throw "Ошибка ввода!";
            
            break;
            
        }

    return buffer;

}

