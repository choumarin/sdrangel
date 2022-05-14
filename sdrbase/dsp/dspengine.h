///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2015 F4EXB                                                      //
// written by Edouard Griffiths                                                  //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
// (at your option) any later version.                                           //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#ifndef INCLUDE_DSPENGINE_H
#define INCLUDE_DSPENGINE_H

#include <QObject>
#include <QTimer>
#include <vector>

#include "audio/audiodevicemanager.h"
#include "audio/audiooutputdevice.h"
#include "export.h"
#include "ambe/ambeengine.h"

class DSPDeviceSourceEngine;
class DSPDeviceSinkEngine;
class DSPDeviceMIMOEngine;
class FFTFactory;

class SDRBASE_API DSPEngine : public QObject {
	Q_OBJECT
public:
	DSPEngine();
	~DSPEngine();

	static DSPEngine *instance();

	unsigned int getDefaultAudioSampleRate() const { return AudioDeviceManager::m_defaultAudioSampleRate; }

	DSPDeviceSourceEngine *addDeviceSourceEngine();
	void removeLastDeviceSourceEngine();

	DSPDeviceSinkEngine *addDeviceSinkEngine();
	void removeLastDeviceSinkEngine();

	DSPDeviceMIMOEngine *addDeviceMIMOEngine();
	void removeLastDeviceMIMOEngine();

    void removeDeviceEngineAt(int deviceIndex);

	AudioDeviceManager *getAudioDeviceManager() { return &m_audioDeviceManager; }
	AMBEEngine *getAMBEEngine() { return &m_ambeEngine; }

    uint32_t getDeviceSourceEnginesNumber() const { return m_deviceSourceEngines.size(); }
    DSPDeviceSourceEngine *getDeviceSourceEngineByIndex(unsigned int deviceIndex) { return m_deviceSourceEngines[deviceIndex]; }

    uint32_t getDeviceSinkEnginesNumber() const { return m_deviceSinkEngines.size(); }
    DSPDeviceSinkEngine *getDeviceSinkEngineByIndex(unsigned int deviceIndex) { return m_deviceSinkEngines[deviceIndex]; }

    uint32_t getDeviceMIMOEnginesNumber() const { return m_deviceMIMOEngines.size(); }
    DSPDeviceMIMOEngine *getDeviceMIMOEngineByIndex(unsigned int deviceIndex) { return m_deviceMIMOEngines[deviceIndex]; }

	// Serial DV methods:

	bool hasDVSerialSupport();
	void setDVSerialSupport(bool support);
	void getDVSerialNames(std::vector<std::string>& deviceNames);
	void pushMbeFrame(
	        const unsigned char *mbeFrame,
	        int mbeRateIndex,
	        int mbeVolumeIndex,
	        unsigned char channels,
	        bool useHP,
	        int upsampling,
	        AudioFifo *audioFifo);

    const QTimer& getMasterTimer() const { return m_masterTimer; }
    void setMIMOSupport(bool mimoSupport) { m_mimoSupport = mimoSupport; }
    bool getMIMOSupport() const { return m_mimoSupport; }
    void createFFTFactory(const QString& fftWisdomFileName);
    void preAllocateFFTs();
    FFTFactory *getFFTFactory() { return m_fftFactory; }

private:
    struct DeviceEngineReference
    {
        int m_deviceEngineType; //!< 0: Rx, 1: Tx, 2: MIMO
        DSPDeviceSourceEngine *m_deviceSourceEngine;
        DSPDeviceSinkEngine *m_deviceSinkEngine;
        DSPDeviceMIMOEngine *m_deviceMIMOEngine;
    };

	QList<DSPDeviceSourceEngine*> m_deviceSourceEngines;
	unsigned int m_deviceSourceEnginesUIDSequence;
	QList<DSPDeviceSinkEngine*> m_deviceSinkEngines;
	unsigned int m_deviceSinkEnginesUIDSequence;
	QList<DSPDeviceMIMOEngine*> m_deviceMIMOEngines;
	unsigned int m_deviceMIMOEnginesUIDSequence;
    QList<DeviceEngineReference> m_deviceEngineReferences;
    AudioDeviceManager m_audioDeviceManager;
    int m_audioInputDeviceIndex;
    int m_audioOutputDeviceIndex;
    QTimer m_masterTimer;
	bool m_dvSerialSupport;
    bool m_mimoSupport;
	AMBEEngine m_ambeEngine;
    FFTFactory *m_fftFactory;
};

#endif // INCLUDE_DSPENGINE_H
