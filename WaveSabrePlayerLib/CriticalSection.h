#pragma once

#include "sys_builddefines.h"
#ifdef PROUT_WIN32
	#include "platforms/win32/sys_win32.h"
#endif 

namespace WaveSabrePlayerLib
{
	class CriticalSection
	{
	public:
		class CriticalSectionGuard
		{
		public:
			CriticalSectionGuard(CriticalSection *criticalSection);
			~CriticalSectionGuard();

		private:
			CriticalSection *criticalSection;
		};

		CriticalSection();
		~CriticalSection();

		CriticalSectionGuard Enter();

	private:
		CRITICAL_SECTION criticalSection;
	};
}


