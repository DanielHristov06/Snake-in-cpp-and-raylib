#include <raylib.h>
#include <classes.cpp>

// Used to update the snake's movement in the set interval
double lastUpdateTime = 0;

bool eventTriggered(double interval){
    double currentTime = GetTime();

    if (currentTime - lastUpdateTime >= interval){
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

class Game{
    public:
        Snake snake;
        Food food;

        void Draw(){
            snake.Draw();
            food.Draw();
        }

        void Update(){
            snake.Update();
        }
};

int main(){

    InitWindow(cellSize * cellCount, cellSize * cellCount, "Snake");
    SetTargetFPS(60);

    Game game;

    while (WindowShouldClose() == false){
        BeginDrawing();

        if (eventTriggered(0.2)){
            game.Update();
        }

        if (IsKeyPressed(KEY_W) && game.snake.dir.y != 1){
            game.snake.dir = {0, -1};
        }
        if (IsKeyPressed(KEY_S) && game.snake.dir.y != -1){
            game.snake.dir = {0, 1};
        }
        if (IsKeyPressed(KEY_A) && game.snake.dir.x != 1){
            game.snake.dir = {-1, 0};
        }
        if (IsKeyPressed(KEY_D) && game.snake.dir.x != -1){
            game.snake.dir = {1, 0};
        }

        ClearBackground(lightGreen);

        game.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}