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
    Q_PROPERTY(Fact* cmdHeight          READ cmdHeight          CONSTANT)
    Q_PROPERTY(Fact* estHeight          READ estHeight          CONSTANT)

    Fact* rpm                           () { return &_rpmFact; }
    Fact* mechPwr                       () { return &_mechPwrFact; }
    Fact* efficiency                    () { return &_efficiencyFact; }
    Fact* gPerW                         () { return &_gPerWFact; }
    Fact* cmdHeight                     () { return &_cmdHeightFact; }
    Fact* estHeight                     () { return &_estHeightFact; }

    // Overrides from FactGroup
    void handleMessage(Vehicle* vehicle, mavlink_message_t& message) override;

    static const char* _rpmFactName;
    static const char* _mechPwrFactName;
    static const char* _efficiencyFactName;
    static const char* _gPerWFactName;
    static const char* _cmdHeightFactName;
    static const char* _estHeightFactName;

private:
    Fact _rpmFact;
    Fact _mechPwrFact;
    Fact _efficiencyFact;
    Fact _gPerWFact;
    Fact _cmdHeightFact;
    Fact _estHeightFact;
};
