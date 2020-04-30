#pragma once

#include "SongRenderer.h"
#ifdef PROUT_WAVESABRE

#include "system/sys_mutex.hpp"
#include "platforms/win32/sys_win32.h"

#include <dsound.h>

namespace WaveSabrePlayerLib
{
	class DirectSoundRenderThread
	{
	public:
		typedef void (*RenderCallback)(SongRenderer::Sample *buffer, int numSamples, void *data);

		DirectSoundRenderThread(RenderCallback callback, void *callbackData, int sampleRate, int bufferSizeMs = 1000);
		~DirectSoundRenderThread();

		int GetPlayPositionMs();

	private:
		static DWORD WINAPI threadProc(LPVOID lpParameter);

		RenderCallback callback;
		void *callbackData;
		int sampleRate;
		int bufferSizeMs;
		int bufferSizeBytes;

		HANDLE thread;
		pMutex criticalSection;
		pMutex playPositionCriticalSection;
		bool shutdown;

		int oldPlayCursorPos;
		long long bytesRendered;
		LPDIRECTSOUNDBUFFER buffer;
	};
}

#endif // PROUT_WAVESABRE