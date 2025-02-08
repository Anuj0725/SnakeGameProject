Snake Game Documentation

Group Members:
1. ANUJ MADHANI                202401017
2. GOHIL PARTH JAYESHKUMAR     202401056
3. BECHARA UTSAV BHAVESHBHAI   202401021
4. CHAVDA NAITIK ARJUNBHAI     202401037

Overview:

This is a simple console-based Snake game implemented in C++ using the Windows API for cursor manipulation. The game features a moving snake that grows in length as it consumes fruit, with the player's score increasing accordingly. The game ends when the snake collides with itself or the game boundaries.

Game Components

1. Constants & Global Variables

const int width = 80, height = 20; - Defines the game area dimensions.
int x, y; - Stores the snake's head position.
int fruitCordX, fruitCordY; - Stores the fruit's position.
int playerScore; - Keeps track of the player's score.
vector<int> snakeTailX(100), snakeTailY(100); - Arrays to store the snake's tail coordinates.
int snakeTailLen; - Stores the current length of the snake's tail.
enum snakesDirection { STOP = 0, LEFT, RIGHT, UP, DOWN }; - Enum to represent the snake's movement direction.
snakesDirection sDir; - Stores the current direction of the snake.
bool isGameOver; - Flag to check if the game is over.
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); - Handles console output.

2. Utility Functions

void SetCursorPosition(int x, int y);
Moves the cursor to the specified (x, y) position in the console.
void HideCursor();
Hides the console cursor to prevent flickering.
void SetColor(int color);
Sets the console text color.

3. Core Game Functions

void GameInit();
Initializes the game variables.
Sets the starting position of the snake and fruit.
Initializes the snake's tail length.
void DrawGame(string playerName, int snakeColor);
Renders the game frame.
Displays the game border.
Draws the snake (head & tail) and the fruit.
Shows the player's score and name.
int GetNextColor(int currentColor);
Changes the snake's color when it consumes fruit.
Returns the next color in sequence.
void UpdateGame(int &snakeColor);
Moves the snake's head in the current direction.
Updates the position of the snake's tail.
Checks for collisions with walls or itself.
Checks if the snake eats the fruit, increases score, and grows the tail.
Generates a new fruit at a random position.
int SetDifficulty();
Returns a delay value for Sleep() function, controlling game speed.
void UserInput();
Reads user keyboard input.
Updates the snake's direction based on keypress (w, a, s, d).
Exits the game if x is pressed.

4. main() Function

Asks for the player's name.
Calls GameInit() to initialize the game.
Hides the cursor.
Starts the game loop:
Calls DrawGame() to render the game.
Processes user input via UserInput().
Updates the game state with UpdateGame().
Pauses the loop for a short duration (Sleep(dfc)).
Ends the game when isGameOver == true.
Displays the final score and prompts the user to exit.

Controls

W - Move Up
A - Move Left
S - Move Down
D - Move Right
X - Quit the Game

Game Flow

Initialize game state.
Display the game frame.
Accept player input.
Update snake position.
Check for collisions and game-over conditions.
Repeat steps 2-5 until the game ends.
Display the final score and exit.
