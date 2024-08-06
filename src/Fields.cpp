#include "Fields.hpp"

//////////////////////////////////////////////////////////
// FIELD --------------------------------------------------------
Field::Field() {
    set_cells();
    set_letters();
    set_nums();
}

Field::~Field() {
    for (int i = 0; i < 10; i++) {
        delete[] cells[i];
    }

    delete[] cells;
    delete[] letters;
    delete[] nums;
}

void Field::set_cells() {
    cells = new Tool_cell*[10];

    for (int i = 0; i < 10; i++) {
        cells[i] = new Tool_cell[10];
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cells[i][j].set_size(32, 32);
            cells[i][j].set_image("..\\..\\src\\image\\tiles.png");
            cells[i][j].set_sprite(0, 0);
        }
    }
}

void Field::set_letters(){
    letters = new Tool_text[str_letters.getSize()];

    for (int i = 0; i < str_letters.getSize(); i++) {
        letters[i].set_string(str_letters[i]);
    } 
};

void Field::set_nums(){
    nums = new Tool_text[str_nums.getSize()];

    for (int i = 0; i < str_nums.getSize(); i++) {
        nums[i].set_string(str_nums[i]);
    }
};

//////////////////////////////////////////////////////////
// PLAYER_FIELD --------------------------------------------------------
void Player_field::draw_cells(std::unique_ptr<sf::RenderWindow>& window) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cells[i][j].set_position((i + 2) * 32, (j+2) * 32);
            cells[i][j].draw(window);
        }
    }
}

void Player_field::draw_letters(std::unique_ptr<sf::RenderWindow>& window) {
    for (int i = 0; i < str_letters.getSize(); i++) {
	    letters[i].set_position((i + 2) * 32 + 5, 32);
	    letters[i].draw(window);
    }
}

void Player_field::draw_nums(std::unique_ptr<sf::RenderWindow>& window) {
    for (int i = 0; i < str_nums.getSize(); i++) {
	    if (i != 10) {
		    if (i != 9) {
			    nums[i].set_position(1.25 * 32, ((i + 2.09) * 32));
		    }
		    else {
			    nums[i].set_position(1.0 * 32, ((i + 2.09) * 32) - 0.5);
		    }
	    }
	    else {
		    nums[i].set_position(1.5 * 32, ((i + 1.09) * 32));
	    }

	    nums[i].draw(window);
    }
}

void Player_field::draw_field(std::unique_ptr<sf::RenderWindow>& window) {
    draw_cells(window);
    draw_letters(window);
    draw_nums(window);
};

//////////////////////////////////////////////////////////
// ENEMY_FIELD --------------------------------------------------------
void Enemy_field::draw_cells(std::unique_ptr<sf::RenderWindow>& window) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cells[i][j].set_position((i + 17) * 32, (j+2) * 32);
            cells[i][j].draw(window);
        }
    }
}

void Enemy_field::draw_letters(std::unique_ptr<sf::RenderWindow>& window) {
    for (int i = 0; i < str_letters.getSize(); i++) {
	    letters[i].set_position((i + 17) * 32 + 5, 32);
	    letters[i].draw(window);
    }
}

void Enemy_field::draw_nums(std::unique_ptr<sf::RenderWindow>& window) {
    for (int i = 0; i < str_nums.getSize(); i++) {
	    if (i != 10) {
		    if (i != 9) {
			    nums[i].set_position(16.25 * 32, ((i + 2.09) * 32));
		    }
		    else {
			    nums[i].set_position(16 * 32, ((i + 2.09) * 32) - 0.5);
		    }
	    }
	    else {
		    nums[i].set_position(16.5 * 32, ((i + 1.09) * 32));
	    }

	    nums[i].draw(window);
    }
}

void Enemy_field::draw_field(std::unique_ptr<sf::RenderWindow>& window) {
    draw_cells(window);
    draw_letters(window);
    draw_nums(window);
};