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
const char* VehicleEscInfoFactGroup::_failureFlagFifthFactName  =               "failureFlag5";
const char* VehicleEscInfoFactGroup::_failureFlagSixthFactName  =               "failureFlag6";
const char* VehicleEscInfoFactGroup::_failureFlagSeventhFactName  =             "failureFlag7";
const char* VehicleEscInfoFactGroup::_failureFlagEighthFactName  =              "failureFlag8";

const char* VehicleEscInfoFactGroup::_errorCountFirstFactName =                 "errorCount1";
const char* VehicleEscInfoFactGroup::_errorCountSecondFactName =                "errorCount2";
const char* VehicleEscInfoFactGroup::_errorCountThirdFactName =                 "errorCount3";
const char* VehicleEscInfoFactGroup::_errorCountFourthFactName =                "errorCount4";
const char* VehicleEscInfoFactGroup::_errorCountFifthFactName  =                "errorCount5";
const char* VehicleEscInfoFactGroup::_errorCountSixthFactName  =                "errorCount6";
const char* VehicleEscInfoFactGroup::_errorCountSeventhFactName  =              "errorCount7";
const char* VehicleEscInfoFactGroup::_errorCountEighthFactName  =               "errorCount8";

const char* VehicleEscInfoFactGroup::_temperatureFirstFactName =                "temperature1";
const char* VehicleEscInfoFactGroup::_temperatureSecondFactName =               "temperature2";
const char* VehicleEscInfoFactGroup::_temperatureThirdFactName =                "temperature3";
const char* VehicleEscInfoFactGroup::_temperatureFourthFactName =               "temperature4";
const char* VehicleEscInfoFactGroup::_temperatureFifthFactName  =               "temperature5";
const char* VehicleEscInfoFactGroup::_temperatureSixthFactName  =               "temperature6";
const char* VehicleEscInfoFactGroup::_temperatureSeventhFactName  =             "temperature7";
const char* VehicleEscInfoFactGroup::_temperatureEighthFactName  =              "temperature8";

const char* VehicleEscInfoFactGroup::_stateFirstFactName =                "state1";
const char* VehicleEscInfoFactGroup::_stateSecondFactName =               "state2";
const char* VehicleEscInfoFactGroup::_stateThirdFactName =                "state3";
const char* VehicleEscInfoFactGroup::_stateFourthFactName =               "state4";
const char* VehicleEscInfoFactGroup::_stateFifthFactName  =               "state5";
const char* VehicleEscInfoFactGroup::_stateSixthFactName  =               "state6";
const char* VehicleEscInfoFactGroup::_stateSeventhFactName  =             "state7";
const char* VehicleEscInfoFactGroup::_stateEighthFactName  =              "state8";

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
    , _failureFlagFifthFact              (0, _failureFlagFifthFactName, FactMetaData::valueTypeFloat)
    , _failureFlagSixthFact              (0, _failureFlagSixthFactName, FactMetaData::valueTypeFloat)
    , _failureFlagSeventhFact            (0, _failureFlagSeventhFactName, FactMetaData::valueTypeFloat)
    , _failureFlagEighthFact             (0, _failureFlagEighthFactName, FactMetaData::valueTypeFloat)

    , _errorCountFirstFact               (0, _errorCountFirstFactName, FactMetaData::valueTypeFloat)
    , _errorCountSecondFact              (0, _errorCountSecondFactName, FactMetaData::valueTypeFloat)
    , _errorCountThirdFact               (0, _errorCountThirdFactName, FactMetaData::valueTypeFloat)
    , _errorCountFourthFact              (0, _errorCountFourthFactName, FactMetaData::valueTypeFloat)
    , _errorCountFifthFact               (0, _errorCountFifthFactName, FactMetaData::valueTypeFloat)
    , _errorCountSixthFact               (0, _errorCountSixthFactName, FactMetaData::valueTypeFloat)
    , _errorCountSeventhFact             (0, _errorCountSeventhFactName, FactMetaData::valueTypeFloat)
    , _errorCountEighthFact              (0, _errorCountEighthFactName, FactMetaData::valueTypeFloat)

    , _temperatureFirstFact              (0, _temperatureFirstFactName, FactMetaData::valueTypeFloat)
    , _temperatureSecondFact             (0, _temperatureSecondFactName, FactMetaData::valueTypeFloat)
    , _temperatureThirdFact              (0, _temperatureThirdFactName, FactMetaData::valueTypeFloat)
    , _temperatureFourthFact             (0, _temperatureFourthFactName, FactMetaData::valueTypeFloat)
    , _temperatureFifthFact              (0, _temperatureFifthFactName, FactMetaData::valueTypeFloat)
    , _temperatureSixthFact              (0, _temperatureSixthFactName, FactMetaData::valueTypeFloat)
    , _temperatureSeventhFact            (0, _temperatureSeventhFactName, FactMetaData::valueTypeFloat)
    , _temperatureEighthFact             (0, _temperatureEighthFactName, FactMetaData::valueTypeFloat)

    , _stateFirstFact                    (0, _stateFirstFactName, FactMetaData::valueTypeFloat)
    , _stateSecondFact                   (0, _stateSecondFactName, FactMetaData::valueTypeFloat)
    , _stateThirdFact                    (0, _stateThirdFactName, FactMetaData::valueTypeFloat)
    , _stateFourthFact                   (0, _stateFourthFactName, FactMetaData::valueTypeFloat)
    , _stateFifthFact                    (0, _stateFifthFactName, FactMetaData::valueTypeFloat)
    , _stateSixthFact                    (0, _stateSixthFactName, FactMetaData::valueTypeFloat)
    , _stateSeventhFact                  (0, _stateSeventhFactName, FactMetaData::valueTypeFloat)
    , _stateEighthFact                   (0, _stateEighthFactName, FactMetaData::valueTypeFloat)
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
   _addFact(&_failureFlagFifthFact,             _failureFlagFifthFactName);
   _addFact(&_failureFlagSixthFact,             _failureFlagSixthFactName);
   _addFact(&_failureFlagSeventhFact,           _failureFlagSeventhFactName);
   _addFact(&_failureFlagEighthFact,            _failureFlagEighthFactName);

   _addFact(&_errorCountFirstFact,              _errorCountFirstFactName);
   _addFact(&_errorCountSecondFact,             _errorCountSecondFactName);
   _addFact(&_errorCountThirdFact,              _errorCountThirdFactName);
   _addFact(&_errorCountFourthFact,             _errorCountFourthFactName);
   _addFact(&_errorCountFifthFact,             _errorCountFifthFactName);
   _addFact(&_errorCountSixthFact,             _errorCountSixthFactName);
   _addFact(&_errorCountSeventhFact,           _errorCountSeventhFactName);
   _addFact(&_errorCountEighthFact,            _errorCountEighthFactName);

   _addFact(&_temperatureFirstFact,             _temperatureFirstFactName);
   _addFact(&_temperatureSecondFact,            _temperatureSecondFactName);
   _addFact(&_temperatureThirdFact,             _temperatureThirdFactName);
   _addFact(&_temperatureFourthFact,            _temperatureFourthFactName);
   _addFact(&_temperatureFifthFact,             _temperatureFifthFactName);
   _addFact(&_temperatureSixthFact,             _temperatureSixthFactName);
   _addFact(&_temperatureSeventhFact,           _temperatureSeventhFactName);
   _addFact(&_temperatureEighthFact,            _temperatureEighthFactName);

   _addFact(&_stateFirstFact,                   _stateFirstFactName);
   _addFact(&_stateSecondFact,                  _stateSecondFactName);
   _addFact(&_stateThirdFact,                   _stateThirdFactName);
   _addFact(&_stateFourthFact,                  _stateFourthFactName);
   _addFact(&_stateFifthFact,                   _stateFifthFactName);
   _addFact(&_stateSixthFact,                   _stateSixthFactName);
   _addFact(&_stateSeventhFact,                 _stateSeventhFactName);
   _addFact(&_stateEighthFact,                  _stateEighthFactName);
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
    // failureFlagFirst()->setRawValue     (content.failure_flags[4]);
    // failureFlagSecond()->setRawValue    (content.failure_flags[5]);
    // failureFlagThird()->setRawValue     (content.failure_flags[6]);
    // failureFlagFourth()->setRawValue    (content.failure_flags[7]);

    errorCountFirst()->setRawValue      (content.error_count[0]);
    errorCountSecond()->setRawValue     (content.error_count[1]);
    errorCountThird()->setRawValue      (content.error_count[2]);
    errorCountFourth()->setRawValue     (content.error_count[3]);
    // errorCountFirst()->setRawValue      (content.error_count[4]);
    // errorCountSecond()->setRawValue     (content.error_count[5]);
    // errorCountThird()->setRawValue      (content.error_count[6]);
    // errorCountFourth()->setRawValue     (content.error_count[7]);
    

    temperatureFirst()->setRawValue     (content.temperature[0]/100);
    temperatureSecond()->setRawValue    (content.temperature[1]/100);
    temperatureThird()->setRawValue     (content.temperature[2]/100);
    temperatureFourth()->setRawValue    (content.temperature[3]/100);
    // temperatureFirst()->setRawValue     (content.temperature[4]/100);
    // temperatureSecond()->setRawValue    (content.temperature[5]/100);
    // temperatureThird()->setRawValue     (content.temperature[6]/100);
    // temperatureFourth()->setRawValue    (content.temperature[7]/100);
    
    stateFirst()->setRawValue     (static_cast<double>(content.state[0]));
    stateSecond()->setRawValue    (static_cast<double>(content.state[1]));
    stateThird()->setRawValue     (static_cast<double>(content.state[2]));
    stateFourth()->setRawValue    (static_cast<double>(content.state[3]));
    // stateFirst()->setRawValue     (static_cast<double>(content.state[4]));
    // stateSecond()->setRawValue    (static_cast<double>(content.state[5]));
    // stateThird()->setRawValue     (static_cast<double>(content.state[6]));
    // stateFourth()->setRawValue    (static_cast<double>(content.state[7]));

    

    
}
