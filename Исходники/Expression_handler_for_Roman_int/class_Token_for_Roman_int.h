

class Token_for_Roman_int : public Token
{

    public:
        
        Roman_int value;

        Token_for_Roman_int();

        Token_for_Roman_int get(istream &is);
        Token_for_Roman_int get(ifstream &ifs);

};

