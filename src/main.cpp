#include <raylib.h>
#include <cmath>

#include "input/Input.hpp"

int main() {

  const int screenWidth = 1280;
  const int screenHeight = 720;
  
  InitWindow(screenWidth, screenHeight, "Cube Engine");

  Camera3D camera = {0};
  camera.position = {0.0f, 10.0f, 10.0f};
  camera.target = {0.0f, 0.0f, 0.0f};
  camera.up = {0.0f, 1.0f, 0.0f};
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  Vector3 cubePosition{0.0f, 0.0f, 0.0f};

  SetTargetFPS(60);

  Model cube = LoadModel("assets/models/test_cube.glb");

  while (!WindowShouldClose()) {
    CubeInput input = ReadInput();
    float speed = 5.0f * GetFrameTime();

    cubePosition.x += input.x * speed;
    cubePosition.z += input.z * speed;

    camera.target = cubePosition;
    UpdateCamera(&camera, CAMERA_THIRD_PERSON);

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
