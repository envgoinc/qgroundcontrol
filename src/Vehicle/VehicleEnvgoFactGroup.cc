/****************************************************************************
 *
 *   Copyright (c) 2022 enVgo. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/ 

#include "VehicleEnvgoFactGroup.h"
#include "Vehicle.h"
#include "math.h"

const char* VehicleEnvgoFactGroup::_timestampFactName =                   "timestamp";
const char* VehicleEnvgoFactGroup::_escErrorCountFactName =               "escErrorCount";
const char* VehicleEnvgoFactGroup::_escRPMFactName =                      "escRPM";
const char* VehicleEnvgoFactGroup::_escThrottleFactName =                 "escThrottle";
const char* VehicleEnvgoFactGroup::_escVoltageFactName =                  "escVoltage";
const char* VehicleEnvgoFactGroup::_escCurrentFactName =                  "escCurrent";
const char* VehicleEnvgoFactGroup::_motorPositionFactName =               "motorPosition";
const char* VehicleEnvgoFactGroup::_escAddressFactName =                  "escAddress";
const char* VehicleEnvgoFactGroup::_escStateFactName =                    "escState";

VehicleEnvgoFactGroup::VehicleEnvgoFactGroup(QObject* parent)
    : FactGroup                         (1000, ":/json/Vehicle/EnvgoFactGroup.json", parent)
    , _timestampFact                    (0, _timestampFactName,                 FactMetaData::valueTypeFloat)
    , _escErrorCountFact                (0, _escErrorCountFactName,             FactMetaData::valueTypeFloat)
    , _escRPMFact                       (0, _escRPMFactName,                    FactMetaData::valueTypeFloat)
    , _escThrottleFact                  (0, _escThrottleFactName,               FactMetaData::valueTypeFloat)
    , _escVoltageFact                   (0, _escVoltageFactName,                FactMetaData::valueTypeFloat)
    , _escCurrentFact                   (0, _escCurrentFactName,                FactMetaData::valueTypeFloat)
    , _motorPositionFact                (0, _motorPositionFactName,             FactMetaData::valueTypeFloat)
    , _escAddressFact                   (0, _escAddressFactName,                FactMetaData::valueTypeFloat)
    , _escStateFact                     (0, _escStateFactName,                  FactMetaData::valueTypeFloat)

{
    _addFact(&_timestampFact,               _timestampFactName);
    _addFact(&_escErrorCountFact,           _escErrorCountFactName);
    _addFact(&_escRPMFact,                  _escRPMFactName);
    _addFact(&_escThrottleFact,             _escThrottleFactName);
    _addFact(&_escVoltageFact,              _escVoltageFactName);
    _addFact(&_escCurrentFact,              _escCurrentFactName);
    _addFact(&_motorPositionFact,           _motorPositionFactName);
    _addFact(&_escAddressFact,              _escAddressFactName);
    _addFact(&_escStateFact,                _escStateFactName);
}

void VehicleEnvgoFactGroup::handleMessage(Vehicle* /* vehicle */, mavlink_message_t& message)
{
    
}