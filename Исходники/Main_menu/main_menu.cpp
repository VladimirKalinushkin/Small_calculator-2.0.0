
#include "main_menu.h"

void main_menu(Settings &Main_settings, TokenStream &Stream) {

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
                    Main_settings.set_all_settings(Modes_calculating);
                    continue;
                    break;

                default: 
                    Stream.putback(oper);
                    enable_mode(Main_settings, Stream);
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
