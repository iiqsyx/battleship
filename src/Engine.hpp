#include <SFML/Graphics.hpp>
#include <memory>
#include "Fields.hpp"

class Engine {
public:
    Engine(unsigned int x_size, unsigned int y_size, const std::string &lable);
    void set_icon(const std::string& path_to_file);
    void run();

private:
    void draw();
    void input();

private:
   std::unique_ptr<sf::RenderWindow> window;
   sf::RectangleShape background = sf::RectangleShape(sf::Vector2f(896, 480));
   
   Player_field* player_field;
   Enemy_field* enemy_field;
   Tool_button* replace_ships_button;
};


