#ifndef GAME_HPP
#define GAME_HPP

#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <iostream>
#include <string>



#define GAME_NAME "Dracula's Party"


//world
#define TILE_X 0.05625
#define TILE_Y 0.1
#define WORLD_SIZE_X 15
#define WORLD_SIZE_Y 15
#define SEA_COLOR 0.179, 0.498, 0.543

#define NON_BLOCKED 0
#define BLOCKED 1

//player
#define PLAYER_SCREEN_POS_X 0.45
#define PLAYER_SCREEN_POS_Y 0.45
#define PLAYER_SPEED 0.2
#define PLAYER_INTRO_X 0.2
#define PLAYER_INTRO_Y 0.2
#define PLAYER_INTRO_SIZE_X 0.6
#define PLAYER_INTRO_SIZE_Y 0.6

//npcs
#define NUM_NPCS 9
#define NPC_MALE 0
#define NPC_FEMALE 1

//conversations
#define CONVO_SIZE_X 1.0
#define CONVO_SIZE_Y 0.25
#define CONVO_END_RADIUS 0.15
#define CONVO_TEXT_SIZE_Y 0.05
#define CONVO_LETTER_SIZE 0.01
#define CONVO_TEXT_LEFT 0.03
#define TEXT_COLOR 0.404, 0.17, 0.081


#include "player.hpp"
#include "world.hpp"
#include "conversation.hpp"
#include "npc.hpp"

#endif