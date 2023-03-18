
#include "calculation.h"

double third_order() {

    double value = second_order();

    while (cin) {

        Token oper = Stream.get();
        switch (oper.type) {
            case '+':{
                value += second_order();
                break;}
            case '-':{
                value -= second_order();
                break;}
            default:{
                Stream.putback(oper);
                return value;
                break;}
        }
    }

    return 0;

}

double second_order() {

    double value = first_order();

    while (cin) {

        Token oper = Stream.get();

        if(oper.type == '*' || oper.type == '/') {

            Token second_oper = Stream.get();
            if(second_oper.type == 'n' || second_oper.type == '(' || second_oper.type == type_is_constante || second_oper.type == type_is_varriable || second_oper.type == type_is_function) {
                Stream.putback(second_oper);

                switch (oper.type) {
                    case '*':{
                        value *= first_order();
                        break;}
                    case '/':{
                        double second_value = first_order();
                        if (second_value == 0)throw " Деление на нуль! \n";
                        value /= second_value;
                        break;}
                    default:{
                        throw " Ошибка в логике программы! \n";
                        break;}
                }
            }
            else throw " За знаком * и / должно быть число или скобка! \n";

        }
        else {
            Stream.putback(oper);
            return value;
        }
    }
    return 0;

}

double first_order() {

    double value = primary();

    while (cin) {

        Token oper = Stream.get();
        if (oper.type == '^') {
            double second_value = primary();
            value = pow (value, second_value);
        }
        else {
            Stream.putback(oper);
            return value;
        }
    }

    return 0;

}

double primary() {

    Token oper = Stream.get();

    switch (oper.type) {

        case type_is_constante: case type_is_number: case type_is_varriable:{

            return oper.value;
            break;

        }
        case '+':{
            return primary();
            break;}
        case '-':{
            return  -primary();
            break;}
        case '(':{

            double result = third_order();
            oper = Stream.get();
            if (oper.type != ')') throw "нет ')' \n";
            else return result;
            break;

        }
        case type_is_function:{
            Stream.putback(oper);
            return math_function();
            break;
        }
        case type_is_word: {
            throw " Переменная не инициализирована! \n";
            break;}
        case type_is_keyword: {
            throw " Имя занято! \n";
            break;}
        default:{
            throw " Нет первичного выражения! \n";
            break;}
    }

    return 0;
}

double math_function() {

    Token name_function = Stream.get();
    string name = name_function.word;

    if (name == fmod_name) {

        if (Stream.get().type == '(') {
            double left = primary();
            if (Stream.get().type == ',') {
                double right = primary();
                if ( right == 0 ) throw "Деление на нуль!\n";
                if (Stream.get().type == ')') {
                    return fmod ( left, right );
                }
                else throw "Должно быть: fmod ( число, число )! \n";
            }
            else throw "Должно быть: fmod ( число, число )! \n";
        }
        else throw "Должно быть: fmod ( число, число )! \n";
    }

    double result = primary();

    if ( name == asin_name || name == acos_name || name == atan_name ) {
        if (result >= -1 & result <=1) {
            if (name == asin_name) return asin ( result );
            else if (name == acos_name) return acos ( result );
            else if (name == atan_name) return atan ( result );
        }
        else throw "Для обратных тригонометрических функций должно испооьзоваться значение от -1 до 1! \n";
    }

    if (name == cos_name) return cos ( result );
    else if (name == sin_name) return sin ( result );
    else if (name == tan_name) return tan ( result );
    else if (name == sqrt_name) {

        if (result >= 0) return sqrt ( result );
        else throw " Корень можно извлечь только из неотрицательного числа! \n";
    }
    else if (name == abs_name) return abs ( result );
    else if (name == ln_name) return log ( result );
    else if (name == log_name) return log10 ( result );
    else if (name == ceil_name) return ceil ( result );
    else if (name == floor_name) return floor (result );

    else throw "Неизвестная функция, ошибка в логике программы! \n";

    return 0;

}
