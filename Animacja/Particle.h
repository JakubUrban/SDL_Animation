#pragma once

#include<stdlib.h>
#include<math.h>

class Particle
{
private:
	double x;
	double y;
	double speed;
	unsigned int color;
	double direction;
	const double PI = 3.1415926535;

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

