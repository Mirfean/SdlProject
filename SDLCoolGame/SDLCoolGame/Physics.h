#pragma once
class Physics
{
public:
	Physics();
	~Physics();
	
	int GetVel();
	void SetVel(int x);

	int GetAcc();
	void SetAcc(int x);

	void inc(int dt);

private:
	int vel;	//Velocity
	int acc;	//Acceleration

};

