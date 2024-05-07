#pragma once

#include "board.h"
#include "piece.h"

class Game {
public:
    void Setup(Piece* redPieces, Piece* whitePieces);
    Piece* FindPiece(int x, int y, Piece* redPieces, Piece* whitePieces);
    void KillPiece(int x, int y, Piece* redPieces, Piece* whitePieces);
    std::vector<std::pair<int, int>> GetAvailableJumps(Piece* piece, Piece* redPieces, Piece* whitePieces);
    std::vector<std::pair<int, int>> GetAvailableMoves(Piece* piece, Piece* redPieces, Piece* whitePieces);
    void MovePiece(Piece* piece, int newX, int newY, Piece* redPieces, Piece* whitePieces, bool isJump);
    void ProcessTurn(int& turn, sf::Vector2i mousePos, Piece* redPieces, Piece* whitePieces, int& selectedX, int& selectedY, bool& isPieceSelected, bool& pieceHasJumped);
    void HighlightSelectedPiece(sf::RenderWindow& window, int x, int y) const;
    void HighlightMove(sf::RenderWindow& window, int x, int y) const;
};
