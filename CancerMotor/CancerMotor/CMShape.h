#pragma once
class CMShape
{
public:
	typedef float vec4[4];

	CMShape(float x, float y);
	CMShape();
	~CMShape();

	void SetX(float x);
	float GetX();

	void SetY(float y);
	float GetY();

	void SetRotation(int a);
	int GetRotation();

	void SetColor(vec4 color);
	void SetColor(float r, float b, float g, float a);

	float GetColorR();
	float GetColorG();
	float GetColorB();
	float GetColorA();

	void SetSize(float s);
	float GetSize();

	void SetOrigon(float x, float y);
	float GetOrigon();

protected:
	float _x, _y, _origon, 
	_size;
	int _rotation;
	vec4 _colorRGBA;
};