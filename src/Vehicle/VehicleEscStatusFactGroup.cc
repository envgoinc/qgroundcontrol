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

const char* VehicleEscStatusFactGroup::_indexFactName =                             "index";

const char* VehicleEscStatusFactGroup::_rpmFirstFactName =                          "rpm1";
const char* VehicleEscStatusFactGroup::_rpmSecondFactName =                         "rpm2";
const char* VehicleEscStatusFactGroup::_rpmThirdFactName =                          "rpm3";
const char* VehicleEscStatusFactGroup::_rpmFourthFactName =                         "rpm4";
const char* VehicleEscStatusFactGroup::_rpmFifthFactName  =                         "rpm5";
const char* VehicleEscStatusFactGroup::_rpmSixthFactName  =                         "rpm6";
const char* VehicleEscStatusFactGroup::_rpmSeventhFactName  =                       "rpm7";
const char* VehicleEscStatusFactGroup::_rpmEighthFactName  =                        "rpm8";

const char* VehicleEscStatusFactGroup::_currentFirstFactName =                      "current1";
const char* VehicleEscStatusFactGroup::_currentSecondFactName =                     "current2";
const char* VehicleEscStatusFactGroup::_currentThirdFactName =                      "current3";
const char* VehicleEscStatusFactGroup::_currentFourthFactName =                     "current4";
const char* VehicleEscStatusFactGroup::_currentFifthFactName  =                     "current5";
const char* VehicleEscStatusFactGroup::_currentSixthFactName  =                     "current6";
const char* VehicleEscStatusFactGroup::_currentSeventhFactName  =                   "current7";
const char* VehicleEscStatusFactGroup::_currentEighthFactName  =                    "current8";

const char* VehicleEscStatusFactGroup::_voltageFirstFactName =                      "voltage1";
const char* VehicleEscStatusFactGroup::_voltageSecondFactName =                     "voltage2";
const char* VehicleEscStatusFactGroup::_voltageThirdFactName =                      "voltage3";
const char* VehicleEscStatusFactGroup::_voltageFourthFactName =                     "voltage4";
const char* VehicleEscStatusFactGroup::_voltageFifthFactName  =                     "voltage5";
const char* VehicleEscStatusFactGroup::_voltageSixthFactName  =                     "voltage6";
const char* VehicleEscStatusFactGroup::_voltageSeventhFactName  =                   "voltage7";
const char* VehicleEscStatusFactGroup::_voltageEighthFactName  =                    "voltage8";

VehicleEscStatusFactGroup::VehicleEscStatusFactGroup(QObject* parent)
    : FactGroup                         (1000, ":/json/Vehicle/EscStatusFactGroup.json", parent)
    , _indexFact                        (0, _indexFactName,                         FactMetaData::valueTypeUint8)

    , _rpmFirstFact                     (0, _rpmFirstFactName,                      FactMetaData::valueTypeFloat)
    , _rpmSecondFact                    (0, _rpmSecondFactName,                     FactMetaData::valueTypeFloat)
    , _rpmThirdFact                     (0, _rpmThirdFactName,                      FactMetaData::valueTypeFloat)
    , _rpmFourthFact                    (0, _rpmFourthFactName,                     FactMetaData::valueTypeFloat)
    , _rpmFifthFact                     (0, _rpmFifthFactName,                      FactMetaData::valueTypeFloat)
    , _rpmSixthFact                     (0, _rpmSixthFactName,                      FactMetaData::valueTypeFloat)
    , _rpmSeventhFact                   (0, _rpmSeventhFactName,                    FactMetaData::valueTypeFloat)
    , _rpmEighthFact                    (0, _rpmEighthFactName,                     FactMetaData::valueTypeFloat)

    , _currentFirstFact                 (0, _currentFirstFactName,                  FactMetaData::valueTypeFloat)
    , _currentSecondFact                (0, _currentSecondFactName,                 FactMetaData::valueTypeFloat)
    , _currentThirdFact                 (0, _currentThirdFactName,                  FactMetaData::valueTypeFloat)
    , _currentFourthFact                (0, _currentFourthFactName,                 FactMetaData::valueTypeFloat)
    , _currentFifthFact                 (0, _currentFifthFactName,                  FactMetaData::valueTypeFloat)
    , _currentSixthFact                 (0, _currentSixthFactName,                  FactMetaData::valueTypeFloat)
    , _currentSeventhFact               (0, _currentSeventhFactName,                FactMetaData::valueTypeFloat)
    , _currentEighthFact                (0, _currentEighthFactName,                 FactMetaData::valueTypeFloat)

    , _voltageFirstFact                 (0, _voltageFirstFactName,                  FactMetaData::valueTypeFloat)
    , _voltageSecondFact                (0, _voltageSecondFactName,                 FactMetaData::valueTypeFloat)
    , _voltageThirdFact                 (0, _voltageThirdFactName,                  FactMetaData::valueTypeFloat)
    , _voltageFourthFact                (0, _voltageFourthFactName,                 FactMetaData::valueTypeFloat)
    , _voltageFifthFact                 (0, _voltageFifthFactName,                  FactMetaData::valueTypeFloat)
    , _voltageSixthFact                 (0, _voltageSixthFactName,                  FactMetaData::valueTypeFloat)
    , _voltageSeventhFact               (0, _voltageSeventhFactName,                FactMetaData::valueTypeFloat)
    , _voltageEighthFact                (0, _voltageEighthFactName,                 FactMetaData::valueTypeFloat)

{
    _addFact(&_indexFact,                       _indexFactName);

    _addFact(&_rpmFirstFact,                    _rpmFirstFactName);
    _addFact(&_rpmSecondFact,                   _rpmSecondFactName);
    _addFact(&_rpmThirdFact,                    _rpmThirdFactName);
    _addFact(&_rpmFourthFact,                   _rpmFourthFactName);
    _addFact(&_rpmFifthFact,                    _rpmFifthFactName);
    _addFact(&_rpmSixthFact,                    _rpmSixthFactName);
    _addFact(&_rpmSeventhFact,                  _rpmSeventhFactName);
    _addFact(&_rpmEighthFact,                   _rpmEighthFactName);

    _addFact(&_currentFirstFact,                _currentFirstFactName);
    _addFact(&_currentSecondFact,               _currentSecondFactName);
    _addFact(&_currentThirdFact,                _currentThirdFactName);
    _addFact(&_currentFourthFact,               _currentFourthFactName);
    _addFact(&_currentFifthFact,                _currentFifthFactName);
    _addFact(&_currentSixthFact,                _currentSixthFactName);
    _addFact(&_currentSeventhFact,              _currentSeventhFactName);
    _addFact(&_currentEighthFact,               _currentEighthFactName);

    _addFact(&_voltageFirstFact,                _voltageFirstFactName);
    _addFact(&_voltageSecondFact,               _voltageSecondFactName);
    _addFact(&_voltageThirdFact,                _voltageThirdFactName);
    _addFact(&_voltageFourthFact,               _voltageFourthFactName);
    _addFact(&_voltageFifthFact,                _voltageFifthFactName);
    _addFact(&_voltageSixthFact,                _voltageSixthFactName);
    _addFact(&_voltageSeventhFact,              _voltageSeventhFactName);
    _addFact(&_voltageEighthFact,               _voltageEighthFactName);

}

void VehicleEscStatusFactGroup::handleMessage(Vehicle* /* vehicle */, mavlink_message_t& message)
{
    if (message.msgid != MAVLINK_MSG_ID_ESC_STATUS){
        return;
    } else{
        mavlink_esc_status_t content;
        mavlink_msg_esc_status_decode(&message, &content);

        index()->setRawValue                        (content.index);

        rpmFirst()->setRawValue                     (content.rpm[0]);
        rpmSecond()->setRawValue                    (content.rpm[1]);
        rpmThird()->setRawValue                     (content.rpm[2]);
        rpmFourth()->setRawValue                    (content.rpm[3]);
        rpmFifth()->setRawValue                     (content.rpm[4]);
        rpmSixth()->setRawValue                     (content.rpm[5]);
        rpmSeventh()->setRawValue                   (content.rpm[6]);
        rpmEighth()->setRawValue                    (content.rpm[7]);

        currentFirst()->setRawValue                 (content.current[0]);
        currentSecond()->setRawValue                (content.current[1]);
        currentThird()->setRawValue                 (content.current[2]);
        currentFourth()->setRawValue                (content.current[3]);
        currentFifth()->setRawValue                 (content.current[4]);
        currentSixth()->setRawValue                 (content.current[5]);
        currentSeventh()->setRawValue               (content.current[6]);
        currentEighth()->setRawValue                (content.current[7]);

        currentFirst()->setRawValue                 (content.voltage[0]);
        voltageSecond()->setRawValue                (content.voltage[1]);
        voltageThird()->setRawValue                 (content.voltage[2]);
        voltageFourth()->setRawValue                (content.voltage[3]);
        voltageFifth()->setRawValue                 (content.voltage[4]);
        voltageSixth()->setRawValue                 (content.voltage[5]);
        voltageSeventh()->setRawValue               (content.voltage[6]);
        voltageEighth()->setRawValue                (content.voltage[7]);
    }
}
