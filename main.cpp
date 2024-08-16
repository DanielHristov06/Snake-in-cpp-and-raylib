#include <raylib.h>
#include <classes.cpp>

int main(){

    InitWindow(cellSize * cellCount, cellSize * cellCount, "Snake");
    SetTargetFPS(60);

    Food food;
    Snake snake;

    while (WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(lightGreen);

        snake.Draw();
        food.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}