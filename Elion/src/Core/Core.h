#pragma once
#include "SDL/SDL.h"
#include <memory>
#include <vector>
#include "math_3d.h"


#ifdef ELION_PLATFORM_WINDOWS
    #ifdef ELION_BUILD_DLL
         #define ELION_API _declspec(dllexport)
     #else 
         #define ELION_API _declspec(dllimport)
#endif;

#else
    #error Elion only supports Windows!
#endif;

                                       
#define SCENE_XPOSITION 520
#define SCENE_YPOSITION 100
#define SCENE_WIDTH 1030
#define SCENE_HEIGHT 1000
                                        

                                




namespace Elion
{
	typedef unsigned int uint;
	template<typename T , typename ... Args>
	constexpr std::shared_ptr<T> create_ref(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}