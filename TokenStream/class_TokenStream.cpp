
#include "class_TokenStream.h"

Token TokenStream::get() {

     if(Stream.size()) {

         Token buffer = Stream.back();
         Stream.pop_back();
         return buffer;

     }
     else {

         Token buffer = buffer.get();

         if (buffer.type == type_is_word) return set_Token_type(buffer);
         return buffer;

     }

}

void TokenStream::putback(Token buffer) {

    Stream.push_back(buffer);

}

Token TokenStream::set_Token_type(Token buffer) {

    string s = buffer.word;
    
    for(auto t : ConstantesStream)
    {
        if(t.word == s)
            return t;
    }
    
    for(auto t : KeyWordsStream)
    {
        if(t.word == s)
            return t;
    }
    
    for(auto t : FunctionsNameStream)
    {
        if(t.word == s)
            return t;
    }

    for(auto t : VarriablesStream)
    {
        if(t.word == s)
            return t;
    }
    return buffer;

}

void TokenStream::inicialise_Varriable(string s, double value){

    Token new_Varriable(s, value);
    new_Varriable.type = type_is_varriable;
    VarriablesStream.push_back(new_Varriable);

}

void TokenStream::set_Varriable(string s, double value) {

    for(int i = 0; i < VarriablesStream.size(); i++)
    {
        if(VarriablesStream[i].word == s)
        {
            VarriablesStream[i].value = value;
            return;
        }
    }

    throw " Неизвестная переменная! \n";

}

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
