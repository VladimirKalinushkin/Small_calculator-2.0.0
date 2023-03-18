
#include "class_Token.h"

Token Token::get(){

    Token buffer (0);

    cin >> buffer.type;
    switch (buffer.type){
        case print: case exit_simbol: case equality: case help: case '-': case '+': case '*': case '/':  case '(': case ')': case '^': case ',': {
            break;
            }
        case '0':  case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': {
            cin.putback(buffer.type);
            cin >> buffer.value;
            buffer.type = type_is_number;
        break;
        }
        default:{
            if( isalpha(buffer.type) ){

                cin.putback(buffer.type);

                buffer.type = type_is_word;
                buffer.word = get_word_from_string();

            }
            else throw " Неправильный ввод! \n";
            break;
            }
        }

    return buffer;

}
