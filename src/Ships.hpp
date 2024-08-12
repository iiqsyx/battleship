#include <unordered_map>
class Ship {
public:
    Ship(): is_alive(true) { damage = 0;};
    int get_size(){ return size; }

    bool is_alive;
    int damage;
    std::unordered_multimap<int, int> pos;

protected:
    int size;
};

class One_deck_ship: public Ship {
public:
    One_deck_ship(): Ship() {
        size = 1;
    };
};

class Two_deck_ship: public Ship {
public:
    Two_deck_ship(): Ship(){
        size = 2;
    };
};

class Three_deck_ship: public Ship {
public:
    Three_deck_ship(): Ship(){
        size = 3;
    };
};

class Four_deck_ship: public Ship {
public:
    Four_deck_ship(): Ship(){
        size = 4;
    };
};



