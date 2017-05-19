#pragma once



class Particle
{
private:
	int x;
	int y;
	unsigned int color;

private:
	void SetPosition(int x, int y);
	void SetColor(unsigned char Red, unsigned char Green, unsigned char Blue);

public:
	Particle();

	void Update();
};

