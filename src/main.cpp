#include <raylib.h>

int main() {

  InitWindow(1920, 1080, "Cube Engine");
    Camera3D camera = {0};

  camera.position = {5.0f, 5.0f, 5.0f};
  camera.target = {0.0f, 0.0f, 0.0f};
  camera.up = {0.0f, 1.0f, 0.0f};
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  Model cube = LoadModel("assets/models/test_cube.glb");
  RenderTexture2D target = LoadRenderTexture(640, 360);

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginTextureMode(target);
    ClearBackground(RAYWHITE);
    
    BeginMode3D(camera);
    DrawModel(cube, Vector3{0, 0, 0,}, 1.0f, WHITE);
    DrawGrid(20, 1.0f);
    EndMode3D();

    EndTextureMode();
    
    DrawFPS(10, 10);

    BeginDrawing();
    ClearBackground(BLACK);

    DrawTexturePro(target.texture,
                   Rectangle{0, 0, 640, -360},
                   Rectangle{0, 0, 1280, 720},
                   Vector2{0, 0}, 0.0f,
                   WHITE
		  );
    EndDrawing();
  }

  UnloadModel(cube);
  UnloadRenderTexture(target);
  CloseWindow();
  return 0;
}
