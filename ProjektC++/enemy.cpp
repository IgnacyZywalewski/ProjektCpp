#include <SDL.h>

#include "enemy.h"

Enemy::Enemy(SDL_Renderer* renderer, float x, float y, int w, int h, float moveSpeed) {
    this->renderer = renderer;

    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    this->speed = moveSpeed;
}

Enemy::~Enemy() {}

void Enemy::draw() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_Rect sdlRect = { static_cast<int>(rect.x), static_cast<int>(rect.y), rect.w, rect.h };
    SDL_RenderFillRect(renderer, &sdlRect);
}

void Enemy::updateEnemyPosition(float playerX, float playerY) {
    float dx = playerX - rect.x;
    float dy = playerY - rect.y;

    float length = sqrt(dx * dx + dy * dy);

    dx /= length;
    dy /= length;

    rect.x += dx * speed;
    rect.y += dy * speed;
}

void Enemy::clearEnemy(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect sdlRect = { static_cast<int>(rect.x), static_cast<int>(rect.y), rect.w, rect.h };
    SDL_RenderFillRect(renderer, &sdlRect);
}
