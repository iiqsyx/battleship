#include "Engine.hpp"
#include <iostream>

Engine::Engine(unsigned int x_size, unsigned int y_size, const std::string &lable){
    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(x_size, y_size), lable);
    player_field = new Player_field;
    enemy_field = new Enemy_field;

    replace_ships_button = new Tool_button("..\\..\\src\\image\\tiles.png", 64, 64);
    replace_ships_button->set_position(416, 128);
    replace_ships_button->set_sprite(256, 0);

    player_field->input_ships();
    player_field->set_ships_sprites();
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
        sf::Vector2f mouse_position = window->mapPixelToCoords(mouse);

        if(event.type == sf::Event::Closed){
            window->close();
        }

        if (replace_ships_button->pressed(event, mouse_position)) {
            player_field->replace_ships();
        }
        

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if ((player_field->get_position(i,j)).pressed(event, mouse_position)) {
                    if(player_field->check_ship(i, j)) {
                        player_field->damage_ship(i, j);
                    }
                }
            } 
        }
            
    }
}

void Engine::draw(){
    window->clear();
    window->draw(background);
    player_field->draw_field(window);
    enemy_field->draw_field(window);
    replace_ships_button->draw(window);
    window->display();
}