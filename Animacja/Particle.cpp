#include "Particle.h"


Particle::Particle() :x(0), y(0),color(0xffffffff)
{
	speed = (double)rand() / RAND_MAX * 0.1;
	
	direction = ((double)rand() / RAND_MAX) * 2 * PI;
}

Particle::Particle(double x, double y)
{
	this->x = x;
	this->y = y;
}


double Particle::GetPositionX() { return x; }
double Particle::GetPositionY() { return y; }

void Particle::SetPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

unsigned int Particle::GetColor() { return color; }

void Particle::SetColor(unsigned char Red, unsigned char Green, unsigned char Blue)
{
	color += Red;
	color <<= 8;

	color += Green;
	color <<= 8;

	color += Blue;
	color <<= 8;

	color += 0xff;
}

void Particle::Update(int time)
{
	x += cos(direction)*speed*time;
	y += sin(direction)*speed*time;
}