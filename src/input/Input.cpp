#include "Input.hpp"
#include <raylib.h>

CubeInput ReadInput() {
  return {
      .x = float(IsKeyDown(KEY_D)) - float(IsKeyDown(KEY_A)),
      .z = float(IsKeyDown(KEY_S)) - float(IsKeyDown(KEY_W)),
  };
}
