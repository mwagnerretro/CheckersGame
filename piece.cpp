#include "piece.h"

Piece::Piece(int x, int y, sf::Color color)
    : x(x), y(y), color(color), isKing(false), isAlive(true) {}



void Piece::Draw(sf::RenderWindow& window) const {
    if (isAlive) {
        sf::CircleShape shape(30.f);
        shape.setFillColor(color);
        shape.setPosition(sf::Vector2f(x * 75 + 7.5f, y * 75 + 7.5f));
        window.draw(shape);

        if (isKing) {
            shape.setFillColor(sf::Color::Green);
            shape.setRadius(10.f);
            shape.setPosition(sf::Vector2f(x * 75 + 30, y * 75 + 30));
            window.draw(shape);
        }
    }
}
