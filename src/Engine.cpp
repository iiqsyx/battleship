#include "Engine.hpp"

Engine::Engine(unsigned int x_size, unsigned int y_size, const std::string &lable){
    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(x_size, y_size), lable);
}

void Engine::run(){
    while (window->isOpen()) {
        input();
        draw();
    } 
}

void Engine::input(){
    sf::Event event;
    while (window->pollEvent(event)) {
        if(event.type == sf::Event::Closed){
            window->close();
        }
    }
    
}

void Engine::draw(){
    window->clear();
    window->draw(background);
    window->display();
}