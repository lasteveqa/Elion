#pragma once
#ifndef __SCENECAMERA_H__
#define __SCENECAMERA_H__
#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/compatibility.hpp"

namespace Elion
{


	class SceneCamera
	{
	private:

		glm::mat4 m_CameraView;

	public:

		SceneCamera(glm::vec3 pos, glm::vec3 view, glm::vec3 up);
		~SceneCamera() {}

		glm::mat4 get_camera_view()
		{
			return this->m_CameraView;
		}
	};

}

#endif;