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
        Food food = Food(snake.body);
        bool running = true;

        void Draw(){
            snake.Draw();
            food.Draw();
        }

        void Update(){
            if (running){
                if (eventTriggered(0.2)){
                    snake.Update();
                }
                CheckFoodCollision();
                EdgeCollision();
                BodyCollision();
            }
        }

        void CheckFoodCollision(){
            if (Vector2Equals(snake.body[0], food.position)){
                food.position = food.GenerateRandomPos(snake.body);
                snake.addSegment = true;
            }
        }

        void EdgeCollision(){
            if (snake.body[0].x == cellCount || snake.body[0].x == -1){
                GameOver();
            }
            if (snake.body[0].y == cellCount || snake.body[0].y == -1){
                GameOver();
            }
        }

        void BodyCollision(){
            std::deque<Vector2> headlessBody = snake.body;
            headlessBody.pop_front();

            if (ElementInDeque(snake.body[0], headlessBody)){
                GameOver();
            }
        }

        void GameOver(){
            running = false;
            snake.Reset();
            food.position = food.GenerateRandomPos(snake.body);
        }
};

int main(){

    InitWindow(cellSize * cellCount, cellSize * cellCount, "Snake");
    SetTargetFPS(60);

    Game game;

    while (!WindowShouldClose()){
        BeginDrawing();

        game.Update();

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

        if (IsKeyPressed(GetKeyPressed())) game.running = true;

        ClearBackground(lightGreen);

        game.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}