#include <memory>
#include <SFML/Graphics.hpp>
#include "Tools.hpp"

class Field {
public:
    Field(/* args */);
    virtual ~Field();

private: 
    void draw_letters(std::unique_ptr<sf::RenderWindow>& window);
    void draw_nums(std::unique_ptr<sf::RenderWindow>& window);
    void draw_cells(std::unique_ptr<sf::RenderWindow>& window);

    void set_letters();
    void set_nums();
    void set_cells();

    
};

class Player_Field : public Field {

};

class Enemy_field : public Field {

};




