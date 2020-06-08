#include <stdexcept>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Window.h"

GLFWwindow*			Window::handle = nullptr;

bool Window::Initialize( const std::string& Title, int Width, int Height )
{
	try
	{
		if ( handle ) return true;

		// Initialize GLFW
		if ( !glfwInit() )		throw std::runtime_error( "Failed init GLFW" );

		// Set context render settings and window
		glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
		glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
		glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

		// Create window
		handle = glfwCreateWindow( Width, Height, Title.c_str(), nullptr, nullptr );
		if ( !handle )				throw std::runtime_error( "Failed creating window" );

		// Make current context opengl
		glfwMakeContextCurrent( handle );

		// Initialize opengl
		glewExperimental = true;
		if ( glewInit() != GLEW_OK )		throw std::runtime_error( "Failed init GLEW" );

		return true;
	}
	catch ( const std::exception& Exception )
	{
		std::cerr << Exception.what();
		return false;
	}
}

void Window::Destroy()
{
	if ( !handle )	return;
	glfwTerminate();
	handle = nullptr;
}

void Window::Close()
{
	if ( !handle )	return;	
	glfwSetWindowShouldClose( handle, true );
}

void Window::PollEvents()
{
	glfwPollEvents();
}

void Window::SetTitle( const std::string& Title )
{
	if ( !handle )		return;
	glfwSetWindowTitle( handle, Title.c_str() );
}

bool Window::IsOpen()
{
	if ( !handle )		return false;
	return !glfwWindowShouldClose( handle );
}

void Window::SwapBuffers()
{
	if ( !handle )		return;
	glfwSwapBuffers( handle );
}
