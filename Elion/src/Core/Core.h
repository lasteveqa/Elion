#pragma once

#include <memory>
#include <vector>
#include "math_3d.h"
#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#ifdef ELION_PLATFORM_WINDOWS
    #ifdef ELION_BUILD_DLL
         #define ELION_API _declspec(dllexport)
     #else 
         #define ELION_API _declspec(dllimport)
#endif;

#else
    #error Elion only supports Windows!
#endif;

#define ELION_PRE_GAME_LOOP(window) 	SDL_GL_SwapWindow(window.get_window()); \
                                        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
                                

namespace Elion
{
	typedef unsigned int uint;

	template<typename T , typename ... Args>
	constexpr std::shared_ptr<T> create_ref(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}