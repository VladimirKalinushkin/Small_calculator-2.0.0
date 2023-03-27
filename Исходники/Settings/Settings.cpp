
#include "Settings.h"


Settings::Settings(const set <char> & Modes_calculating)
{

    _mode_calculating = *Modes_calculating.begin();
    
}

void Settings::set_all_settings(const set <char> & Modes_calculating)
{
    try{

        set_Mode_calculating(Modes_calculating);

    }
    catch(exeption & ex)
    {
        ex.what();
    }
}

void Settings::set_Mode_calculating(const set <char> & Modes_calculating)
{
    
    cout << "Введите режим работы вычислений (полный режим с арабскими числами или ограниченный - с римскими): " 
         << mode_is_arabian << " / " << mode_is_roman 
         << '\n';
    
    _mode_calculating = get_and_valid_Mode_calculating(Modes_calculating); 

}
char Settings::get_and_valid_Mode_calculating(const set <char> & Modes_calculating)
{

    set <char> Modes = Modes_calculating;

    char mode;
    cin >> mode;

    if(Modes.count(mode))
        return mode;

    throw exeption("Неправильный ввод!\n");
        
}


Settings::exeption::exeption(char *msg)
{
    message = msg;
}
Settings::exeption::exeption(char *msg, char &bad_value)
{
    message = msg;
    bad_value_char = &bad_value;
}
void Settings::exeption::what()
{

    if (message)
        cerr << message << "\n";
    if (bad_value_char)
        cerr << "  Передано: " << *bad_value_char << "\n";
    if (!message)
        cerr << "Неизвестная ошибка!\n";
}
