#include <SFML/Graphics.hpp>

class Tool_image {
public:
    Tool_image(sf::String path_to_file);
    Tool_image() { };

    sf::Texture& get_texture() {
        return texture;
    }
    void init_tool(sf::String path_to_file) {
        image.loadFromFile(path_to_file);
        texture.loadFromImage(image);
    }

private:
    sf::Image image;
    sf::Texture texture;
};

class Tool {
public:
    Tool() {};
    virtual ~Tool() {};

    virtual void set_position(float x, float y) = 0;
    virtual void draw(std::unique_ptr<sf::RenderWindow>& window) = 0;

};

class Tool_text : public Tool {
public:
    Tool_text() {
        font.loadFromFile("..\\..\\src\\font\\BrokenChalk.ttf");
        txt.setFont(font);
        txt.setCharacterSize(20);
        txt.setFillColor(sf::Color(68, 32, 99));
        txt.setStyle(sf::Text::Bold);
    }

    void set_position(float x, float y) override;
    void set_size(float size);
    void set_string(sf::String str);
    void set_font(sf::String path);
    void set_color(sf::Color && color);
    void draw(std::unique_ptr<sf::RenderWindow>& window) override;

    
    
private:    
    sf::Text txt;
    sf::String str;
    sf::Font font;
};

class Tool_cell : public Tool {
public:
    Tool_cell(): press(false) {};
    Tool_cell(sf::String path_to_image, float wight, float hight) : wight(wight), hight(hight) {
        press = false;
        cell.setSize(sf::Vector2f(this->wight, this->hight));
        
        image.init_tool(path_to_image);
        cell.setTexture(&image.get_texture());
        cell.setTextureRect(sf::IntRect(0, 0, 32, 32));
    };

    
    void set_position(float x, float y) override;
    void set_size(float wight, float hight);
    void set_sprite(int x_pos, int y_pos);
    void set_image(sf::String path_to_image);
    void draw(std::unique_ptr<sf::RenderWindow>& window) override;
    void reset_pressed();
    
    bool pressed(sf::Event & evt, sf::Vector2f pos);

private:
    Tool_image image;
    sf::RectangleShape cell;
    float wight;
    float hight;
    bool press;

};

class Tool_button : public Tool {
public:
    Tool_button(): press(false) {};
    Tool_button (sf::String path_to_image, float wight, float hight) : wight(wight), hight(hight) {
        press = false;
        button.setSize(sf::Vector2f(this->wight, this->hight));
        
        image.init_tool(path_to_image);
        button.setTexture(&image.get_texture());
        button.setTextureRect(sf::IntRect(0, 0, 32, 32));
    };

    void set_sprite(int x_pos, int y_pos);
    void set_position(float x, float y) override;
    void set_size(float wight, float hight);
    void set_image(sf::String path_to_image);
    void draw(std::unique_ptr<sf::RenderWindow>& window) override;

    bool pressed(sf::Event & evt, sf::Vector2f pos);

private:
    void set_pressed_sprite();
    void set_original_sprite();

    Tool_image image;
    sf::RectangleShape button;
    float wight;
    float hight;
    bool press;
    float sprite_x;
    float sprite_y;
};