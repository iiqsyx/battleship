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

void Tool_cell::change_sprite(int x_pos, int y_pos) {
    cell.setTexture(&image.get_texture());
    cell.setTextureRect(sf::IntRect(x_pos, y_pos, 0, 0));
}

bool Tool_cell::pressed(sf::Event & evt, sf::Vector2f pos) {
    if (press) {
	    return false;
    }

    if (cell.getGlobalBounds().contains(pos.x,pos.y) && evt.type == sf::Event::MouseButtonPressed && !press) {
	    if (evt.key.code == sf::Mouse::Left) {
		    press = true;
		    return true;
	    }
    }

    if (!press) {
	    return false;
    }

    if (press) {
	    if (!(evt.type == sf::Event::MouseButtonPressed)) {
		    press = false;
	    }

	    return false;
    }
}

void Tool_cell::draw(std::unique_ptr<sf::RenderWindow>& window) {
    window->draw(cell);
}
