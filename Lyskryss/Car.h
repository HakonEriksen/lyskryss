#pragma once
class Car
{
public:
	Car();
	Car(int, int, bool);
	int getxpos();
	int getypos();
	bool getDir();
	bool passedLight();
	void move();
	~Car();
private:
	int xpos;
	int ypos;
	bool dir; // true for west, false for north
};

