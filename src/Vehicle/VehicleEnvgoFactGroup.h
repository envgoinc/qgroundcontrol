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
#include "QGCMavlink.h"

class Vehicle;

class VehicleEnvgoFactGroup : public FactGroup
{
    Q_OBJECT 

    public:
        VehicleEnvgoFactGroup(QObject* parent = nullptr);
        
        Q_PROPERTY(Fact* timestamp                READ timestamp        CONSTANT)
        Q_PROPERTY(Fact* escErrorCount            READ escErrorCount    CONSTANT)
        Q_PROPERTY(Fact* escRPM                   READ escRPM           CONSTANT)
        Q_PROPERTY(Fact* escThrottle              READ escThrottle      CONSTANT)
        Q_PROPERTY(Fact* escVoltage               READ escVoltage       CONSTANT)
        Q_PROPERTY(Fact* escCurrent               READ escCurrent       CONSTANT)
        Q_PROPERTY(Fact* motorPosition            READ motorPosition    CONSTANT)
        Q_PROPERTY(Fact* escAddress               READ escAddress       CONSTANT)
        Q_PROPERTY(Fact* escState                 READ escState         CONSTANT)

        Fact* timestamp                           () { return &_timestampFact; }
        Fact* escErrorCount                       () { return &_escErrorCountFact; }
        Fact* escRPM                              () { return &_escRPMFact; }
        Fact* escThrottle                         () { return &_escThrottleFact; }
        Fact* escVoltage                          () { return &_escVoltageFact; }
        Fact* escCurrent                          () { return &_escCurrentFact; }
        Fact* motorPosition                       () { return &_motorPositionFact; }
        Fact* escAddress                          () { return &_escAddressFact; }
        Fact* escState                            () { return &_escStateFact; }
        

        // Overrides from FactGroup
        void handleMessage(Vehicle* vehicle, mavlink_message_t& message) override;

        static const char* _timestampFactName;
        static const char* _escErrorCountFactName;
        static const char* _escRPMFactName;
        static const char* _escThrottleFactName;
        static const char* _escVoltageFactName;
        static const char* _escCurrentFactName;
        static const char* _motorPositionFactName;
        static const char* _escAddressFactName;
        static const char* _escStateFactName;

    private:
        Fact _timestampFact;
        Fact _escErrorCountFact;
        Fact _escRPMFact;
        Fact _escThrottleFact;
        Fact _escVoltageFact;
        Fact _escCurrentFact;
        Fact _motorPositionFact;
        Fact _escAddressFact;
        Fact _escStateFact;

};




