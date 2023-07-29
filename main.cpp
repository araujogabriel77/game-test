#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;
constexpr float SHAPE_SPEED = 0.1f;

constexpr float SHAPE_SIZE = 10.f;
constexpr float SHAPE_DIAMETER = SHAPE_SIZE * 2;


int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
    sf::CircleShape shape(SHAPE_SIZE);

    sf::Vector2f platformSize(800, 100);
    sf::RectangleShape platform(platformSize);

    sf::Font font;

    if (!font.loadFromFile("Fonts/roboto.ttf"))
    {
        std::cerr << "Could not load font\n";
        exit(-1);
    }

    
    platform.setPosition(0, 500);
    platform.setFillColor(sf::Color::Blue);
    
    sf::Vector2f platformCurrentPosition = platform.getPosition();

    float x = platformCurrentPosition.x;
    float y = platformCurrentPosition.y;

    std::string coordinates = std::to_string((int)x) + ", " + std::to_string((int)y);
    sf::Text text(coordinates, font, 12);
    text.setPosition(200, 200);

    shape.setFillColor(sf::Color::Green);

    float x_speed = SHAPE_SPEED;
    float y_speed = SHAPE_SPEED;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Vector2f shapePosition = shape.getPosition();
        
        if (shapePosition.x >= WINDOW_WIDTH - SHAPE_DIAMETER || shapePosition.x < 0)
        {
            x_speed *= -1.0f;
        }

        if (shapePosition.y >= WINDOW_HEIGHT - SHAPE_DIAMETER || shapePosition.y < 0)
        {
            y_speed *= -1.0f;
        }


        shape.setPosition(shapePosition.x + x_speed, shapePosition.y + y_speed);

        std::string coordinates = std::to_string((int)shapePosition.x) + ", " + std::to_string((int)shapePosition.y);
        sf::Text text(coordinates, font, 12);

        window.clear();
        window.draw(shape);
        //window.draw(platform);
        window.draw(text);
        window.display();
    }

    return 0;
}