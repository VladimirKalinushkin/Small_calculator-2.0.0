


class TokenStream_for_Roman_int : public TokenStream
{

    private:
        vector <Token_for_Roman_int> Stream;

        

    public:

        Token_for_Roman_int TokenStream_for_Roman_int::get(istream &is);
        Token_for_Roman_int TokenStream_for_Roman_int::get(ifstream &ifs);

        void putback(Token_for_Roman_int buffer);

};

