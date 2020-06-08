#pragma once
#include <string>

class GLFWwindow;

class Window
{
public:
	static bool		Initialize( const std::string& Title, int Width, int Height );
	static void		Destroy();
	static void		Close();
	static void		PollEvents();

	static void		SetTitle( const std::string& Title );

	static bool		IsOpen();
	static void		SwapBuffers();

private:
	static GLFWwindow*		handle;
};

