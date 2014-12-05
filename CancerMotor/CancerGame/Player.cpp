#include "Player.h"
#include <time.h>
#include <ctime>
Player::Player()
{
	
	player = CML::CMRectangle(500, 500, 200, 200);
	player.SetImage(CML::ResourceManager::createResource<CML::CMImage>("sample.png"));
	player.SetRotation(0.0f);
	player.SetSize(1.0f);
	player.SetColor(0.0f, 0.0f, 0.0f, 0.0f);
	player.SetOrigon(-100, -100);



	cursor = CML::CMCircle(500, 500, 75, 360 / 6);
	cursor.SetImage(CML::ResourceManager::createResource<CML::CMImage>("sample.png"));
	cursor.SetRotation(0.0f);
	cursor.SetSize(1.0f);
	cursor.SetColor(0.0f, 0.0f, 0.0f, 0.0f);
	srand(time(NULL));
}

Player::~Player()
{
}

void Player::playerInputs(float mx, float my)
{
	//player.SetColor((rand() % 100) / 100.0f, (rand() % 100) / 100.0f, (rand() % 100) / 100.0f, 0.0f);

	float paskafix[3];
	for (int i = 0; i < 3; i++)
		paskafix[i] = (rand() % 100) / 100.0f;
	std::cout << paskafix[0] << paskafix[1] << paskafix[2] << std::endl;
	player.SetColor(0.0f,paskafix[1],0.0f, 0.0f);
	if (CML::CMInput::isKeyPressed(CML::CMInput::Right))
		player.SetX(player.GetX() + 10);
	if (CML::CMInput::isKeyPressed(CML::CMInput::Left))
		player.SetX(player.GetX() - 10);

	if (CML::CMInput::isKeyPressed(CML::CMInput::Up))
		player.SetY(player.GetY() + 10);
	if (CML::CMInput::isKeyPressed(CML::CMInput::Down))
		player.SetY(player.GetY() - 10);

	if (CML::CMInput::isKeyPressed(CML::CMInput::Space))
		player.SetRotation(player.GetRotation() + 15);

	if (CML::CMInput::isKeyPressed(CML::CMInput::N))
		player.SetSize(player.GetWidth() + 0.01);
	if (CML::CMInput::isKeyPressed(CML::CMInput::M))
		player.SetSize(player.GetWidth() - 0.01);

	if (player.GetY() >!5 && !CML::CMInput::isKeyPressed(CML::CMInput::Up))
	player.SetY(player.GetY() - 5);

	cursor.SetX(mx);
	cursor.SetY(my);

	float Dx = player.GetX() - mx;
	float Dy = player.GetY() - my;

	float DLen = sqrt(Dx*Dx + Dy*Dy);
	Dx /= DLen;
	Dy /= DLen;

	cursor.SetX(player.GetX() + Dx*-250);
	cursor.SetY(player.GetY() + Dy*-250);

	//std::cout << mx << " " << my << std::endl;
	//std::cout << cursor.GetX() << "  " << cursor.GetY() << std::endl;

}

float Player::GetX()
{
	return player.GetX();
}

float Player::GetY()
{
	return player.GetY();
}

void Player::SetX(float x)
{
	player.SetX(x);
}

void Player::SetY(float y)
{
	player.SetY(y);
}

float Player::GetWidth()
{
	return player.GetWidth();
}

float Player::GetHeight()
{
	return player.GetHeight();
}

void Player::SetWidth(float x)
{
	player.SetWidth(x);
}

void Player::SetHeight(float y)
{
	player.SetHeight(y);
}

float Player::GetRotation()
{
	return player.GetRotation();
}

void Player::SetRotation(float a)
{
	return player.SetRotation(a);
}

CML::CMShape *Player::returnPaska(Shapes s)
{
	if (s == CURSOR)
		return &cursor;
	else
		return &player;
}