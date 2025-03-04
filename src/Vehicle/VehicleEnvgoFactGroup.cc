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

const char* VehicleEnvgoFactGroup::_mechPwrFactName =                           "mechPwr";
const char* VehicleEnvgoFactGroup::_efficiencyFactName =                        "efficiency";
const char* VehicleEnvgoFactGroup::_gPerWFactName =                             "gPerW";
const char* VehicleEnvgoFactGroup::_desiredPitchFactName =                      "desiredPitch";
const char* VehicleEnvgoFactGroup::_cmdHeightFactName =                         "cmdHeight";
const char* VehicleEnvgoFactGroup::_estHeightFactName =                         "estHeight";
const char* VehicleEnvgoFactGroup::_elevatorAngleFactName =                     "elevatorAngle";
const char* VehicleEnvgoFactGroup::_desiredHeightFactName =                     "desiredHeight";
const char* VehicleEnvgoFactGroup::_gearFactName =                              "gear";
const char* VehicleEnvgoFactGroup::_sternHeightFactName =                       "sternHeight";
const char* VehicleEnvgoFactGroup::_sonarFrontFactName =                        "sonarBow";
const char* VehicleEnvgoFactGroup::_sonarBackStarboardFactName =                "sonarBackStar";
const char* VehicleEnvgoFactGroup::_sonarBackPortFactName =                     "sonarBackPort";


VehicleEnvgoFactGroup::VehicleEnvgoFactGroup(QObject* parent)
    : FactGroup                         (1000, ":/json/Vehicle/EnvgoFactGroup.json", parent)
    , _mechPwrFact                      (0, _mechPwrFactName,                       FactMetaData::valueTypeFloat)
    , _efficiencyFact                   (0, _efficiencyFactName,                    FactMetaData::valueTypeFloat)
    , _gPerWFact                        (0, _gPerWFactName,                         FactMetaData::valueTypeFloat)
    , _desiredPitchFact                 (0, _desiredPitchFactName,                  FactMetaData::valueTypeFloat)
    , _cmdHeightFact                    (0, _cmdHeightFactName,                     FactMetaData::valueTypeFloat)
    , _estHeightFact                    (0, _estHeightFactName,                     FactMetaData::valueTypeFloat)
    , _elevatorAngleFact                (0, _elevatorAngleFactName,                 FactMetaData::valueTypeFloat)
    , _desiredHeightFact                (0, _desiredHeightFactName,                 FactMetaData::valueTypeFloat)
    , _gearFact                         (0, _gearFactName,                          FactMetaData::valueTypeFloat)
    , _sternHeightFact                  (0, _sternHeightFactName,                   FactMetaData::valueTypeFloat)
    , _sonarFrontFact                   (0, _sonarFrontFactName,                    FactMetaData::valueTypeFloat)
    , _sonarBackStarboardFact           (0, _sonarBackStarboardFactName,            FactMetaData::valueTypeFloat)
    , _sonarBackPortFact                (0, _sonarBackPortFactName,                 FactMetaData::valueTypeFloat)

{
    _addFact(&_mechPwrFact,                     _mechPwrFactName);
    _addFact(&_efficiencyFact,                  _efficiencyFactName);
    _addFact(&_gPerWFact,                       _gPerWFactName);
    _addFact(&_desiredPitchFact,                _desiredPitchFactName);
    _addFact(&_cmdHeightFact,                   _cmdHeightFactName);
    _addFact(&_estHeightFact,                   _estHeightFactName);
    _addFact(&_elevatorAngleFact,               _elevatorAngleFactName);
    _addFact(&_desiredHeightFact,               _desiredHeightFactName);
    _addFact(&_gearFact,                        _gearFactName);
    _addFact(&_sternHeightFact,                 _sternHeightFactName);
    _addFact(&_sonarFrontFact,                  _sonarFrontFactName);
    _addFact(&_sonarBackStarboardFact,          _sonarBackStarboardFactName);
    _addFact(&_sonarBackPortFact,               _sonarBackPortFactName);
}

void VehicleEnvgoFactGroup::handleMessage(Vehicle* /* vehicle */, mavlink_message_t& message)
{
    if (message.msgid == MAVLINK_MSG_ID_DEBUG_VECT) {
        mavlink_debug_vect_t content;
        mavlink_msg_debug_vect_decode(&message, &content);

        mechPwr()->setRawValue                      (content.x);
        efficiency()->setRawValue                   (round(content.y));
        gPerW()->setRawValue                        (content.z);
    }  else if (message.msgid == MAVLINK_MSG_ID_DEBUG_FLOAT_ARRAY) {
        mavlink_debug_float_array_t content;
        mavlink_msg_debug_float_array_decode(&message, &content);
        desiredPitch()->setRawValue                 (content.data[10] * 180 / M_PI);
        cmdHeight()->setRawValue                    (content.data[50] * 100);
        estHeight()->setRawValue                    (round(content.data[51] * 100));
        elevatorAngle()->setRawValue                (content.data[36] * 180 / M_PI);
        desiredHeight()->setRawValue                (round(content.data[26] * 100));
        gear()->setRawValue                         ((int)content.data[48]);
        sternHeight()->setRawValue                  (round(content.data[33] * 100));
        sonarFront()->setRawValue                   (round(content.data[45] * 100));
        sonarBackStarboard()->setRawValue           (round(content.data[46] * 100));
        sonarBackPort()->setRawValue                (round(content.data[47] * 100));
    }
}