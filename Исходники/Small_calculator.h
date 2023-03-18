
#include "Standart/standart_includes_for_cpp.h"

const char exit_simbol = 'q';
const char* promt = ">>";
const char* print_result = ": ";
const char print = ';';
const char equality = '=';
const char help = '?';

const char type_is_number = 'n';
const char type_is_word = 'w';
const char type_is_constante = 'c';
const char type_is_keyword = 'k';
const char type_is_varriable = 'v';
const char type_is_function = 'f';

const double pi = 3.14159265;
const char* pi_name = "pi";
const double e = 2.71828;
const char* e_name = "e";

const char* inicialise_word = "var";

const char* cos_name = "cos";
const char* sin_name = "sin";
const char* tan_name = "tn";
const char* asin_name = "asin";
const char* acos_name = "acos";
const char* atan_name = "atan";
const char* sqrt_name = "sqrt";
const char* abs_name = "abs";
const char* ln_name = "ln";
const char* log_name = "log";
const char* ceil_name = "ceil";
const char* floor_name = "floor";
const char* fmod_name = "fmod";


#include "TokenStream/Stream.cpp"

TokenStream Stream;

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

#include "Expression_handler/expression_handler.cpp"

