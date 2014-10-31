#pragma once
class CMShape
{
public:
	CMShape();
	~CMShape();

	void SetX(float x);
	float GetX();

	void SetY(float y);
	float GetY();

	void SetRotation(float a);
	float GetRotation();

	void SetColor(float color);
	float GetColor();

	void SetSize(int s);
	int GetSize();

	void SetOrigon(float x, float y);
	float GetOrigon();

private:
	float _x, _y, _rotation, _origon, _color;
	int _size;
};