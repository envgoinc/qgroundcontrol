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

#pragma once

#include "FactGroup.h"
#include "QGCMAVLink.h"

class Vehicle;

class VehicleEscInfoFactGroup : public FactGroup
{
    Q_OBJECT

public:
    VehicleEscInfoFactGroup(QObject* parent = nullptr);

    Q_PROPERTY(Fact* index          READ index              CONSTANT)
    
    Q_PROPERTY(Fact* counter            READ counter            CONSTANT)
    Q_PROPERTY(Fact* count              READ count              CONSTANT)
    Q_PROPERTY(Fact* connectionType     READ connectionType     CONSTANT)
    Q_PROPERTY(Fact* info               READ info               CONSTANT)

    Q_PROPERTY(Fact* failureFlagFirst   READ failureFlagFirst   CONSTANT)
    Q_PROPERTY(Fact* failureFlagSecond  READ failureFlagSecond  CONSTANT)
    Q_PROPERTY(Fact* failureFlagThird   READ failureFlagThird   CONSTANT)
    Q_PROPERTY(Fact* failureFlagFourth  READ failureFlagFourth  CONSTANT)
    Q_PROPERTY(Fact* failureFlagFifth   READ failureFlagFourth  CONSTANT)
    Q_PROPERTY(Fact* failureFlagSixth   READ failureFlagFourth  CONSTANT)
    Q_PROPERTY(Fact* failureFlagSeventh READ failureFlagFourth  CONSTANT)
    Q_PROPERTY(Fact* failureFlagEighth  READ failureFlagFourth  CONSTANT)

    Q_PROPERTY(Fact* errorCountFirst    READ errorCountFirst    CONSTANT)
    Q_PROPERTY(Fact* errorCountSecond   READ errorCountSecond   CONSTANT)
    Q_PROPERTY(Fact* errorCountThird    READ errorCountThird    CONSTANT)
    Q_PROPERTY(Fact* errorCountFourth   READ errorCountFourth   CONSTANT)
    Q_PROPERTY(Fact* errorCountFifth    READ errorCountFourth  CONSTANT)
    Q_PROPERTY(Fact* errorCountSixth    READ errorCountFourth  CONSTANT)
    Q_PROPERTY(Fact* errorCountSeventh  READ errorCountFourth  CONSTANT)
    Q_PROPERTY(Fact* errorCountEighth   READ errorCountFourth  CONSTANT)

    Q_PROPERTY(Fact* temperatureFirst   READ temperatureFirst   CONSTANT)
    Q_PROPERTY(Fact* temperatureSecond  READ temperatureSecond  CONSTANT)
    Q_PROPERTY(Fact* temperatureThird   READ temperatureThird   CONSTANT)
    Q_PROPERTY(Fact* temperatureFourth  READ temperatureFourth  CONSTANT)
    Q_PROPERTY(Fact* temperatureFifth   READ temperatureFourth  CONSTANT)
    Q_PROPERTY(Fact* temperatureSixth   READ temperatureFourth  CONSTANT)
    Q_PROPERTY(Fact* temperatureSeventh READ temperatureFourth  CONSTANT)
    Q_PROPERTY(Fact* temperatureEighth  READ temperatureFourth  CONSTANT)

    Q_PROPERTY(Fact* stateFirst         READ stateFirst   CONSTANT)
    Q_PROPERTY(Fact* stateSecond        READ stateSecond  CONSTANT)
    Q_PROPERTY(Fact* stateThird         READ stateThird   CONSTANT)
    Q_PROPERTY(Fact* stateFourth        READ stateFourth  CONSTANT)
    Q_PROPERTY(Fact* stateFifth         READ stateFourth  CONSTANT)
    Q_PROPERTY(Fact* stateSixth         READ stateFourth  CONSTANT)
    Q_PROPERTY(Fact* stateSeventh       READ stateFourth  CONSTANT)
    Q_PROPERTY(Fact* stateEighth        READ stateFourth  CONSTANT)

    Fact* index                         () { return &_indexFact; }

    Fact* counter                       () { return &_counterFact; }
    Fact* count                         () { return &_countFact; }
    Fact* connectionType                () { return &_connectionTypeFact; }
    Fact* info                          () { return &_infoFact; }

    Fact* failureFlagFirst              () { return &_failureFlagFirstFact; }
    Fact* failureFlagSecond             () { return &_failureFlagSecondFact; }
    Fact* failureFlagThird              () { return &_failureFlagThirdFact; }
    Fact* failureFlagFourth             () { return &_failureFlagFourthFact; }
    Fact* failureFlagFifth              () { return &_failureFlagFifthFact; }
    Fact* failureFlagSixth              () { return &_failureFlagSixthFact; }
    Fact* failureFlagSeventh            () { return &_failureFlagSeventhFact; }
    Fact* failureFlagEighth             () { return &_failureFlagEighthFact; }

    Fact* errorCountFirst               () { return &_errorCountFirstFact; }
    Fact* errorCountSecond              () { return &_errorCountSecondFact; }
    Fact* errorCountThird               () { return &_errorCountThirdFact; }
    Fact* errorCountFourth              () { return &_errorCountFourthFact; }
    Fact* errorCountFifth              () { return &_errorCountFifthFact; }
    Fact* errorCountSixth              () { return &_errorCountSixthFact; }
    Fact* errorCountSeventh            () { return &_errorCountSeventhFact; }
    Fact* errorCountEighth             () { return &_errorCountEighthFact; }
    

    Fact* temperatureFirst              () { return &_temperatureFirstFact; }
    Fact* temperatureSecond             () { return &_temperatureSecondFact; }
    Fact* temperatureThird              () { return &_temperatureThirdFact; }
    Fact* temperatureFourth             () { return &_temperatureFourthFact; }
    Fact* temperatureFifth              () { return &_temperatureFifthFact; }
    Fact* temperatureSixth              () { return &_temperatureSixthFact; }
    Fact* temperatureSeventh            () { return &_temperatureSeventhFact; }
    Fact* temperatureEighth             () { return &_temperatureEighthFact; }

    Fact* stateFirst                    () { return &_stateFirstFact; }
    Fact* stateSecond                   () { return &_stateSecondFact; }
    Fact* stateThird                    () { return &_stateThirdFact; }
    Fact* stateFourth                   () { return &_stateFourthFact; }
    Fact* stateFifth                    () { return &_stateFifthFact; }
    Fact* stateSixth                    () { return &_stateSixthFact; }
    Fact* stateSeventh                  () { return &_stateSeventhFact; }
    Fact* stateEighth                   () { return &_stateEighthFact; }

    // Overrides from FactGroup
    void handleMessage(Vehicle* vehicle, mavlink_message_t& message) override;

    static const char* _indexFactName;

    static const char* _counterFactName;
    static const char* _countFactName;
    static const char* _connectionTypeFactName;
    static const char* _infoFactName;

    static const char* _failureFlagFirstFactName;
    static const char* _failureFlagSecondFactName;
    static const char* _failureFlagThirdFactName;
    static const char* _failureFlagFourthFactName;
    static const char* _failureFlagFifthFactName;
    static const char* _failureFlagSixthFactName;
    static const char* _failureFlagSeventhFactName;
    static const char* _failureFlagEighthFactName;

    static const char* _errorCountFirstFactName;
    static const char* _errorCountSecondFactName;
    static const char* _errorCountThirdFactName;
    static const char* _errorCountFourthFactName;
    static const char* _errorCountFifthFactName;
    static const char* _errorCountSixthFactName;
    static const char* _errorCountSeventhFactName;
    static const char* _errorCountEighthFactName;

    static const char* _temperatureFirstFactName;
    static const char* _temperatureSecondFactName;
    static const char* _temperatureThirdFactName;
    static const char* _temperatureFourthFactName;
    static const char* _temperatureFifthFactName;
    static const char* _temperatureSixthFactName;
    static const char* _temperatureSeventhFactName;
    static const char* _temperatureEighthFactName;

    static const char* _stateFirstFactName;
    static const char* _stateSecondFactName;
    static const char* _stateThirdFactName;
    static const char* _stateFourthFactName;
    static const char* _stateFifthFactName;
    static const char* _stateSixthFactName;
    static const char* _stateSeventhFactName;
    static const char* _stateEighthFactName;
private:
    Fact _indexFact;

    Fact _counterFact;
    Fact _countFact;
    Fact _connectionTypeFact;
    Fact _infoFact;

    Fact _failureFlagFirstFact;
    Fact _failureFlagSecondFact;
    Fact _failureFlagThirdFact;
    Fact _failureFlagFourthFact;
    Fact _failureFlagFifthFact;
    Fact _failureFlagSixthFact;
    Fact _failureFlagSeventhFact;
    Fact _failureFlagEighthFact;
    

    Fact _errorCountFirstFact;
    Fact _errorCountSecondFact;
    Fact _errorCountThirdFact;
    Fact _errorCountFourthFact;
    Fact _errorCountFifthFact;
    Fact _errorCountSixthFact;
    Fact _errorCountSeventhFact;
    Fact _errorCountEighthFact;

    Fact _temperatureFirstFact;
    Fact _temperatureSecondFact;
    Fact _temperatureThirdFact;
    Fact _temperatureFourthFact;
    Fact _temperatureFifthFact;
    Fact _temperatureSixthFact;
    Fact _temperatureSeventhFact;
    Fact _temperatureEighthFact;

    Fact _stateFirstFact;
    Fact _stateSecondFact;
    Fact _stateThirdFact;
    Fact _stateFourthFact;
    Fact _stateFifthFact;
    Fact _stateSixthFact;
    Fact _stateSeventhFact;
    Fact _stateEighthFact;

    

};