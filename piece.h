#pragma once

#include <SFML/Graphics.hpp>

class Piece {
public:
    int x;
    int y;
    bool isKing;
    sf::Color color;
    bool isAlive;

    Piece(int x = 0, int y = 0, sf::Color color = sf::Color::White);

    void Draw(sf::RenderWindow& window) const;
};
