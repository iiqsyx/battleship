#include <SFML/Graphics.hpp>
#include <memory>
#include "Engine.hpp"

int main() {
    auto engine = std::make_shared<Engine>(352, 352, "battleship");
    engine->set_icon("..\\..\\src\\image\\icon.png");
    engine->run();

    return 0;
}