
enum Modes_calculating {Arabian = 1, Roman = 2};

class Settings
{

    Modes_calculating mode;

    public:

        Settings() { mode = Roman; }
        void set_mode(Modes_calculating _mode) {mode = _mode; }
        Modes_calculating get_mode() { return mode; }
};