#include "Player.h"
#include <time.h>
#include <ctime>
Player::Player() :Entity()
{
	/*
	player = CML::CMRectangle(500, 500, 200, 200);
	player.SetImage(CML::ResourceManager::createResource<CML::CMImage>("sample.png"));
	player.SetRotation(0.0f);
	player.SetSize(1.0f);
	player.SetColor(0.0f, 0.0f, 0.0f, 0.0f);
	player.SetOrigon(-100, -100);
	*/
	_shape = CML::CMRectangle(500, 500, 200, 200);
	_shape.SetImage(CML::ResourceManager::createResource<CML::CMImage>("sample.png"));
	_shape.SetRotation(0.0f);
	_shape.SetSize(1.0f);
	_shape.SetColor(0.0f, 0.0f, 0.0f, 0.0f);
	_shape.SetOrigon(100, 100);


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
	Update(0.0f);
	float paskafix[3];
	for (int i = 0; i < 3; i++)
		paskafix[i] = (rand() % 100) / 100.0f;
	_shape.SetColor(0.0f, paskafix[1], 0.0f, 0.0f);
	if (CML::CMInput::isKeyPressed(CML::CMInput::D))
		_shape.SetX(_shape.GetX() + 10);
	if (CML::CMInput::isKeyPressed(CML::CMInput::A))
		_shape.SetX(_shape.GetX() - 10);

	if (CML::CMInput::isKeyPressed(CML::CMInput::W) && HitsGround())
		Jump();
	if (CML::CMInput::isKeyPressed(CML::CMInput::S))
		_shape.SetY(_shape.GetY() - 10);

	if (CML::CMInput::isKeyPressed(CML::CMInput::Space))
		_shape.SetRotation(_shape.GetRotation() + 15);

	if (CML::CMInput::isKeyPressed(CML::CMInput::N))
		_shape.SetSize(_shape.GetWidth() + 0.01);
	if (CML::CMInput::isKeyPressed(CML::CMInput::M))
		_shape.SetSize(_shape.GetWidth() - 0.01);


	cursor.SetX(mx);
	cursor.SetY(my);

	float Dx = _shape.GetX() - mx;
	float Dy = _shape.GetY() - my;

	float DLen = sqrt(Dx*Dx + Dy*Dy);
	Dx /= DLen;
	Dy /= DLen;

	cursor.SetX(_shape.GetX() + Dx*-250);
	cursor.SetY(_shape.GetY() + Dy*-250);

	//std::cout << mx << " " << my << std::endl;
	//std::cout << cursor.GetX() << "  " << cursor.GetY() << std::endl;

}

float Player::GetX()
{
	return _shape.GetX();
}

float Player::GetY()
{
	return _shape.GetY();
}

void Player::SetX(float x)
{
	_shape.SetX(x);
}

void Player::SetY(float y)
{
	_shape.SetY(y);
}

float Player::GetWidth()
{
	return _shape.GetWidth();
}

float Player::GetHeight()
{
	return _shape.GetHeight();
}

void Player::SetWidth(float x)
{
	_shape.SetWidth(x);
}

void Player::SetHeight(float y)
{
	_shape.SetHeight(y);
}

float Player::GetRotation()
{
	return _shape.GetRotation();
}

void Player::SetRotation(float a)
{
	return _shape.SetRotation(a);
}

CML::CMShape *Player::returnPaska(Shapes s)
{
	if (s == CURSOR)
		return &cursor;
	else
		return &_shape;
}