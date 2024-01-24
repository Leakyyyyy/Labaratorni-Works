#include <iostream>
#include <vector>
#include <ctime>
#include <conio.h>
#include <thread>

using namespace std;

int score = 0;
int highScore = 0;
const int WIDTH = 15;
const int HEIGHT = 20;
const int DELAY = 150;

struct Point {
    int x, y;
};

vector<vector<int>> board(HEIGHT, vector<int>(WIDTH, 0));

vector<vector<Point>> tetrominos = {
    {{0, 0}, {1, 0}, {0, 1}, {1, 1}},      // Квадрат
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},      // Палка лежит
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},      // Палка стоит
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},      // Г
    {{0, 0}, {0, 1}, {0, 2}, {1, 0}},      // L
    {{0, 0}, {0, 1}, {0, 2}, {-1, 0}},     // обратная L
    {{0, 0}, {0, 1}, {0, 2}, {-1, 2}},     // Обратная Г
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},      // Т
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}},      // S
    {{0, 0}, {1, 0}, {1, -1}, {1, -2}}     // Z
};

void DrawBoard(const vector<Point>& currentTetromino, const Point& currentPosition) {
    system("cls");

    // Copy the board to avoid modifying the original board
    vector<vector<int>> tempBoard = board;

    // Update the copy with the current tetromino
    for (const auto& point : currentTetromino) {
        int x = currentPosition.x + point.x;
        int y = currentPosition.y + point.y;

        if (y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH) {
            tempBoard[y][x] = 2; // Use a different value to represent the falling tetromino
        }
    }

    // Draw the updated board
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            if (tempBoard[row][col] == 0)
                cout << ".";
            else if (tempBoard[row][col] == 1)
                cout << "X"; // Occupied cell
            else
                cout << "O"; // Falling tetromino
        }
        cout << endl;
    }
}

bool IsCollision(const vector<Point>& tetromino, const Point& position) {
    for (const auto& point : tetromino) {
        int x = position.x + point.x;
        int y = position.y + point.y;

        // Check if the position is within the board boundaries
        if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT || board[y][x] != 0) {
            return true; // Collision detected
        }
    }

    return false; // No collision
}

void MergeTetromino(const vector<Point>& tetromino, const Point& position) {
    for (const auto& point : tetromino) {
        int x = position.x + point.x;
        int y = position.y + point.y;

        // Add boundary checks to prevent placing blocks outside the board
        if (y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH) {
            board[y][x] = 1;
        }
    }
}

void RemoveCompletedLines() {
    int linesCleared = 0;
    for (int row = HEIGHT - 1; row >= 0; row--) {
        bool isCompleted = true;

        for (int col = 0; col < WIDTH; col++) {
            if (board[row][col] == 0) {
                isCompleted = false;
                break;
            }
        }

        if (isCompleted) {
            for (int r = row; r > 0; r--) {
                for (int c = 0; c < WIDTH; c++) {
                    board[r][c] = board[r - 1][c];
                }
            }
            // Clear the top row
            for (int c = 0; c < WIDTH; c++) {
                board[0][c] = 0;
            }

            row++;
            linesCleared++;
        }
    }

    // Update score based on the number of lines cleared
    score += 10 * linesCleared;

    // Update high score if the current score is higher
    if (score > highScore) {
        highScore = score;
    }
}

void RotateTetromino(vector<Point>& tetromino) {
    // Find the center of the tetromino
    Point center = tetromino[0];
    for (const auto& point : tetromino) {
        center.x += point.x;
        center.y += point.y;
    }
    center.x /= tetromino.size();
    center.y /= tetromino.size();

    // Rotate each point around the center
    for (auto& point : tetromino) {
        int tempX = point.x;
        point.x = center.x - (point.y - center.y);
        point.y = center.y + (tempX - center.x);
    }
}

bool IsCollisionAfterRotation(const vector<Point>& tetromino, const Point& position) {
    vector<Point> rotatedTetromino = tetromino;
    RotateTetromino(rotatedTetromino);

    for (const auto& point : rotatedTetromino) {
        int x = position.x + point.x;
        int y = position.y + point.y;

        if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT || board[y][x] != 0)
            return true;
    }

    return false;
}

void RotateTetromino(vector<Point>& tetromino, const Point& center) {
    for (auto& point : tetromino) {
        int tempX = point.x;
        point.x = center.x - (point.y - center.y);
        point.y = center.y + (tempX - center.x);
    }
}

int main() {
    srand(time(0));

    bool gameOver = false;

    vector<Point> currentTetromino;
    Point currentPosition;

    int tetrominoIndex = rand() % tetrominos.size();
    currentTetromino = tetrominos[tetrominoIndex];
    currentPosition = { WIDTH / 2, 0 };

    auto startTime = chrono::high_resolution_clock::now();  // Track the start time

    while (!gameOver) {
        auto currentTime = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::seconds>(currentTime - startTime);

        DrawBoard(currentTetromino, currentPosition);

        bool isXAtTop = false;
        for (int col = 9; col < WIDTH; col++) {
            if (board[0][col] == 1) {
                isXAtTop = true;
                break;
            }
        }
        if (isXAtTop) {
            cout << "Game over! Symbol 'X' is at the top." << endl;
            break;
        }

        cout << "Score: " << score << " Time: " << duration.count() << "s" << endl;
        cout << "Next Tetromino:" << endl;

        // Display the next falling tetromino
        for (const auto& point : tetrominos[(tetrominoIndex + 1) % tetrominos.size()]) {
            int x = WIDTH / 2 + point.x;
            int y = point.y;

            // Check if it's the start of a new row
            if (point.x == 0) {
                cout << endl;
            }

            cout << "O"; // Use a character to represent the next tetromino
        }

        if (_kbhit()) {
            char input = _getch();

            switch (input) {
            case 'a':
                currentPosition.x--;
                if (IsCollision(currentTetromino, currentPosition))
                    currentPosition.x++;
                break;
            case 'd':
                currentPosition.x++;
                if (IsCollision(currentTetromino, currentPosition))
                    currentPosition.x--;
                break;
            case 'r':
                // Find the center of the current tetromino
                Point center = currentTetromino[0];
                for (const auto& point : currentTetromino) {
                    center.x += point.x;
                    center.y += point.y;
                }
                center.x /= currentTetromino.size();
                center.y /= currentTetromino.size();

                // Rotate the tetromino and check for collisions after rotation
                vector<Point> rotatedTetromino = currentTetromino;
                RotateTetromino(rotatedTetromino, center);
                if (!IsCollisionAfterRotation(rotatedTetromino, currentPosition)) {
                    currentTetromino = rotatedTetromino;
                }
                break;
            }
        }

        currentPosition.y++;
        if (IsCollision(currentTetromino, currentPosition)) {
            currentPosition.y--;
            MergeTetromino(currentTetromino, currentPosition);
            RemoveCompletedLines();


            tetrominoIndex = rand() % tetrominos.size();
            currentTetromino = tetrominos[tetrominoIndex];
            currentPosition = { WIDTH / 2, 0 };

        }

        // Introduce delay to slow down the falling of tetrominoes
        this_thread::sleep_for(chrono::milliseconds(DELAY));
    }

    DrawBoard(currentTetromino, currentPosition);
    cout << "Game Over! Score: " << score << endl;
    cout << "Record: " << highScore << endl;

    return 0;
}
