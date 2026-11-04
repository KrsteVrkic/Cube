#include <raylib.h>
#include "Player.hpp"
#include "input/Input.hpp"

int main() {

  const int screenWidth = 1280;
  const int screenHeight = 720;

  InitWindow(screenWidth,
             screenHeight,
             "Cube Engine");
  Camera3D camera = {0};
  camera.position = {0.0f, 10.0f, 10.0f};
  camera.target = {0.0f, 0.0f, 0.0f};
  camera.up = {0.0f, 1.0f, 0.0f};
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;
  
  Player player;
  player.model = LoadModel("assets/models/test_cube.glb");

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    CubeInput input = ReadInput();
    MovePlayer(player, input.z, input.x, GetFrameTime());

    camera.target = player.position;
    UpdateCamera(&camera, CAMERA_THIRD_PERSON);
    BeginDrawing();
    ClearBackground(RAYWHITE);

    BeginMode3D(camera);
    DrawModel(player.model, player.position, 1.0f, WHITE);
    DrawGrid(20,
             1.0f);
    EndMode3D();

    DrawFPS(10, 10);
    EndDrawing();
  }

  UnloadModel(player.model);
  CloseWindow();
  return 0;
}
