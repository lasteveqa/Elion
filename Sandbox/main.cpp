#include <Elion.h>
#include "SDL.h"
#include "Menu_Layer.h"
#include <functional>
class test {
public:
	std::function<void()> f = std::bind(&test::hello, this);
	void hello()
	{
		std::cout << "Hello World" << std::endl;
	}
};




 int main(int argc, char* argv[])
{
	
	 
	 test s;
	
	 
	Elion::Application app;
 
	Elion::Window window(Elion::WindowProperties("Elion Engine", 1280, 720));

	Elion::Event e;
	
	Elion::LayerState state;
	state.set_layer(new Menu_Layer());

	

	while (app.is_running())
	{
		ELION_PRE_GAME_LOOP(window);
	

		while (SDL_PollEvent(&e.event()))
		{
			switch (e.event().type)
			{
			case SDL_QUIT:
				app.set_running(false);
				break;
			case SDL_KEYDOWN:
				
				e.set_key_pressed_event(Elion::KeyPressedEvent(SDLK_f), false, s.f);
	
			break;

			case SDL_KEYUP:
				
				break;
			}
			
		}
		state.render();
		
		

		app.Run();
		
	
	}
	
	

	return 0;
}