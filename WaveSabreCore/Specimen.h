#pragma once

#include "sys_buildfeatures.h"
#ifdef PROUT_WAVESABRE

#include "platforms/win32/sys_win32.h"
#include <mmreg.h>
#ifdef UNICODE
	#define _UNICODE
#endif
typedef DWORD	FOURCC;
#include <MSAcm.h>

#include "extern/WaveSabre/WaveSabreCore/SynthDevice.h"
#include "extern/WaveSabre/WaveSabreCore/Envelope.h"
#include "extern/WaveSabre/WaveSabreCore/StateVariableFilter.h"
#include "extern/WaveSabre/WaveSabreCore/SamplePlayer.h"



namespace WaveSabreCore
{
	class Specimen : public SynthDevice
	{
	public:
		enum class ParamIndices
		{
			AmpAttack,
			AmpDecay,
			AmpSustain,
			AmpRelease,

			SampleStart,
			LoopMode,
			LoopStart,
			LoopLength,
			Reverse,

			InterpolationMode,

			CoarseTune,
			FineTune,

			FilterType,
			FilterFreq,
			FilterResonance,
			FilterModAmt,

			ModAttack,
			ModDecay,
			ModSustain,
			ModRelease,

			VoicesUnisono,
			VoicesDetune,
			VoicesPan,

			Master,

			VoiceMode,
			SlideTime,

			NumParams,
		};

		static const int SampleRate = 44100;

		Specimen();
		virtual ~Specimen();

		virtual void SetParam(int index, float value);
		virtual float GetParam(int index) const;

		virtual void SetChunk(void *data, int size);
		virtual int GetChunk(void **data);

		void LoadSample(char *data, int compressedSize, int uncompressedSize, WAVEFORMATEX *waveFormat);

	private:
		class SpecimenVoice : public Voice
		{
		public:
			SpecimenVoice(Specimen *thunder);
			virtual WaveSabreCore::SynthDevice *SynthDevice() const;

			virtual void Run(double songPosition, float **outputs, int numSamples);

			virtual void NoteOn(int note, int velocity, float detune, float pan);
			virtual void NoteOff();

		private:
			double coarseDetune(float detune);
			void calcPitch();

			Specimen *specimen;

			Envelope ampEnv, modEnv;

			SamplePlayer samplePlayer;

			StateVariableFilter filter;

			float velocity;
		};

		static BOOL __stdcall driverEnumCallback(HACMDRIVERID driverId, DWORD_PTR dwInstance, DWORD fdwSupport);
		static BOOL __stdcall formatEnumCallback(HACMDRIVERID driverId, LPACMFORMATDETAILS formatDetails, DWORD_PTR dwInstance, DWORD fdwSupport);

		static HACMDRIVERID driverId;

		char *chunkData;

		char *waveFormatData;
		int compressedSize, uncompressedSize;

		char *compressedData;
		float *sampleData;

		float ampAttack, ampDecay, ampSustain, ampRelease;
		float sampleStart;
		bool reverse;
		LoopMode loopMode;
		LoopBoundaryMode loopBoundaryMode;
		float loopStart, loopLength;

		InterpolationMode interpolationMode;

		int sampleLength;
		int sampleLoopStart, sampleLoopLength;
		float coarseTune, fineTune;
		float masterLevel;
		StateVariableFilterType filterType;
		float filterFreq, filterResonance, filterModAmt;
		float modAttack, modDecay, modSustain, modRelease;
	};
}
#endif // PROUT_WAVESABRE