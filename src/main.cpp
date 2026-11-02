#include <raylib.h>

int main() {

  InitWindow(1280, 720, "Cube Engine");
    Camera3D camera = {0};

  camera.position = {5.0f, 5.0f, 5.0f};
  camera.target = {0.0f, 0.0f, 0.0f};
  camera.up = {0.0f, 1.0f, 0.0f};
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  Model cube = LoadModel("assets/models/test_cube.glb");

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode3D(camera);
    DrawModel(cube, Vector3{0, 0, 0,}, 1.0f, WHITE);
    DrawGrid(20, 1.0f);
    EndMode3D();
    DrawFPS(10, 10);
    EndDrawing();
  }

  UnloadModel(cube);
  CloseWindow();
  return 0;
}
