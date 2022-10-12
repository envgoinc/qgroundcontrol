/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once

#include "FactGroup.h"
#include "QGCMAVLink.h"

class Vehicle;

class VehicleEscStatusFactGroup : public FactGroup
{
    Q_OBJECT

public:
    VehicleEscStatusFactGroup(QObject* parent = nullptr);

    Q_PROPERTY(Fact* rpm                READ rpm                CONSTANT)
    Q_PROPERTY(Fact* mechPwr            READ mechPwr            CONSTANT)
    Q_PROPERTY(Fact* efficiency         READ efficiency         CONSTANT)
    Q_PROPERTY(Fact* gPerW              READ gPerW              CONSTANT)
    Q_PROPERTY(Fact* desiredPitch       READ desiredPitch       CONSTANT)
    Q_PROPERTY(Fact* cmdHeight          READ cmdHeight          CONSTANT)
    Q_PROPERTY(Fact* estHeight          READ estHeight          CONSTANT)
    Q_PROPERTY(Fact* elevatorAngle      READ elevatorAngle      CONSTANT)

    Fact* rpm                           () { return &_rpmFact; }
    Fact* mechPwr                       () { return &_mechPwrFact; } //envgo
    Fact* efficiency                    () { return &_efficiencyFact; } //envgo
    Fact* gPerW                         () { return &_gPerWFact; } //envgo
    Fact* desiredPitch                  () { return &_desiredPitchFact; } //envgo
    Fact* cmdHeight                     () { return &_cmdHeightFact; } //envgo
    Fact* estHeight                     () { return &_estHeightFact; } //envgo
    Fact* elevatorAngle                 () { return &_elevatorAngleFact; } //envgo

    // Overrides from FactGroup
    void handleMessage(Vehicle* vehicle, mavlink_message_t& message) override;

    static const char* _rpmFactName;
    static const char* _mechPwrFactName;
    static const char* _efficiencyFactName;
    static const char* _gPerWFactName;
    static const char* _desiredPitchFactName;
    static const char* _cmdHeightFactName;
    static const char* _estHeightFactName;
    static const char* _elevatorAngleFactName;

private:
    Fact _rpmFact;
    Fact _mechPwrFact;
    Fact _efficiencyFact;
    Fact _gPerWFact;
    Fact _desiredPitchFact;
    Fact _cmdHeightFact;
    Fact _estHeightFact;
    Fact _elevatorAngleFact;
};
