#include "Player.h"

Player::Player()
{
	player = CML::CMRectangle(500, 500, 200, 200);
	player.SetImage(CML::ResourceManager::createResource<CML::CMImage>("sample.png"));
	player.SetRotation(0.0f);
	player.SetSize(1.0f);
	player.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	player.SetOrigon(400, 400);
}

Player::~Player()
{
}

void Player::playerInputs()
{

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
	return player.GetSize().getX();
}

float Player::GetHeight()
{
	return player.GetSize().getY();
}

void Player::SetSize(float x)
{
	player.SetSize(x);
}

float Player::GetRotation()
{
	return player.GetRotation();
}

void Player::SetRotation(float a)
{
	return player.SetRotation(a);
}

CML::CMRectangle *Player::returnPaska()
{
	return &player;
}