/*
 * Created by Sagi Wilentzik on 15/02/2022.
 */

#include <iostream>
#include <cstring>

using namespace std;

class Game {
    friend class Singleton;
private:
    char *name;

    Game() {
        name = new char[strlen("Game 1") + 1];
        strcpy(name, "Game 1");
    }
};

class Singleton {
    Game *game;
public:
    Game *getGame() {
        if (!game)
            game = new Game();
        return game;

    }
};

int main() {
    Singleton singleton;
    Game* g1 = singleton.getGame();
    cout << "g1 address=" << g1 << endl;
    Game* g2 = singleton.getGame();
    cout << "g2 address=" << g2 << endl;
}
