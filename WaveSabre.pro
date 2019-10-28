TEMPLATE = lib
CONFIG += staticlib stl_off rtti_off

DESTDIR = $$_PRO_FILE_PWD_/../lib/


HEADERS += \
  WaveSabreCore.h \
  WaveSabreCore/Adultery.h \
  WaveSabreCore/AllPass.h \
  WaveSabreCore/AllPassDelay.h \
  WaveSabreCore/BiquadFilter.h \
  WaveSabreCore/Cathedral.h \
  WaveSabreCore/Chamber.h \
  WaveSabreCore/Comb.h \
  WaveSabreCore/Crusher.h \
  WaveSabreCore/DelayBuffer.h \
  WaveSabreCore/Device.h \
  WaveSabreCore/Echo.h \
  WaveSabreCore/Envelope.h \
  WaveSabreCore/Falcon.h \
  WaveSabreCore/GmDls.h \
  WaveSabreCore/Helpers.h \
  WaveSabreCore/Leveller.h \
  WaveSabreCore/MxcsrFlagGuard.h \
  WaveSabreCore/ResampleBuffer.h \
  WaveSabreCore/SamplePlayer.h \
  WaveSabreCore/Scissor.h \
  WaveSabreCore/Slaughter.h \
  WaveSabreCore/Smasher.h \
  WaveSabreCore/Specimen.h \
  WaveSabreCore/StateVariableFilter.h \
  WaveSabreCore/SynthDevice.h \
  WaveSabreCore/Thunder.h \
  WaveSabreCore/Twister.h \
  WaveSabrePlayerLib.h \
  WaveSabrePlayerLib/CriticalSection.h \
  WaveSabrePlayerLib/PreRenderPlayer.h \
  WaveSabrePlayerLib/WavWriter.h \
  WaveSabrePlayerLib/DirectSoundRenderThread.h \
  WaveSabrePlayerLib/RealtimePlayer.h \
  WaveSabrePlayerLib/IPlayer.h \
  WaveSabrePlayerLib/SongRenderer.h

SOURCES += \
  WaveSabreCore/Adultery.cpp \
  WaveSabreCore/AllPass.cpp \
  WaveSabreCore/AllPassDelay.cpp \
  WaveSabreCore/BiquadFilter.cpp \
  WaveSabreCore/Cathedral.cpp \
  WaveSabreCore/Chamber.cpp \
  WaveSabreCore/Comb.cpp \
  WaveSabreCore/Crusher.cpp \
  WaveSabreCore/DelayBuffer.cpp \
  WaveSabreCore/Device.cpp \
  WaveSabreCore/Echo.cpp \
  WaveSabreCore/Envelope.cpp \
  WaveSabreCore/Falcon.cpp \
  WaveSabreCore/GmDls.cpp \
  WaveSabreCore/Helpers.cpp \
  WaveSabreCore/Leveller.cpp \
  WaveSabreCore/MxcsrFlagGuard.cpp \
  WaveSabreCore/ResampleBuffer.cpp \
  WaveSabreCore/SamplePlayer.cpp \
  WaveSabreCore/Scissor.cpp \
  WaveSabreCore/Slaughter.cpp \
  WaveSabreCore/Smasher.cpp \
  WaveSabreCore/Specimen.cpp \
  WaveSabreCore/StateVariableFilter.cpp \
  WaveSabreCore/SynthDevice.cpp \
  WaveSabreCore/Thunder.cpp \
  WaveSabreCore/Twister.cpp \
  WaveSabrePlayerLib/CriticalSection.cpp \
  WaveSabrePlayerLib/DirectSoundRenderThread.cpp \
  WaveSabrePlayerLib/IPlayer.cpp \
  WaveSabrePlayerLib/PreRenderPlayer.cpp \
  WaveSabrePlayerLib/RealtimePlayer.cpp \
  WaveSabrePlayerLib/SongRenderer.cpp \
  WaveSabrePlayerLib/SongRenderer.Track.cpp \
  WaveSabrePlayerLib/WavWriter.cpp
