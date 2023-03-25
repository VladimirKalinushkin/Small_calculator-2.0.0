
class Settings
{

    char _mode;

    public:

        Settings() { _mode = mode_is_arabian; }

        char get_mode() { return _mode; }

        void set_main_settings();

    private:

        class exeption : public exception
        {
        public:
            exeption(char *msg);
            exeption(char *msg, char &bad_value);

            void what();

        private:
            char *message = NULL;
            char *bad_value_char = NULL;
        };

        void set_Mode_calculating();
        char get_and_valid_Mode_calculating();

};

Settings main_settings;
