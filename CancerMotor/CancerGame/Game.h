#pragma once

#include "CMWindow.h"
#include "glew.h"
#include "ResourceManager.h"
#include "glm\glm.hpp"
#include "CMSprite.h"
#include <string>
#include <iostream>
#include "RenderingContext.h"
#include "GraphicContext.h"
#include "CMShape.h"
#include "CMRectangle.h"
#include "CMCircle.h"
#include <stdlib.h> 
#include <time.h>
#include "CMVector2.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtx\transform.hpp"
#include "CMInput.h"
#include <Collision.h>
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"
#include "Pickup.h"
class Game
{
public:
	enum GameState { MainMenu, Play };

	Game();
	~Game();
private:
	CML::GraphicContext gcontext;
	CML::RenderingContext rContext;
	std::vector <Projectile*> ProjectileList;
	std::vector <Enemy*> EnemyList;
};

