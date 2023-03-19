
#include "class_TokenStream_for_Roman_int.h"

Token_for_Roman_int TokenStream_for_Roman_int::get(istream &is) {

     if(Stream.size()) {

         Token_for_Roman_int buffer = Stream.back();
         Stream.pop_back();
         return buffer;

     }
     else {

         Token_for_Roman_int buffer = buffer.get(is);

         return buffer;

     }

}
Token_for_Roman_int TokenStream_for_Roman_int::get(ifstream &ifs) {

     if(Stream.size()) {

         Token_for_Roman_int buffer = Stream.back();
         Stream.pop_back();
         return buffer;

     }
     else {

         Token_for_Roman_int buffer = buffer.get(ifs);

         return buffer;

     }

}

void TokenStream_for_Roman_int::putback(Token_for_Roman_int buffer) {

    Stream.push_back(buffer);

}
