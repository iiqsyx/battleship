#include "Tools.hpp"

//////////////////////////////////////////////////////////
// TEXT TOOL --------------------------------------------------------
void Tool_text::set_position(float x, float y) {
    txt.setPosition(x, y);
}

void Tool_text::set_size(float size) {
    txt.setCharacterSize(size);
}

void Tool_text::set_string(sf::String str) {
    this->str = str;
    txt.setString(this->str);
}

void Tool_text::set_font(sf::String path) {
    font.loadFromFile(path);
    txt.setFont(font);
}

void Tool_text::set_color(sf::Color && color) {
    txt.setFillColor(std::move(color));
};

void Tool_text::draw(std::unique_ptr<sf::RenderWindow>& window) {
    window->draw(txt);
}

//////////////////////////////////////////////////////////
// CELL TOOL --------------------------------------------------------
void Tool_cell::set_position(float x, float y) {
    cell.setPosition(x, y);
}

void Tool_cell::set_size(float wight, float hight) {
    this->wight = wight;
    this->hight = hight;

    cell.setSize(sf::Vector2f(this->wight, this->hight));
}

void Tool_cell::set_image(sf::String path_to_image) {
    image.init_tool(path_to_image);
}

void Tool_cell::set_sprite(int x_pos, int y_pos) {
    cell.setTexture(&image.get_texture());
    cell.setTextureRect(sf::IntRect(x_pos, y_pos, 32, 32));
}

bool Tool_cell::pressed(sf::Event & evt, sf::Vector2f pos) {
    if (press) {
		return false;
	}

	if (cell.getGlobalBounds().contains(pos.x, pos.y) && evt.type == sf::Event::MouseButtonPressed && !press) {
		if (evt.key.code == sf::Mouse::Left) {
			press = true;
			return true;
		}
	}
    
	if (press) {
		if (!(evt.key.code == sf::Mouse::Left)) {
			press = false;
		}
		return false;
	}
}

void Tool_cell::reset_pressed() {
    press = false;
}

void Tool_cell::draw(std::unique_ptr<sf::RenderWindow>& window) {
    window->draw(cell);
}

//////////////////////////////////////////////////////////
// BUTTON TOOL --------------------------------------------------------
void Tool_button::set_sprite(int x_pos, int y_pos) {
    sprite_x = x_pos;
    sprite_y = y_pos;
    button.setTexture(&image.get_texture());
    button.setTextureRect(sf::IntRect(x_pos, y_pos, 32, 32));
}

void Tool_button::set_position(float x, float y) {
    button.setPosition(x, y);
}

void Tool_button::set_size(float wight, float hight) {
    this->wight = wight;
    this->hight = hight;

    button.setSize(sf::Vector2f(this->wight, this->hight));
}

void Tool_button::set_image(sf::String path_to_image) {
    image.init_tool(path_to_image);
}

void Tool_button::set_pressed_sprite() {
    button.setTexture(&image.get_texture());
    button.setTextureRect(sf::IntRect(sprite_x + 32, sprite_y, 32, 32));
}

void Tool_button::set_original_sprite() {
    button.setTexture(&image.get_texture());
    button.setTextureRect(sf::IntRect(sprite_x, sprite_y, 32, 32));
}

bool Tool_button::pressed(sf::Event & evt, sf::Vector2f pos) {

    if (button.getGlobalBounds().contains(pos.x, pos.y)) {
        set_pressed_sprite();
    }

    if (!(button.getGlobalBounds().contains(pos.x, pos.y))) {
        set_original_sprite();
    }

	if (button.getGlobalBounds().contains(pos.x, pos.y) && evt.type == sf::Event::MouseButtonPressed && !press) {
		if (evt.key.code == sf::Mouse::Left) {

            set_original_sprite();
			return true;
		}
	}

    return false;
}

void Tool_button::draw(std::unique_ptr<sf::RenderWindow>& window) {
    window->draw(button);
}
