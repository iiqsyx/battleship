#include <memory>
#include <SFML/Graphics.hpp>
#include "Tools.hpp"

class Field {
public:
    Field();
    virtual ~Field();

protected:
    Tool_cell ** cells;
    Tool_text* letters;
    Tool_text* nums;

    const sf::String str_letters = "ABCDEFGHIJ";
    const sf::String str_nums = "12345678910";

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
    void draw_field(std::unique_ptr<sf::RenderWindow>& window);

private:
    void draw_letters(std::unique_ptr<sf::RenderWindow>& window) override;
    void draw_nums(std::unique_ptr<sf::RenderWindow>& window) override;
    void draw_cells(std::unique_ptr<sf::RenderWindow>& window) override;
};

class Enemy_field : public Field {
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




