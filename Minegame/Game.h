#pragma once

class Game
{
public:
	Game();
	~Game();

	bool		Initialize();
	void		Update();

private:
	bool		isInitialize;
};

