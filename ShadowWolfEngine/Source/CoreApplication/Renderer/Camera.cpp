#include "SWpch.h"
#include "Camera.h"

namespace Wolf
{

	Camera::Camera(const glm::mat4& projectionMatrix)
		: m_ProjectionMatrix(projectionMatrix)
	{
	}

}