#include "Particle.h"


Particle::Particle() :x(0), y(0),color(0xffffffff)
{
	x_speed = (rand() - (RAND_MAX / 2))*0.00001;
	y_speed = (rand() - (RAND_MAX / 2))*0.00001;
}

Particle::Particle(double x, double y)
{
	this->x = x;
	this->y = y;

	x_speed = (rand() - (RAND_MAX / 2))*0.00001;
	y_speed = (rand() - (RAND_MAX / 2))*0.00001;
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
	x += (time * x_speed);

	y += (time * y_speed);

	if (x >= 800 || x <= 0) { x_speed = (rand() - (RAND_MAX / 2))*0.00001; };
	if (y >= 600 || y <= 0) { y_speed = (rand() - (RAND_MAX / 2))*0.00001; };

}