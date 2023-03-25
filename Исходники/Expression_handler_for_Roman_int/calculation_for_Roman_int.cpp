
#include "calculation_for_Roman_int.h"


Roman_int third_order_for_Roman_int()
{
    Roman_int value = second_order_for_Roman_int();

    while (cin) {

        Token oper = Stream.get();
        
        switch (oper.type) {
            case '+':{
                Roman_int second_value = second_order_for_Roman_int();
                value += second_value;
                break;}
            case '-':{
                Roman_int second_value = second_order_for_Roman_int();
                value -= second_value;
                break;}
            default:{
                Stream.putback(oper);
                return value;
                break;}
        }
    }

    return value;
}
Roman_int second_order_for_Roman_int()
{
    Roman_int value = primary_for_Roman_int();

    while (cin) {

        Token oper = Stream.get();
        
        switch (oper.type) {
            case '*':{
                Roman_int second_value = primary_for_Roman_int();
                value *= second_value;
                break;}
            case '/':{
                Roman_int second_value = primary_for_Roman_int();
                value /= second_value;
                break;}
            default:{
                Stream.putback(oper);
                return value;
                break;}
        }
    }

    return value;
}
Roman_int primary_for_Roman_int()
{
    Token oper = Stream.get();

    switch (oper.type) {

        case type_is_word:{

            Roman_int ret;
            ret.set(oper.word);

            if(ret.empty())
                throw "Неправильный ввод!";

            return ret;
            break;

        }
        case '+':{

            return primary_for_Roman_int();
            break;
            
        }
        case '(':{

            Roman_int result = third_order_for_Roman_int();

            oper = Stream.get();
            if (oper.type != ')')
                throw "нет ')' \n";

            return result;
            break;

        }
        default:{

            throw " Нет первичного выражения! \n";
            break;
        
        }
    }

}