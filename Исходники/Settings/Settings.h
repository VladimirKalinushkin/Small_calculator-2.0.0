
class Settings
{

    char _mode_calculating;

    public:

        Settings(const set <char> & Modes_calculating);

        char get_mode() { return _mode_calculating; }

        void set_all_settings(const set <char> & Modes_calculating);

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

        void set_Mode_calculating(const set <char> & Modes_calculating);
        char get_and_valid_Mode_calculating(const set <char> & Modes_calculating);

};
