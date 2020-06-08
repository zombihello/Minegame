#pragma once
#include <string>

class Engine
{
public:
	static void		Run();

private:
	static bool		Initialize();
	static void		Destroy();

	static bool		isInitialize;
};

