#include <conio.h>
#include <iostream>
#include <windows.h>
#include <ctime>
#include <vector>

using namespace std;

const int width = 80;
const int height = 20;
int x, y;
int fruitCordX, fruitCordY;
int playerScore;
vector<int> snakeTailX(100), snakeTailY(100);
int snakeTailLen;
enum snakesDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
snakesDirection sDir;
bool isGameOver;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void SetCursorPosition(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hConsole, coord);
}

void HideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void SetColor(int color) {
    SetConsoleTextAttribute(hConsole, color);
}

void GameInit() {
    isGameOver = false;
    sDir = RIGHT;
    srand(time(0));
    x = width / 2;
    y = height / 2;
    fruitCordX = rand() % width;
    fruitCordY = rand() % height;
    playerScore = 0;
    snakeTailLen = 3;

    for (int i = 0; i < snakeTailLen; i++) {
        snakeTailX[i] = x - (i + 1);
        snakeTailY[i] = y;
    }
}

void DrawGame(string playerName, int snakeColor) {
    SetCursorPosition(0, 0);

    cout << string(width + 2, '-') << "\n";

    for (int i = 0; i < height; i++) {
        cout << "|"; 
        for (int j = 0; j < width; j++) {
            if (i == y && j == x) {
                SetColor(snakeColor);
                cout << "O";
            } 
            else if (i == fruitCordY && j == fruitCordX) {
                SetColor(12);
                cout << "#";
            } 
            else {
                bool isTail = false;
                for (int k = 0; k < snakeTailLen; k++) {
                    if (snakeTailX[k] == j && snakeTailY[k] == i) {
                        SetColor(snakeColor);
                        cout << "o";
                        isTail = true;
                        break;
                    }
                }
                if (!isTail) {
                    SetColor(7);
                    cout << " ";
                }
            }
        }
        cout << "|\n"; 
    }

    cout << string(width + 2, '-') << "\n";
    SetColor(7);
    cout << playerName << " Your Score: " << playerScore << "\n";
}

int GetNextColor(int currentColor) {
    switch (currentColor) {
        case 10: return 11;
        case 11: return 12;
        case 12: return 13;
        case 13: return 14;
        case 14: return 15;
        default: return 10;
    }
}

void UpdateGame(int &snakeColor) {
    int prevX = snakeTailX[0], prevY = snakeTailY[0], prev2X, prev2Y;
    snakeTailX[0] = x;
    snakeTailY[0] = y;

    for (int i = 1; i < snakeTailLen; i++) {
        prev2X = snakeTailX[i];
        prev2Y = snakeTailY[i];
        snakeTailX[i] = prevX;
        snakeTailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (sDir) {
        case LEFT: x -= 2; break;  
        case RIGHT: x += 2; break; 
        case UP: y--; break;
        case DOWN: y++; break;
    }

    if (x >= width || x < 0 || y >= height || y < 0)
        isGameOver = true;

    for (int i = 0; i < snakeTailLen; i++) {
        if (snakeTailX[i] == x && snakeTailY[i] == y)
            isGameOver = true;
    }

    if ((x == fruitCordX && y == fruitCordY) || 
        (sDir == LEFT && x + 1 == fruitCordX && y == fruitCordY) || 
        (sDir == RIGHT && x - 1 == fruitCordX && y == fruitCordY)) {
        
        playerScore += 1;
        
        do {
            fruitCordX = rand() % width;
        } while (fruitCordX % 2 != 0); 
        
        fruitCordY = rand() % height;
        snakeTailLen++;
        snakeColor = GetNextColor(snakeColor);
    }
}


int SetDifficulty() {
    return 50;
}

void UserInput() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a': if (sDir != RIGHT) sDir = LEFT; break;
            case 'd': if (sDir != LEFT) sDir = RIGHT; break;
            case 'w': if (sDir != DOWN) sDir = UP; break;
            case 's': if (sDir != UP) sDir = DOWN; break;
            case 'x': isGameOver = true; break;
        }
    }
}

int main() {
    string playerName;
    int dfc = SetDifficulty();

    GameInit();
    HideCursor();
    int snakeColor = 10;

    while (!isGameOver) {
        DrawGame(playerName, snakeColor);
        UserInput();
        UpdateGame(snakeColor);
        Sleep(dfc);
    }

    SetCursorPosition(0, height + 4);
    cout << "Game Over! Final Score: " << playerScore << "\n";
    system("pause");
    return 0;
}