#pragma once

#include "sys_buildfeatures.h"
#ifdef PROUT_WAVESABRE

namespace WaveSabreCore
{
	class AllPass
	{
	public:
		AllPass();
		virtual ~AllPass();

		void SetBufferSize(int size); 
		float Process(float inp);
		void SetFeedback(float val);
		float GetFeedback();

	private:
		float feedback;
		float *buffer;
		int bufferSize;
		int bufferIndex;
	};
}


#endif // PROUT_WAVESABRE