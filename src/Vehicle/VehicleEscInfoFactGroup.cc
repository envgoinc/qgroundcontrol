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

#include "VehicleEscInfoFactGroup.h"
#include "Vehicle.h"

const char* VehicleEscInfoFactGroup::_indexFactName =                           "index";

const char* VehicleEscInfoFactGroup::_counterFactName =                         "counter";
const char* VehicleEscInfoFactGroup::_countFactName =                           "count";
const char* VehicleEscInfoFactGroup::_connectionTypeFactName =                  "connectionType";
const char* VehicleEscInfoFactGroup::_infoFactName =                            "info";

const char* VehicleEscInfoFactGroup::_failureFlagFirstFactName =                "failureFlag1";
const char* VehicleEscInfoFactGroup::_failureFlagSecondFactName =               "failureFlag2";
const char* VehicleEscInfoFactGroup::_failureFlagThirdFactName =                "failureFlag3";
const char* VehicleEscInfoFactGroup::_failureFlagFourthFactName  =              "failureFlag4";

const char* VehicleEscInfoFactGroup::_errorCountFirstFactName =                 "errorCount1";
const char* VehicleEscInfoFactGroup::_errorCountSecondFactName =                "errorCount2";
const char* VehicleEscInfoFactGroup::_errorCountThirdFactName =                 "errorCount3";
const char* VehicleEscInfoFactGroup::_errorCountFourthFactName =                "errorCount4";

const char* VehicleEscInfoFactGroup::_temperatureFirstFactName =                "temperature1";
const char* VehicleEscInfoFactGroup::_temperatureSecondFactName =               "temperature2";
const char* VehicleEscInfoFactGroup::_temperatureThirdFactName =                "temperature3";
const char* VehicleEscInfoFactGroup::_temperatureFourthFactName =               "temperature4";

VehicleEscInfoFactGroup::VehicleEscInfoFactGroup(QObject* parent)
    : FactGroup                         (1000, ":/json/Vehicle/EscInfoFactGroup.json", parent)
    , _indexFact                         (0, _indexFactName, FactMetaData::valueTypeUint8)

    , _counterFact                       (0, _counterFactName, FactMetaData::valueTypeFloat)
    , _countFact                         (0, _countFactName, FactMetaData::valueTypeFloat)
    , _connectionTypeFact                (0, _connectionTypeFactName, FactMetaData::valueTypeFloat)
    , _infoFact                          (0, _infoFactName, FactMetaData::valueTypeFloat)

    , _failureFlagFirstFact              (0, _failureFlagFirstFactName, FactMetaData::valueTypeFloat)
    , _failureFlagSecondFact             (0, _failureFlagSecondFactName, FactMetaData::valueTypeFloat)
    , _failureFlagThirdFact              (0, _failureFlagThirdFactName, FactMetaData::valueTypeFloat)
    , _failureFlagFourthFact             (0, _failureFlagFourthFactName, FactMetaData::valueTypeFloat)

    , _errorCountFirstFact               (0, _errorCountFirstFactName, FactMetaData::valueTypeFloat)
    , _errorCountSecondFact              (0, _errorCountSecondFactName, FactMetaData::valueTypeFloat)
    , _errorCountThirdFact               (0, _errorCountThirdFactName, FactMetaData::valueTypeFloat)
    , _errorCountFourthFact              (0, _errorCountFourthFactName, FactMetaData::valueTypeFloat)

    , _temperatureFirstFact              (0, _temperatureFirstFactName, FactMetaData::valueTypeFloat)
    , _temperatureSecondFact             (0, _temperatureSecondFactName, FactMetaData::valueTypeFloat)
    , _temperatureThirdFact              (0, _temperatureThirdFactName, FactMetaData::valueTypeFloat)
    , _temperatureFourthFact             (0, _temperatureFourthFactName, FactMetaData::valueTypeFloat)
{
   _addFact(&_indexFact,                        _indexFactName);

   _addFact(&_counterFact,                      _counterFactName);
   _addFact(&_countFact,                        _countFactName);
   _addFact(&_connectionTypeFact,               _connectionTypeFactName);
   _addFact(&_infoFact,                         _infoFactName);

   _addFact(&_failureFlagFirstFact,             _failureFlagFirstFactName);
   _addFact(&_failureFlagSecondFact,            _failureFlagSecondFactName);
   _addFact(&_failureFlagThirdFact,             _failureFlagThirdFactName);
   _addFact(&_failureFlagFourthFact,            _failureFlagFourthFactName);

   _addFact(&_errorCountFirstFact,              _errorCountFirstFactName);
   _addFact(&_errorCountSecondFact,             _errorCountSecondFactName);
   _addFact(&_errorCountThirdFact,              _errorCountThirdFactName);
   _addFact(&_errorCountFourthFact,             _errorCountFourthFactName);

   _addFact(&_temperatureFirstFact,             _temperatureFirstFactName);
   _addFact(&_temperatureSecondFact,            _temperatureSecondFactName);
   _addFact(&_temperatureThirdFact,             _temperatureThirdFactName);
   _addFact(&_temperatureFourthFact,            _temperatureFourthFactName);
}

void VehicleEscInfoFactGroup::handleMessage(Vehicle* /* vehicle */, mavlink_message_t& message)
{
    if (message.msgid != MAVLINK_MSG_ID_ESC_INFO){
        return;
    }

    mavlink_esc_info_t content;
    mavlink_msg_esc_info_decode(&message, &content);

    index()->setRawValue                (content.index);

    counter()->setRawValue              (content.counter);
    count()->setRawValue                (content.count);
    connectionType()->setRawValue       (content.connection_type);
    info()->setRawValue                 (content.info);

    failureFlagFirst()->setRawValue     (content.failure_flags[0]);
    failureFlagSecond()->setRawValue    (content.failure_flags[1]);
    failureFlagThird()->setRawValue     (content.failure_flags[2]);
    failureFlagFourth()->setRawValue    (content.failure_flags[3]);

    errorCountFirst()->setRawValue      (content.error_count[0]);
    errorCountSecond()->setRawValue     (content.error_count[1]);
    errorCountThird()->setRawValue      (content.error_count[2]);
    errorCountFourth()->setRawValue     (content.error_count[3]);

    temperatureFirst()->setRawValue     (content.temperature[0]);
    temperatureSecond()->setRawValue    (content.temperature[1]);
    temperatureThird()->setRawValue     (content.temperature[2]);
    temperatureFourth()->setRawValue    (content.temperature[3]);
}
