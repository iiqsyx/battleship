#include "Engine.hpp"
#include <iostream>

Engine::Engine(unsigned int x_size, unsigned int y_size, const std::string &lable){
    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(x_size, y_size), lable);
    player_field = new Player_field;
    enemy_field = new Enemy_field;
}

void Engine::set_icon(const std::string& path_to_file) {
    sf::Image icon;
    icon.loadFromFile(path_to_file);

    window->setIcon(72, 72, icon.getPixelsPtr());
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
        sf::Vector2i mouse = sf::Mouse::getPosition(*window);
        sf::Vector2f mousePosition = window->mapPixelToCoords(mouse);

        if(event.type == sf::Event::Closed){
            window->close();
        }
        
    }
}

void Engine::draw(){
    window->clear();
    window->draw(background);
    player_field->draw_field(window);
    enemy_field->draw_field(window);
    window->display();
}