#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>
using namespace std;

class exception_fish : public exception{
};

class exception_boot: public exception{
};

class Fishing{
    int field[9] = {0};
    int attempts = 0;

public:
    void catchFish(int pond){
        if(pond >= 9 || field[pond - 1 ] == 4) throw runtime_error("Error!");
        if (field[pond - 1] == 1) {
            throw exception_fish();
        }
        else{
            attempts++;
            if (field[pond - 1] == 2) throw exception_boot();
            if (field[pond - 1] == 0) {
                attempts++;
            }

        }
        field[pond - 1] = 4;
    }
    int get_attempts() const {return attempts;}
    void set_fish_boot(){
        srand(std::time(nullptr));
        field[rand() % 9] = 1;
        for(int i = 0; i < 3; i++){
            srand(std::time(nullptr));
            int n = rand() % 9;
            while(field[n] != 0){
                srand(std::time(nullptr));
                n = rand() % 9;
            }
            field[n] = 2;
        }
        cout << "Filling completed! " << endl;
    }

};

int main() {

    Fishing game;
    game.set_fish_boot();

    bool fishing = true;

    while (fishing)
    {
        cout << "Enter number pond to fishing: ";
        int pond;
        cin >> pond;
        try
        {
            game.catchFish(pond);
        }
        catch (const exception_fish &e)
        {
            cerr << "You are win! " << " in " << game.get_attempts() << " attempts\n";
            fishing = false;
        }
        catch (const exception_boot &e)
        {
            cout << "You are lose! " << '\n';
            fishing = false;
        }
        catch (const runtime_error &e)
        {
            cout << e.what() << '\n';
        }
        catch (const exception &e)
        {
            cerr << e.what() << '\n';
        }
    }
}
