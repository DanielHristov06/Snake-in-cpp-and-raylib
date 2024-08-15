#include <raylib.h>
#include <classes.cpp>

int main(){

    InitWindow(cellSize * cellCount, cellSize * cellCount, "Snake");
    SetTargetFPS(60);

    Food food;

    while (WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(lightGreen);

        food.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}