#include <raylib.h>

int main(){
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Snake");

    while(WindowShouldClose() == false){
        BeginDrawing();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}