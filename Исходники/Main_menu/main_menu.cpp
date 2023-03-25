
#include "main_menu.h"

void main_menu() {

    while (cin) {
        cout << promt;
        try {

            Token oper = Stream.get();

            switch (oper.type) {

                case exit_simbol: 
                    return;
                    break;

                case help: 
                    help_out();
                    continue;
                    break;

                case settings:
                    main_settings.set_main_settings();
                    continue;
                    break;

                default: 
                    Stream.putback(oper);
                    enable_mode(main_settings);
                    break;
                
            }

        }

        catch (const char* msg) { error (msg); }

    }
    
}


void help_out(){

    string adres = "help";

    ifstream file_help;
    file_help.open(adres);
    if (file_help.is_open()) {

        char ch;
        while (file_help.get(ch)) {
            cout << ch;
        }

    }
    else {
        cout << "Файл справки отсутствует!, обратитесь к производителю! " << endl;
    }
    file_help.close();

}

void welcome_words() {
    cout
        << "Введите выражение, завершите его "
        << print
        << " . Для выхода введите "
        << exit_simbol
        << ", для прочих вопросов введите "
        << help
        << ", для настроек - "
        << settings
        << '\n'
        << '\n';
}
