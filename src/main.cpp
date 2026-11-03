#include <raylib.h>
#include "input/Input.hpp"

int main() {
  
  InitWindow(1280, 720, "Cube Engine");
  SetTargetFPS(60);

  Camera3D camera = {0};

  camera.position = {5.0f, 5.0f, 5.0f};
  camera.target = {0.0f, 0.0f, 0.0f};
  camera.up = {0.0f, 1.0f, 0.0f};
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  Model cube = LoadModel("assets/models/test_cube.glb");

  Vector3 cubePosition{0.0f, 0.0f, 0.0f};

  while (!WindowShouldClose()) {
    CubeInput input = ReadInput();
    float speed = 5.0f * GetFrameTime();

    cubePosition.x += input.x * speed;
    cubePosition.z += input.z * speed;

    BeginDrawing();
    ClearBackground(RAYWHITE);

    BeginMode3D(camera);
    DrawModel(cube, cubePosition, 1.0f, WHITE);
    DrawGrid(20, 1.0f);
    EndMode3D();

    DrawFPS(10, 10);
    EndDrawing();
  }

  UnloadModel(cube);
  CloseWindow();
  return 0;
}
