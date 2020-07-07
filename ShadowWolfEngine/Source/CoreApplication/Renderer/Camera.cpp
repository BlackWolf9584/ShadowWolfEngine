#include "SWpch.h"
#include "CoreApplication/Renderer/Camera.h"

namespace SW
{
	Camera::Camera(const glm::mat4& projectionMatrix)
		: m_ProjectionMatrix(projectionMatrix)
	{
	}
}