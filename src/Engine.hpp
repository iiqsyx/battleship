#include <SFML/Graphics.hpp>
#include <memory>
class Engine {
public:
    Engine(unsigned int x_size, unsigned int y_size, const std::string &lable);

    void run();

private:
    void draw();
    void input();

private:
   std::unique_ptr<sf::RenderWindow> window;
   sf::RectangleShape background = sf::RectangleShape(sf::Vector2f(352, 352));
};


