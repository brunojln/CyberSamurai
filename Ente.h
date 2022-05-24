#pragma once
class Ente
{
protected:
	int id;

public:
	Ente();
	~Ente();
	virtual void run() = 0;
};
