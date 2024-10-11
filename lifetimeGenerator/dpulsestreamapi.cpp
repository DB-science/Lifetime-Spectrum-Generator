/****************************************************************************
**
**  Copyright (C) 2019-2023 Dr. Danny Petschke
**
**  This program is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program. If not, see http://www.gnu.org/licenses/.
**
*****************************************************************************
**
**  @author:  Danny Petschke
**  @contact: danny.petschke@uni-wuerzburg.de
**
*****************************************************************************/

#include "dpulsestreamapi.h"

DPulseStreamManager *__sharedInstanceStreamManager = nullptr;

DPulseStreamManager::DPulseStreamManager() {
    m_file           = nullptr;
    m_isArmed        = false;
    m_fileName       = "";
    m_contentInBytes = 0;
}

DPulseStreamManager::~DPulseStreamManager() {
    if (m_file && isArmed())
        stopAndSave();

    DDELETE_SAFETY(m_file);
}

DPulseStreamManager *DPulseStreamManager::sharedInstance() {
    if (!__sharedInstanceStreamManager)
        __sharedInstanceStreamManager = new DPulseStreamManager();

    return __sharedInstanceStreamManager;
}

bool DPulseStreamManager::start(const string& fileName, double sweepInNanoseconds, double sampleSpeedInGHz, int numberOfSamplePoints) {
    DDELETE_SAFETY(m_file);

    if (fileName.empty() || numberOfSamplePoints <= 0)
        return false;

    m_fileName = fileName;

    m_file = new ofstream(m_fileName, ios::out | ios::binary);

    DPulseStreamHeader header = { 1, sweepInNanoseconds, sampleSpeedInGHz, numberOfSamplePoints };

    m_file->write((const char*)&header, sz_structDPulseStreamHeader);

    m_contentInBytes = sz_structDPulseStreamHeader;
    m_isArmed = true;

    return true;
}

void DPulseStreamManager::stopAndSave() {
    if (m_file && isArmed())
        m_file->close();

    DDELETE_SAFETY(m_file);

    m_isArmed        = false;
    m_fileName       = "";
    m_contentInBytes = 0;
}

bool DPulseStreamManager::writePulse(float *time, float *voltage, int nBytes) {
    if (!time || !voltage || nBytes <= 0)
        return false;

    if (!m_file || !m_isArmed)
        return false;

    m_file->write((const char*)time,    nBytes);
    m_file->write((const char*)voltage, nBytes);

    m_contentInBytes += 2* nBytes;

    return true;
}

bool DPulseStreamManager::writePulsePair(float *time_1, float *voltage_1, float *time_2, float *voltage_2, int nBytes) {
    return writePulse(time_1, voltage_1, nBytes) && writePulse(time_2, voltage_2, nBytes);
}


