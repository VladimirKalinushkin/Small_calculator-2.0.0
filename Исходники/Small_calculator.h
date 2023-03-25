
#include "Standart/standart_includes_for_cpp.h"

#include "constantes.h"

//Settings и TokenStream зависит отглобальных констант
#include "Settings/Settings.cpp"
#include "TokenStream/Stream.cpp"

//Expression_handler зависит от Stream
#include "Expression_handler/expression_handler.cpp"
#include "Expression_handler_for_Roman_int/expression_handler_for_Roman_int.cpp"

//Main_menu зависит от Settings, Expression_handler и констант
#include "Main_menu/main_menu.cpp"
