#pragma once
#include <raylib.h>

struct Player {
  Model model{};
  Vector3 position{0.0f, 0.0f, 0.0f};
  float yaw = 0.0f;

};

void MovePlayer(Player& player, float forward, float sideways, float deltaTime);
