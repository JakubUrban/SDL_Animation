#include "Particle.h"


Particle::Particle() :x(0), y(0), color(0)
{

}

void Particle::SetPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

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
