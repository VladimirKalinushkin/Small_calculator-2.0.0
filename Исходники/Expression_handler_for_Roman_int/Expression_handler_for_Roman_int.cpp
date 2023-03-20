
#include "Expression_handler_for_Roman_int.h"

void expression_handler_for_Roman_int()
{

    try
    {
            Roman_int result = third_order_for_Roman_int();
            cout
                << print_result
                << result
                << '\n';
    }
    catch(Roman_int::exeption ex)
    {
        ex.what();
    }

    if(Stream_RI.get(cin).type !=  print) 
        throw " Выражение неправильно завершено! Нет ';' \n";
    
}
