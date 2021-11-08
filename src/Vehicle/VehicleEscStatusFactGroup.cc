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
const char* VehicleEscStatusFactGroup::_mechPwrFactName =                           "mechPwr";
const char* VehicleEscStatusFactGroup::_efficiencyFactName =                        "efficiency";
const char* VehicleEscStatusFactGroup::_gPerWFactName =                             "gPerW";
const char* VehicleEscStatusFactGroup::_desiredPitchFactName =                      "desiredPitch";
const char* VehicleEscStatusFactGroup::_cmdHeightFactName =                         "cmdHeight";
const char* VehicleEscStatusFactGroup::_estHeightFactName =                         "estHeight";
const char* VehicleEscStatusFactGroup::_elevatorAngleFactName =                     "elevatorAngle";


VehicleEscStatusFactGroup::VehicleEscStatusFactGroup(QObject* parent)
    : FactGroup                         (1000, ":/json/Vehicle/EscStatusFactGroup.json", parent)
    , _rpmFact                          (0, _rpmFactName,                           FactMetaData::valueTypeFloat)
    , _mechPwrFact                      (0, _mechPwrFactName,                       FactMetaData::valueTypeFloat)
    , _efficiencyFact                   (0, _efficiencyFactName,                    FactMetaData::valueTypeFloat)
    , _gPerWFact                        (0, _gPerWFactName,                         FactMetaData::valueTypeFloat)
    , _desiredPitchFact                 (0, _desiredPitchFactName,                  FactMetaData::valueTypeFloat)
    , _cmdHeightFact                    (0, _cmdHeightFactName,                     FactMetaData::valueTypeFloat)
    , _estHeightFact                    (0, _estHeightFactName,                     FactMetaData::valueTypeFloat)
    , _elevatorAngleFact                (0, _elevatorAngleFactName,                 FactMetaData::valueTypeFloat)

{
    _addFact(&_rpmFact,                         _rpmFactName);
    _addFact(&_mechPwrFact,                     _mechPwrFactName);
    _addFact(&_efficiencyFact,                  _efficiencyFactName);
    _addFact(&_gPerWFact,                       _gPerWFactName);
    _addFact(&_desiredPitchFact,                    _desiredPitchFactName);
    _addFact(&_cmdHeightFact,                   _cmdHeightFactName);
    _addFact(&_estHeightFact,                   _estHeightFactName);
    _addFact(&_elevatorAngleFact,               _elevatorAngleFactName);
}

void VehicleEscStatusFactGroup::handleMessage(Vehicle* /* vehicle */, mavlink_message_t& message)
{
    if (message.msgid == MAVLINK_MSG_ID_DEBUG_VECT) {
        mavlink_debug_vect_t content;
        mavlink_msg_debug_vect_decode(&message, &content);

        mechPwr()->setRawValue                      (content.x);
        efficiency()->setRawValue                   (content.y);
        gPerW()->setRawValue                        (content.z);
    } else if (message.msgid == MAVLINK_MSG_ID_RAW_RPM) {
        mavlink_raw_rpm_t content;
        mavlink_msg_raw_rpm_decode(&message, &content);

        rpm()->setRawValue                          (content.frequency);
    } else if (message.msgid == MAVLINK_MSG_ID_DEBUG_FLOAT_ARRAY) {
        mavlink_debug_float_array_t content;
        mavlink_msg_debug_float_array_decode(&message, &content);
        desiredPitch()->setRawValue                 (content.data[10] * 180 / M_PI);
        cmdHeight()->setRawValue                    (content.data[50] * 100);
        estHeight()->setRawValue                    (content.data[51] * 100);
        elevatorAngle()->setRawValue                (content.data[36] * 180 / M_PI);
    }
}
