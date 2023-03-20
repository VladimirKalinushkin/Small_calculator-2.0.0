
#include "calculation_for_Roman_int.h"


Roman_int third_order_for_Roman_int()
{
    Roman_int value = second_order_for_Roman_int();

    while (cin) {

        Token_for_Roman_int oper = Stream_RI.get(cin);
        
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
                Stream_RI.putback(oper);
                return value;
                break;}
        }
    }

    return value;
}
Roman_int second_order_for_Roman_int()
{
    Roman_int value = second_order_for_Roman_int();

    while (cin) {

        Token_for_Roman_int oper = Stream_RI.get(cin);
        
        switch (oper.type) {
            case '*':{
                Roman_int second_value = second_order_for_Roman_int();
                value *= second_value;
                break;}
            case '/':{
                Roman_int second_value = second_order_for_Roman_int();
                value /= second_value;
                break;}
            default:{
                Stream_RI.putback(oper);
                return value;
                break;}
        }
    }

    return value;
}
Roman_int primary_for_Roman_int()
{
    Token_for_Roman_int oper = Stream_RI.get(cin);

    switch (oper.type) {

        case type_is_Roman_int:{

            return oper.value;
            break;

        }
        case '+':{
            return primary_for_Roman_int();
            break;}
        case '(':{

            Roman_int result = third_order_for_Roman_int();
            oper = Stream_RI.get(cin);
            if (oper.type != ')') throw "нет ')' \n";
            else return result;
            break;

        }
        default:{
            throw " Нет первичного выражения! \n";
            break;}
    }

    return oper.value;
}