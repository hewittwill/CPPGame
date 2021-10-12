#include <iostream>
#include "Player.h"

void Player::moveLeft() {
    posX -= SPEED;
}

void Player::moveRight() {
    posX += SPEED;
}

void Player::jump() {
    if (speedY < 20) {
        speedY = JUMP_HEIGHT;
    }
}

void Player::draw(sf::RenderWindow window) {
    window.draw(playerSprite);
}

void Player::tick() {
    if (speedY > 0) {
        speedY -= 1;
        posY -= speedY;
    }

    if (posY < 1050 && speedY == 0) {
        posY += 10;
    }

    Player::playerSprite.setPosition(posX, posY);
}