#include "Game.h"
#include "Window.h"

Game::Game() :
	isInitialize( false )
{}

Game::~Game()
{}

bool Game::Initialize()
{
	Window::SetTitle( "Minegame" );

	isInitialize = true;
	return true;
}

void Game::Update()
{}
