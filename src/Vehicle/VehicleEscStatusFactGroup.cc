/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#include "VehicleEscStatusFactGroup.h"
#include "Vehicle.h"
#include "math.h"

const char* VehicleEscStatusFactGroup::_rpmFactName =                               "rpm";

VehicleEscStatusFactGroup::VehicleEscStatusFactGroup(QObject* parent)
    : FactGroup                         (1000, ":/json/Vehicle/EscStatusFactGroup.json", parent)
    , _rpmFact                          (0, _rpmFactName,                           FactMetaData::valueTypeFloat)
 
{
    _addFact(&_rpmFact,                         _rpmFactName);

}

void VehicleEscStatusFactGroup::handleMessage(Vehicle* /* vehicle */, mavlink_message_t& message)
{
    
    if (message.msgid == MAVLINK_MSG_ID_RAW_RPM) {
        mavlink_raw_rpm_t content;
        mavlink_msg_raw_rpm_decode(&message, &content);

        rpm()->setRawValue                          (content.frequency);
    }
}
