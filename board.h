#pragma once

#include <SFML/Graphics.hpp>

class Board {
public:
    static constexpr int size = 8;

    void Draw(sf::RenderWindow& window) const;
    void HighlightSelectedPiece(sf::RenderWindow& window, int x, int y) const;
    void HighlightMove(sf::RenderWindow& window, int x, int y) const;
};
