
#include "enable_mode.h"


void enable_mode(Settings & _settings)
{
    switch(_settings.get_mode())
    {
        case mode_is_arabian:
            expression_handler();
            break;
        case mode_is_roman:
            expression_handler_for_Roman_int();
            break;
        default:

            break;
    }
}

