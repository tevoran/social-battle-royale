#ifndef GAME_HPP
#define GAME_HPP

#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <vector>

//world
#define TILE_X 0.05625
#define TILE_Y 0.1
#define WORLD_SIZE_X 25
#define WORLD_SIZE_Y 25
#define SEA_COLOR 0.179, 0.498, 0.543

#define NON_BLOCKED 0

//player
#define PLAYER_SCREEN_POS_X 0.45
#define PLAYER_SCREEN_POS_Y 0.45
#define PLAYER_SPEED 0.2

//npcs
#define NUM_NPCS 4
#include "player.hpp"
#include "world.hpp"
#include "npc.hpp"

#endif