#pragma once

#include "extern/WaveSabre/WaveSabreCore/Device.h"
#include "extern/WaveSabre/WaveSabreCore/DelayBuffer.h"
#include "extern/WaveSabre/WaveSabreCore/StateVariableFilter.h"

namespace WaveSabreCore
{
	class Chamber : public Device
	{
	public:
		enum class ParamIndices
		{
			Mode,

			Feedback,

			LowCutFreq,
			HighCutFreq,

			DryWet,

			PreDelay,

			NumParams,
		};

		Chamber();
		virtual ~Chamber();

		virtual void Run(double songPosition, float **inputs, float **outputs, int numSamples);

		virtual void SetParam(int index, float value);
		virtual float GetParam(int index) const;

	private:
		static const int numBuffers = 8;

		int mode;
		float lowCutFreq, highCutFreq;
		float feedback;
		float dryWet;
		float preDelay;

		DelayBuffer *delayBuffers[numBuffers];

		DelayBuffer preDelayBuffers[2];

		StateVariableFilter lowCutFilter[2], highCutFilter[2];
	};
}

