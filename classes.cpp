#include <globals.h>

class Snake {
    public:
        std::deque<Vector2> body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
        Vector2 dir = {1, 0};
        bool addSegment = false;

        void Update(){
            body.push_front(Vector2Add(body[0], dir));
            if (addSegment){
                addSegment = false;
            }
            else{
                body.pop_back();
            }
        }

        void Draw(){
            for (unsigned int i = 0; i < body.size(); i++){
                float x = body[i].x;
                float y = body[i].y;
                DrawRectangleRounded(Rectangle{offset + x * cellSize, offset + y * cellSize, (float)cellSize, (float)cellSize}, 0.5, 6, darkGreen);
            }
        }

        void Reset(){
            body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
            dir = {1, 0};
        }
};

bool ElementInDeque(Vector2 element, std::deque<Vector2> deque){
    for (unsigned int i = 0; i < deque.size(); i++){
        if (Vector2Equals(deque[i], element)){
            return true;
        }
    }
    return false;
}

class Food {
    public:
        Vector2 position;
        Texture2D texture;

        Food(std::deque<Vector2> snakeBody){
            Image image = LoadImage("Graphics/food.png");
            texture = LoadTextureFromImage(image);
            UnloadImage(image);
            position = GenerateRandomPos(snakeBody);
        }

        ~Food(){
            UnloadTexture(texture);
        }

        void Draw(){
            DrawTexture(texture, offset + position.x * cellSize, offset + position.y * cellSize, WHITE);
        }

        Vector2 GenerateRandomCell(){
            float x = GetRandomValue(0, cellCount - 1);
            float y = GetRandomValue(0, cellCount - 1);
            return Vector2{x, y};
        }

        Vector2 GenerateRandomPos(std::deque<Vector2> snakeBody){
            Vector2 position = GenerateRandomCell();
            while (ElementInDeque(position, snakeBody)){
                position = GenerateRandomCell();
            }
            return position;
        }
};