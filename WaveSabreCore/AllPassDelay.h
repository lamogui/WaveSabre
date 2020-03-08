#pragma once

namespace WaveSabreCore
{
	class AllPassDelay
	{
	public:
		AllPassDelay();

		void Delay(float delay);
		float Update(float inSamp);

	private:
		float a1, zm1;
	};
}

