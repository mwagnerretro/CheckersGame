#include <SFML/Graphics.hpp>
#include "board.h"
#include "piece.h"
#include "game.h"

int main() {
    // Setup the SFML window
    sf::RenderWindow window(sf::VideoMode(600, 600), "Checkers");
    window.setFramerateLimit(60);

    // Initialize board and pieces
    Board board;
    Piece redPieces[12];
    Piece whitePieces[12];
    Game game;
    game.Setup(redPieces, whitePieces);

    // Game state variables
    int turn = 0;  // 0 for Red, 1 for White
    int selectedX = -1;
    int selectedY = -1;
    bool isPieceSelected = false;
    bool pieceHasJumped = false;

    // Game loop
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                game.ProcessTurn(turn, mousePos, redPieces, whitePieces, selectedX, selectedY, isPieceSelected, pieceHasJumped);
            }
        }

        // Clear the window
        window.clear();

        // Draw board and pieces
        board.Draw(window);
        for (const Piece& piece : redPieces) {
            piece.Draw(window);
        }
        for (const Piece& piece : whitePieces) {
            piece.Draw(window);
        }
        
        // Highlight the selected piece and available moves
        if (isPieceSelected) {
            board.HighlightSelectedPiece(window, selectedX, selectedY);

            // Get available moves and highlight them
            Piece* selectedPiece = game.FindPiece(selectedX, selectedY, redPieces, whitePieces);
            std::vector<std::pair<int, int>> availableMoves = game.GetAvailableMoves(selectedPiece, redPieces, whitePieces);
            for (const auto& move : availableMoves) {
                board.HighlightMove(window, move.first, move.second);
            }
        }
        
        // Display the window
        window.display();
    }

    return 0;
}
