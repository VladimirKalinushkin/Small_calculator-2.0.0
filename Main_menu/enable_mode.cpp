
#include "enable_mode.h"


void enable_mode(Settings & Main_settings, TokenStream &Stream)
{

    switch(Main_settings.get_mode())
    {
        case mode_is_arabian:
            expression_handler(Stream);
            break;
        case mode_is_roman:
            expression_handler_for_Roman_int(Stream);
            break;
        default:
            throw "Не установлен режим работы!\n";
            break;
    }

}

