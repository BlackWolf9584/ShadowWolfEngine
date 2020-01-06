#pragma once

namespace SW
{
	class TimeStep
	{
	public:
		TimeStep() {}
		TimeStep(float time);

		inline float GetSeconds() const { return m_Time; }
		inline float GetMilliseconds() const { return m_Time * 1000.0f; }

	private:
		float m_Time = 0.0f;
	};
}