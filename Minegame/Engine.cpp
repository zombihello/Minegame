#include <stdexcept>
#include <iostream>
#include <GL/glew.h>

#include "Window.h"
#include "Engine.h"
#include "Game.h"

bool		Engine::isInitialize = false;

bool Engine::Initialize()
{
	try
	{
		if ( isInitialize ) return true;
		if ( !Window::Initialize( "MineEngine by zombiHello", 800, 600 ) )
			throw std::runtime_error( "Failed initialize subsystem \"Window\"" );

		isInitialize = true;
		return true;
	}
	catch ( std::exception& Exception )
	{
		std::cerr << Exception.what();
		return false;
	}
}

void Engine::Destroy()
{
	if ( !isInitialize ) return;
	Window::Destroy();
}

void Engine::Run()
{
	if ( !Initialize() )		return;

	Game*			game = new Game();
	if ( !game->Initialize() )	return;

	glClearColor( 1, 0, 0, 1 );

	while ( Window::IsOpen() )
	{
		glClear( GL_COLOR_BUFFER_BIT );

		Window::PollEvents();
		game->Update();
		Window::SwapBuffers();
	}

	delete game;
	Engine::Destroy();
}
