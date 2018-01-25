#include "Physics.h"



Physics::Physics()
{
	acc = 1;
	vel = 1;
}

Physics::~Physics()
{
}

int Physics::GetVel() {
	return vel;
}

void Physics::SetVel(int x) {
	vel = x;
}

int Physics::GetAcc() {
	return acc;
}
void Physics::SetAcc(int x) {
	acc = x;
}

void Physics::inc(int dt)
{
	int temp = (vel * dt + (acc * dt * dt) / 2);
	SetVel(temp);
	vel = temp;
}