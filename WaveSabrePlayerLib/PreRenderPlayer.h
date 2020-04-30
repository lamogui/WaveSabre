#pragma once


#include "extern/WaveSabre/WaveSabrePlayerLib/IPlayer.h"
#include "extern/WaveSabre/WaveSabrePlayerLib/SongRenderer.h"
#include "extern/WaveSabre/WaveSabrePlayerLib/DirectSoundRenderThread.h"

#ifdef PROUT_WAVESABRE

namespace WaveSabrePlayerLib
{
	class PreRenderPlayer 
	{
	public:
		typedef void (*ProgressCallback)(double progress, void *data);

		PreRenderPlayer(const SongRenderer::Song *song, int numRenderThreads, ProgressCallback callback, void *data, int playbackBufferSizeMs = 100);
		virtual ~PreRenderPlayer();

		virtual void Play();

		virtual int GetTempo() const;
		virtual int GetSampleRate() const;
		virtual double GetLength() const;
		virtual double GetSongPos() const;

	private:
		static void renderCallback(SongRenderer::Sample *buffer, int numSamples, void *data);

		int tempo;
		int sampleRate;
		double length;

		int renderBufferSize;
		SongRenderer::Sample *renderBuffer;

		int playbackBufferSizeMs;
		int playbackBufferIndex;

		DirectSoundRenderThread *renderThread;
	};
}
#endif // PROUT_WAVESABRE
