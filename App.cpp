#include "App.h"

App::App()
	:
	wnd( 800,600,"Olej's engine" )
{}

int App::Go()
{
	while( true )
	{
		// process all messages pending, but to not block for new messages
		if( const auto ecode = Window::ProcessMessages() )
		{
			// if return optional has value, means we're quitting so return exit code
			return *ecode;
		}
		DoFrame();
	}
}

void App::DoFrame()
{
	const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer(c, c, 1.0f);
	for (int i = 0; i < 5; i++) {
		wnd.Gfx().DrawTestTriangle(
			-timer.Peek(),
			-5.0f + float(i)*2.0f,
			0.0f,
			0.5f
		);
	}
	wnd.Gfx().EndFrame();
}