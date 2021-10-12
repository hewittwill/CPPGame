#include <iostream>
#include <chrono>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Level.h"

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(1600, 1200), "My window");

    // create the level
    Level level;

    // create the player
    Player player;


    auto now = std::chrono::system_clock::now();

    long game_time = time_point_cast<std::chrono::milliseconds>(now).time_since_epoch().count();
    long game_time_delta = 0;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        now = std::chrono::system_clock::now();

        game_time_delta = time_point_cast<std::chrono::milliseconds>(now).time_since_epoch().count() - game_time;

        if(game_time_delta > 16) {
            game_time = time_point_cast<std::chrono::milliseconds>(now).time_since_epoch().count();
            player.tick();
        }


        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.moveLeft();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.moveRight();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            player.jump();
        }

        // clear the window with black color
        window.clear(sf::Color::White);

        player.draw(window);
//        level.draw(window);

        window.display();
    }

    return 0;

}
