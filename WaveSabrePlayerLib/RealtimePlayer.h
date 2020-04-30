#pragma once
#include "sys_buildfeatures.h"
#ifdef PROUT_WAVESABRE
#include "extern/WaveSabre/WaveSabrePlayerLib/IPlayer.h"
#include "extern/WaveSabre/WaveSabrePlayerLib/SongRenderer.h"
#include "extern/WaveSabre/WaveSabrePlayerLib/DirectSoundRenderThread.h"

namespace WaveSabrePlayerLib
{
	class RealtimePlayer 
	{
	public:
		RealtimePlayer(const SongRenderer::Song *song, int numRenderThreads, int bufferSizeMs = 1000);
		virtual ~RealtimePlayer();

		virtual void Play();
		
		virtual int GetTempo() const;
		virtual int GetSampleRate() const;
		virtual double GetLength() const;
		virtual double GetSongPos() const;

	private:
		static void renderCallback(SongRenderer::Sample *buffer, int numSamples, void *data);

		const SongRenderer::Song *song;
		int numRenderThreads;
		int bufferSizeMs;

		SongRenderer *songRenderer;
		DirectSoundRenderThread *renderThread;
	};
}
#endif // PROUT_WAVESABRE