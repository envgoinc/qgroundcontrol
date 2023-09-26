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

class VehicleEnvgoFactGroup : public FactGroup
{
    Q_OBJECT 

    public:
        VehicleEnvgoFactGroup(QObject* parent = nullptr);
        
        Q_PROPERTY(Fact* mechPwr            READ mechPwr            CONSTANT)
        Q_PROPERTY(Fact* efficiency         READ efficiency         CONSTANT)
        Q_PROPERTY(Fact* gPerW              READ gPerW              CONSTANT)
        Q_PROPERTY(Fact* desiredPitch       READ desiredPitch       CONSTANT)
        Q_PROPERTY(Fact* cmdHeight          READ cmdHeight          CONSTANT)
        Q_PROPERTY(Fact* estHeight          READ estHeight          CONSTANT)
        Q_PROPERTY(Fact* elevatorAngle      READ elevatorAngle      CONSTANT)
        Q_PROPERTY(Fact* desiredHeight      READ desiredHeight      CONSTANT)
        Q_PROPERTY(Fact* gear               READ gear               CONSTANT)
        Q_PROPERTY(Fact* sternHeight        READ sternHeight        CONSTANT)
        Q_PROPERTY(Fact* sonarFront         READ sonarFront         CONSTANT)
        Q_PROPERTY(Fact* sonarBack          READ sonarBack          CONSTANT)
        
        Fact* mechPwr                       () { return &_mechPwrFact; }
        Fact* efficiency                    () { return &_efficiencyFact; }
        Fact* gPerW                         () { return &_gPerWFact; }
        Fact* desiredPitch                  () { return &_desiredPitchFact; }
        Fact* cmdHeight                     () { return &_cmdHeightFact; }
        Fact* estHeight                     () { return &_estHeightFact; }
        Fact* elevatorAngle                 () { return &_elevatorAngleFact; }
        Fact* desiredHeight                 () { return &_desiredHeightFact; }
        Fact* gear                          () { return &_gearFact; }
        Fact* sternHeight                   () { return &_sternHeightFact; }
        Fact* sonarFront                    () { return &_sonarFrontFact; }
        Fact* sonarBack                     () { return &_sonarBackFact; }


        // Overrides from FactGroup
        void handleMessage(Vehicle* vehicle, mavlink_message_t& message) override;

        static const char* _mechPwrFactName;
        static const char* _efficiencyFactName;
        static const char* _gPerWFactName;
        static const char* _desiredPitchFactName;
        static const char* _cmdHeightFactName;
        static const char* _estHeightFactName;
        static const char* _elevatorAngleFactName;
        static const char* _desiredHeightFactName;
        static const char* _gearFactName;
        static const char* _sternHeightFactName;
        static const char* _sonarFrontFactName;
        static const char* _sonarBackFactName;

    private:
        Fact _mechPwrFact;
        Fact _efficiencyFact;
        Fact _gPerWFact;
        Fact _desiredPitchFact;
        Fact _cmdHeightFact;
        Fact _estHeightFact;
        Fact _elevatorAngleFact;
        Fact _desiredHeightFact;
        Fact _gearFact;
        Fact _sternHeightFact;
        Fact _sonarFrontFact;
        Fact _sonarBackFact;
};




