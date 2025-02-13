Snake Game Documentation

Group Members:
1. ANUJ MADHANI                202401017
2. GOHIL PARTH JAYESHKUMAR     202401056
3. BECHARA UTSAV BHAVESHBHAI   202401021
4. CHAVDA NAITIK ARJUNBHAI     202401037

Overview:

Snake Game in C++


A classic Snake game implementation in C++ using Windows Console API. Navigate the snake to eat fruits, grow longer, and avoid collisions.

Features
Movement: Control the snake using arrow keys or WASD.

Color Changing Snake: Snake changes color as it grows.

Score Tracking: Earn points by eating fruits.

Collision Detection: Game ends if the snake hits walls or itself.

Restart Functionality: Play again with the 'R' key after game over.

Adjustable Speed: Control game speed via code (modify dfc variable).

Prerequisites
Windows OS (uses Windows API)

C++ Compiler (e.g., GCC, MSVC)

How to Run
Compile the Code:

bash
Copy
g++ snake.cpp -o snake.exe -static -luser32 -lwinmm
Run the Executable:

bash
Copy
snake.exe
Controls
W/↑ Arrow: Move Up

A/← Arrow: Move Left

S/↓ Arrow: Move Down

D/→ Arrow: Move Right

Q: Quit Game

R: Restart after Game Over

Gameplay Mechanics
The snake moves 2 spaces horizontally (left/right) and 1 space vertically (up/down).

Eating a fruit:

Increases score by 1.

Extends the snake's length.

Changes the snake's color (cycles through colors 10–15).

Fruit spawns at random even columns for alignment.

Customization
Snake Speed: Modify the dfc variable (delay in milliseconds) in main().

Initial Snake Color: Change snakeColor in main() (default: 10 = bright green).
