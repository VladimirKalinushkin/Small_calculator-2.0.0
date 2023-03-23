
#include "Standart/standart_includes_for_cpp.h"
#include "Standart/Roman_int.hpp"
#include "constantes.h"
#include "Settings/Settings.cpp"
#include "TokenStream/Stream.cpp"

TokenStream Stream;
Settings main_settings;

#include "Expression_handler/expression_handler.cpp"
#include "Expression_handler_for_Roman_int/expression_handler_for_Roman_int.cpp"


void inicialiseStream(TokenStream& Stream){

    Stream.inicialise_Constantes(Token (pi_name, pi));
    Stream.inicialise_Constantes(Token (e_name, e));

    Stream.inicialise_KeyWords(Token (inicialise_word));

    Stream.inicialise_FunctionsName(Token (cos_name));
    Stream.inicialise_FunctionsName(Token (sin_name));
    Stream.inicialise_FunctionsName(Token (tan_name));
    Stream.inicialise_FunctionsName(Token (asin_name));
    Stream.inicialise_FunctionsName(Token (acos_name));
    Stream.inicialise_FunctionsName(Token (atan_name));
    Stream.inicialise_FunctionsName(Token (sqrt_name));
    Stream.inicialise_FunctionsName(Token (abs_name));
    Stream.inicialise_FunctionsName(Token (ln_name));
    Stream.inicialise_FunctionsName(Token (log_name));
    Stream.inicialise_FunctionsName(Token (ceil_name));
    Stream.inicialise_FunctionsName(Token (floor_name));
    Stream.inicialise_FunctionsName(Token (fmod_name));


}

void help_out(){

    string adres = "help";

    ifstream file_help;
    file_help.open(adres);
    if (file_help.is_open()) {

        char ch;
        while (file_help.get(ch)) {
            cout << ch;
        }

    }
    else {
        cout << "Файл справки отсутствует!, обратитесь к производителю! " << endl;
    }
    file_help.close();

}

void welcome_words() {
    cout
        << "Введите выражение, завершите его "
        << print
        << " . Для выхода введите "
        << exit_simbol
        << ", для прочих вопросов введите "
        << help
        << '\n'
        << '\n';
}
