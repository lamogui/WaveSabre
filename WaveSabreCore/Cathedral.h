#pragma once 

#include "extern/WaveSabre/WaveSabreCore/Device.h"
#include "extern/WaveSabre/WaveSabreCore/DelayBuffer.h"
#include "extern/WaveSabre/WaveSabreCore/StateVariableFilter.h"
#include "extern/WaveSabre/WaveSabreCore/Comb.h"
#include "extern/WaveSabre/WaveSabreCore/AllPass.h"

namespace WaveSabreCore
{
	class Cathedral : public Device
	{
	public:
		enum class ParamIndices
		{
			Freeze,
			RoomSize,
			Damp,
			Width,

			LowCutFreq,
			HighCutFreq,

			DryWet,

			PreDelay,

			NumParams,
		};

		Cathedral();
		virtual ~Cathedral();

		virtual void Run(double songPosition, float **inputs, float **outputs, int numSamples);

		virtual void SetParam(int index, float value);
		virtual float GetParam(int index) const;

	private:
		static const int numCombs = 8;
		static const int numAllPasses = 4;
		float gain;
		float roomSize, roomSize1;
		float damp, damp1;
		float width;
		float lowCutFreq, highCutFreq;
		float dryWet;
		float wet1, wet2;
		bool freeze;
		float preDelay;

		void UpdateParams();

		StateVariableFilter lowCutFilter[2], highCutFilter[2];

		Comb combLeft[numCombs];
		Comb combRight[numCombs];

		AllPass	allPassLeft[numAllPasses];
		AllPass	allPassRight[numAllPasses];

		DelayBuffer preDelayBuffer;
	};
}
