#include "board.h"

void Board::Draw(sf::RenderWindow& window) const {
    sf::RectangleShape tile(sf::Vector2f(75.f, 75.f));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            tile.setPosition(75 * j, 75 * i);
            tile.setFillColor((i + j) % 2 == 0 ? sf::Color::White : sf::Color::Black);
            window.draw(tile);
        }
    }
}

void Board::HighlightSelectedPiece(sf::RenderWindow& window, int x, int y) const {
    sf::CircleShape highlight(30.f);
    highlight.setFillColor(sf::Color::Transparent);
    highlight.setOutlineThickness(3.f);
    highlight.setOutlineColor(sf::Color::Green);
    highlight.setPosition(75 * x + 7.5f, 75 * y + 7.5f);
    window.draw(highlight);
}

void Board::HighlightMove(sf::RenderWindow& window, int x, int y) const {
    sf::CircleShape highlight(30.f);
    highlight.setFillColor(sf::Color::Transparent);
    highlight.setOutlineThickness(3.f);
    highlight.setOutlineColor(sf::Color::Blue);
    highlight.setPosition(75 * x + 7.5f, 75 * y + 7.5f);
    window.draw(highlight);
}
