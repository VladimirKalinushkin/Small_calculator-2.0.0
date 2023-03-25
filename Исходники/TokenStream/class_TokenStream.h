
class TokenStream {

private:

    vector <Token> Stream;
    vector <Token> ConstantesStream;
    vector <Token> KeyWordsStream;
    vector <Token> FunctionsNameStream;
    vector <Token> VarriablesStream;

    Token set_Token_type(Token buffer);

public:

    Token get();
    void putback(Token buffer);

    void inicialise_Varriable(string s, double value);
    void set_Varriable(string s, double value);

    void inicialise_Constantes(Token a) { a.type = type_is_constante; ConstantesStream.push_back(a); }
    void inicialise_KeyWords(Token a) { a.type = type_is_keyword; KeyWordsStream.push_back(a); }
    void inicialise_FunctionsName(Token a) { a.type = type_is_function; FunctionsNameStream.push_back(a); }


};


TokenStream Stream;

void inicialiseStream(TokenStream& Stream);
