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


    Fact* rpm                           () { return &_rpmFact; }
    
    // Overrides from FactGroup
    void handleMessage(Vehicle* vehicle, mavlink_message_t& message) override;

    
    static const char* _rpmFactName;

private:
    Fact _rpmFact;

};
