#include <memory>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Tools.hpp"
#include "Ships.hpp"

struct Map{
    int map;
    Ship* ship;
};

class Field {
public:
    Field();
    virtual ~Field();

protected:
    Tool_cell ** cells;
    Tool_text* letters;
    Tool_text* nums;

    Map map[10][10];

    const sf::String str_letters = "ABCDEFGHIJ";
    const sf::String str_nums = "12345678910";

    Ship* one = new One_deck_ship[4];
    Ship* two = new Two_deck_ship[3];
    Ship* three = new Three_deck_ship[2];
    Ship* four = new Four_deck_ship[1];

    bool is_valid_placement(int row, int col, int sizeOfP, bool isHorizontal);
    void place_ship(Ship* ship);
    void random_placement(Ship* ship, int ship_count);

private: 
    virtual void draw_letters(std::unique_ptr<sf::RenderWindow>& window) = 0;
    virtual void draw_nums(std::unique_ptr<sf::RenderWindow>& window) = 0;
    virtual void draw_cells(std::unique_ptr<sf::RenderWindow>& window) = 0;

    void set_letters();
    void set_nums();
    void set_cells();
};

class Player_field : private Field {
public:
    Player_field() : Field(){ }

    Tool_cell& get_position(int x, int y) {
        return cells[x][y];
    }
    bool check_ship(int x, int y);
    void damage_ship(int x, int y);

    void draw_field(std::unique_ptr<sf::RenderWindow>& window);
    void input_ships();
    void set_ships_sprites();
    void replace_ships();

private:
    void draw_letters(std::unique_ptr<sf::RenderWindow>& window) override;
    void draw_nums(std::unique_ptr<sf::RenderWindow>& window) override;
    void draw_cells(std::unique_ptr<sf::RenderWindow>& window) override;
};

class Enemy_field : private Field {
public:
    Enemy_field() : Field(){ }

    Tool_cell& get_position(int x, int y) {
        return cells[x][y];
    }
    void draw_field(std::unique_ptr<sf::RenderWindow>& window);

private:
    void draw_letters(std::unique_ptr<sf::RenderWindow>& window) override;
    void draw_nums(std::unique_ptr<sf::RenderWindow>& window) override;
    void draw_cells(std::unique_ptr<sf::RenderWindow>& window) override;
};




