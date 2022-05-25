#pragma once
class Ente
{
protected:
	int id;

public:
	Ente(int ID = 0) { id = ID; }
	~Ente(){}
	//virtual void run() = 0;
};
