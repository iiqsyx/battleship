#include <SFML/Graphics.hpp>
#include "Engine.hpp"

int main() {
    Engine* engine = new Engine(352,352, "App");
    engine->run();

    delete engine;
    return 0;
}