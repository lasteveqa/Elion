#include "Scene/SceneCamera.h"


namespace Elion
{
	SceneCamera::SceneCamera(glm::vec3 pos, glm::vec3 view, glm::vec3 up)
	{
		this->m_CameraView = glm::lookAt(glm::vec3(pos),
			glm::vec3(view),
			glm::vec3(up));
	}
}