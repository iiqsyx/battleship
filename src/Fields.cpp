#include "Fields.hpp"
#include <iostream>
//////////////////////////////////////////////////////////
// FIELD --------------------------------------------------------
Field::Field() {
    set_cells();
    set_letters();
    set_nums();

    for (int i = 0; i < 10; i++) {
	    for (int j = 0; j < 10; j++) {
		    map[i][j].map = 0;
            map[i][j].ship = nullptr;
	    }
    }
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

void Field::set_nums() {
    nums = new Tool_text[str_nums.getSize()];

    for (int i = 0; i < str_nums.getSize(); i++) {
        nums[i].set_string(str_nums[i]);
    }
};

void Field::random_placement(Ship* ship, int ship_count) {
    std::srand(std::time(0));

    for (int i = 0; i < ship_count; i++) {
        place_ship(ship + i);
    }
}

void Field::place_ship(Ship* ship) {
    bool isHorizontal = (rand() % 2) == 0;
    int row, col;

    do {
	    if (isHorizontal) {
		    row = rand() % 10;
		    col = rand() % (10 - ship->get_size() + 1);
	    }
	    else {
		    row = rand() % (10 - ship->get_size() + 1);
		    col = rand() % 10;
	    }
    } while (!is_valid_placement( row, col, ship->get_size(), isHorizontal));

    if (isHorizontal) {
	    for (int i = col; i < col + ship->get_size(); i++) {
		    map[row][i].map = 1;
            map[row][i].ship = ship;
        
            ship->pos.insert(std::make_pair(row, i));
            std::cout<< row << i << std::endl;
	    }
    }
    else {
	    for (int i = row; i < row + ship->get_size(); i++) {
		    map[i][col].map = 1;
            map[i][col].ship = ship;

            ship->pos.insert(std::make_pair(i, col));
            std::cout<< i << col << std::endl;
	    }
    }
}

bool Field::is_valid_placement(int row, int col, int ship_size, bool is_horizontal) {
    if (is_horizontal) {
	    for (int i = row - 1; i <= row + 1; i++) {
		    for (int j = col - 1; j <= col + ship_size; j++) {
			    if (i >= 0 && i < 10 && j >= 0 && j < 10) {
				    if (map[i][j].map != 0) {
					    return false;
				    }
			    }
		    }
	    }
    }
    else {
	    for (int i = row - 1; i <= row + ship_size; i++) {
		    for (int j = col - 1; j <= col + 1; j++) {
			    if (i >= 0 && i < 10 && j >= 0 && j < 10) {
				    if (map[i][j].map != 0) {
					    return false;
				    }
			    }
		    }
	    }
    }
    
    return true;
}

//////////////////////////////////////////////////////////
// PLAYER_FIELD --------------------------------------------------------
void Player_field::draw_cells(std::unique_ptr<sf::RenderWindow>& window) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cells[i][j].set_position((i + 2) * 32, (j+3) * 32);
            cells[i][j].draw(window);
        }
    }
}

void Player_field::draw_letters(std::unique_ptr<sf::RenderWindow>& window) {
    for (int i = 0; i < str_letters.getSize(); i++) {
	    letters[i].set_position((i + 2) * 32 + 5, 64);
	    letters[i].draw(window);
    }
}

void Player_field::draw_nums(std::unique_ptr<sf::RenderWindow>& window) {
    for (int i = 0; i < str_nums.getSize(); i++) {
	    if (i != 10) {
		    if (i != 9) {
			    nums[i].set_position(1.25 * 32, ((i + 3.09) * 32));
		    }
		    else {
			    nums[i].set_position(1.0 * 32, ((i + 3.09) * 32) - 0.5);
		    }
	    }
	    else {
		    nums[i].set_position(1.5 * 32, ((i + 2.09) * 32));
	    }

	    nums[i].draw(window);
    }
}

void Player_field::draw_field(std::unique_ptr<sf::RenderWindow>& window) {
    draw_cells(window);
    draw_letters(window);
    draw_nums(window);
};

void Player_field::input_ships() {
    random_placement(four, 1);
    random_placement(three, 2);
    random_placement(two, 3);
    random_placement(one, 4);
}

void Player_field::set_ships_sprites() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if(map[i][j].map == 1){
                cells[i][j].set_sprite(32,0);
            }
            else {
                cells[i][j].set_sprite(0,0);
            }
        }
    }
    
};

void Player_field::replace_ships() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j].map = 0;
            map[i][j].ship = nullptr;
            cells[i][j].reset_pressed();
        }
    }

    delete[] one;
    delete[] two;
    delete[] three;
    delete[] four;
    
    one = new One_deck_ship[4];
    two = new Two_deck_ship[3];
    three = new Three_deck_ship[2];
    four = new Four_deck_ship[1];

    input_ships();
    set_ships_sprites();
};

bool Player_field::check_ship(int x, int y){
    return map[x][y].map == 1;
}

void Player_field::damage_ship(int x, int y){
    if(map[x][y].map == 1){
        if(((map[x][y].ship->damage) + 1) < map[x][y].ship->get_size()){
            map[x][y].map = 0;
            map[x][y].ship->damage = map[x][y].ship->damage + 1;
            
            cells[x][y].set_sprite(64, 0);
        }
        else if(((map[x][y].ship->damage) + 1) == map[x][y].ship->get_size()){
            map[x][y].map = 0;
            map[x][y].ship->damage = map[x][y].ship->damage + 1;
            
            for (auto pos : map[x][y].ship->pos) {
                for (int i = pos.first - 1; i < pos.first + 2; i++) {
                    for (int j = pos.second - 1; j < pos.second + 2; j++) {
                        if(i >= 0 && i < 10 && j >= 0 && j < 10){
                            cells[i][j].set_sprite(160, 0);
                        }
                    } 
                }
            }

            for (auto pos : map[x][y].ship->pos) {
                cells[pos.first][pos.second].set_sprite(96, 0);
            }
        }
    }
}  

//////////////////////////////////////////////////////////
// ENEMY_FIELD --------------------------------------------------------
void Enemy_field::draw_cells(std::unique_ptr<sf::RenderWindow>& window) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cells[i][j].set_position((i + 17) * 32, (j+3) * 32);
            cells[i][j].draw(window);
        }
    }
}

void Enemy_field::draw_letters(std::unique_ptr<sf::RenderWindow>& window) {
    for (int i = 0; i < str_letters.getSize(); i++) {
	    letters[i].set_position((i + 17) * 32 + 5, 64);
	    letters[i].draw(window);
    }
}

void Enemy_field::draw_nums(std::unique_ptr<sf::RenderWindow>& window) {
    for (int i = 0; i < str_nums.getSize(); i++) {
	    if (i != 10) {
		    if (i != 9) {
			    nums[i].set_position(16.25 * 32, ((i + 3.09) * 32));
		    }
		    else {
			    nums[i].set_position(16 * 32, ((i + 3.09) * 32) - 0.5);
		    }
	    }
	    else {
		    nums[i].set_position(16.5 * 32, ((i + 2.09) * 32));
	    }

	    nums[i].draw(window);
    }
}

void Enemy_field::draw_field(std::unique_ptr<sf::RenderWindow>& window) {
    draw_cells(window);
    draw_letters(window);
    draw_nums(window);
};