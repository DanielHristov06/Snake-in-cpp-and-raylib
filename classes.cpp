#include <raylib.h>
#include <globals.h>
#include <deque>

class Snake {
    public:
        std::deque<Vector2> body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};

        void Draw(){
            for (unsigned int i = 0; i < body.size(); i++){
                float x = body[i].x;
                float y = body[i].y;
                DrawRectangleRounded(Rectangle{x * cellSize, y * cellSize, (float)cellSize, (float)cellSize}, 0.5, 6, darkGreen);
            }
        }
};

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