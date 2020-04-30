#pragma once

#include "sys_buildfeatures.h"
#ifdef PROUT_WAVESABRE

namespace WaveSabreCore
{
	class Comb
	{
	public:
		Comb();
		virtual ~Comb();

		void SetBufferSize(int size);
		float Process(float inp);
		void SetDamp(float val);
		float GetDamp();
		void SetFeedback(float val);
		float GetFeedback();

	private:
		float feedback, filterStore;
		float damp1, damp2;
		float *buffer;
		int bufferSize, bufferIndex;
	};
}

#endif // PROUT_WAVESABRE