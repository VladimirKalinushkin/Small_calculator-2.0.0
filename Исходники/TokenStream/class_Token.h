
class Token
{
public:

    char type;
    double value;
    string word;
    Roman_int roman_value;

    Token() {};
    Token (string w, double v) { word = w; value = v;}
    Token (double v) { value = v; }
    Token (string w) { word = w; }

    Token get();

};
