#pragma once

#include<stdlib.h>

class Particle
{
private:
	double x;
	double y;
	double x_speed;
	double y_speed;
	unsigned int color;

public:
	Particle();
	Particle(double x, double y);
	
public:
	double GetPositionX();
	double GetPositionY();
	void SetPosition(int x, int y);

	unsigned int GetColor();
	void SetColor(unsigned char Red, unsigned char Green, unsigned char Blue);

	void Update(int t);
};

