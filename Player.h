#ifndef CPPGAME_PLAYER_H
#define CPPGAME_PLAYER_H

#include <SFML/Graphics.hpp>


class Player {
private:
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    float SPEED = 1.f;
    float JUMP_HEIGHT = 10.f;

public:

    int posX;
    int posY;

    int speedY;

    void moveLeft();
    void moveRight();
    void jump();
    void tick();
    void draw(sf::RenderWindow window);

    Player()
    {
        playerSprite = sf::Sprite();

        playerTexture.loadFromFile("assets/assets/player_stand.png");
        playerSprite.setTexture(playerTexture);

        posX = 0;
        posY = 1050;

        speedY = 0;

        playerSprite.setPosition(posX, posY);
    }

};


#endif //CPPGAME_PLAYER_H
