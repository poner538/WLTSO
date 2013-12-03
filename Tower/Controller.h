
class Controller
{
public:
    Controller(int new_gold, int new_lives);

    void change_gold(const int value);
    void change_points(const int value);
    void lives();

    static Controller controller;

private:
    int gold = 0;
    int points = 0;
    int current_lives = 100;
};
