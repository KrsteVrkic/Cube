#include "Player.hpp"

void MovePlayer(Player &player,
                float forward,
                float sideways,
                float deltaTime) {
  const float speed = 5.0f;
  player.position.x += sideways * speed * deltaTime;
  player.position.z += forward * speed * deltaTime;
}
