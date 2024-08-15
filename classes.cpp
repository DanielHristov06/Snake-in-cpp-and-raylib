#include <raylib.h>
#include <globals.h>

class Food {
    public:
        Vector2 position;
        Texture2D texture;

        Food(){
            Image image = LoadImage("Graphics/food.png");
            texture = LoadTextureFromImage(image);
            UnloadImage(image);
            position = GenerateRandomPos();
        }

        ~Food(){
            UnloadTexture(texture);
        }

        void Draw(){
            DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
        }

        Vector2 GenerateRandomPos(){
            float x = GetRandomValue(0, cellCount - 1);
            float y = GetRandomValue(0, cellCount - 1);
            return Vector2{x, y};
        }
};