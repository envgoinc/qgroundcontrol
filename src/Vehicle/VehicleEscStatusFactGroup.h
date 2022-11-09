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

    Q_PROPERTY(Fact* index              READ index              CONSTANT)

    Q_PROPERTY(Fact* rpmFirst           READ rpmFirst           CONSTANT)
    Q_PROPERTY(Fact* rpmSecond          READ rpmSecond          CONSTANT)
    Q_PROPERTY(Fact* rpmThird           READ rpmThird           CONSTANT)
    Q_PROPERTY(Fact* rpmFourth          READ rpmFourth          CONSTANT)
    Q_PROPERTY(Fact* rpmFifth           READ rpmFifth           CONSTANT)
    Q_PROPERTY(Fact* rpmSixth           READ rpmSixth           CONSTANT)
    Q_PROPERTY(Fact* rpmSeventh         READ rpmSeventh         CONSTANT)
    Q_PROPERTY(Fact* rpmEighth          READ rpmEighth          CONSTANT)

    Q_PROPERTY(Fact* currentFirst       READ currentFirst       CONSTANT)
    Q_PROPERTY(Fact* currentSecond      READ currentSecond      CONSTANT)
    Q_PROPERTY(Fact* currentThird       READ currentThird       CONSTANT)
    Q_PROPERTY(Fact* currentFourth      READ currentFourth      CONSTANT)
    Q_PROPERTY(Fact* currentFifth       READ currentFifth       CONSTANT)
    Q_PROPERTY(Fact* currentSixth       READ currentSixth       CONSTANT)
    Q_PROPERTY(Fact* currentSeventh     READ currentSeventh     CONSTANT)
    Q_PROPERTY(Fact* currentEighth      READ currentEighth      CONSTANT)

    Q_PROPERTY(Fact* voltageFirst       READ voltageFirst       CONSTANT)
    Q_PROPERTY(Fact* voltageSecond      READ voltageSecond      CONSTANT)
    Q_PROPERTY(Fact* voltageThird       READ voltageThird       CONSTANT)
    Q_PROPERTY(Fact* voltageFourth      READ voltageFourth      CONSTANT)
    Q_PROPERTY(Fact* voltageFifth       READ voltageFifth       CONSTANT)
    Q_PROPERTY(Fact* voltageSixth       READ voltageSixth       CONSTANT)
    Q_PROPERTY(Fact* voltageSeventh     READ voltageSeventh     CONSTANT)
    Q_PROPERTY(Fact* voltageEighth      READ voltageEighth      CONSTANT)


    Fact* index                         () { return &_indexFact; }

    Fact* rpmFirst                      () { return &_rpmFirstFact; }
    Fact* rpmSecond                     () { return &_rpmSecondFact; }
    Fact* rpmThird                      () { return &_rpmThirdFact; }
    Fact* rpmFourth                     () { return &_rpmFourthFact; }
    Fact* rpmFifth                      () { return &_rpmFifthFact; }
    Fact* rpmSixth                      () { return &_rpmSixthFact; }
    Fact* rpmSeventh                    () { return &_rpmSeventhFact; }
    Fact* rpmEighth                     () { return &_rpmEighthFact; }

    Fact* currentFirst                  () { return &_currentFirstFact; }
    Fact* currentSecond                 () { return &_currentSecondFact; }
    Fact* currentThird                  () { return &_currentThirdFact; }
    Fact* currentFourth                 () { return &_currentFourthFact; }
    Fact* currentFifth                  () { return &_currentFifthFact; }
    Fact* currentSixth                  () { return &_currentSixthFact; }
    Fact* currentSeventh                () { return &_currentSeventhFact; }
    Fact* currentEighth                 () { return &_currentEighthFact; }

    Fact* voltageFirst                  () { return &_voltageFirstFact; }
    Fact* voltageSecond                 () { return &_voltageSecondFact; }
    Fact* voltageThird                  () { return &_voltageThirdFact; }
    Fact* voltageFourth                 () { return &_voltageFourthFact; }
    Fact* voltageFifth                  () { return &_voltageFifthFact; }
    Fact* voltageSixth                  () { return &_voltageSixthFact; }
    Fact* voltageSeventh                () { return &_voltageSeventhFact; }
    Fact* voltageEighth                 () { return &_voltageEighthFact; }
    
    // Overrides from FactGroup
    void handleMessage(Vehicle* vehicle, mavlink_message_t& message) override;

    
    static const char* _indexFactName;

    static const char* _rpmFirstFactName;
    static const char* _rpmSecondFactName;
    static const char* _rpmThirdFactName;
    static const char* _rpmFourthFactName;
    static const char* _rpmFifthFactName;
    static const char* _rpmSixthFactName;
    static const char* _rpmSeventhFactName;
    static const char* _rpmEighthFactName;

    static const char* _currentFirstFactName;
    static const char* _currentSecondFactName;
    static const char* _currentThirdFactName;
    static const char* _currentFourthFactName;
    static const char* _currentFifthFactName;
    static const char* _currentSixthFactName;
    static const char* _currentSeventhFactName;
    static const char* _currentEighthFactName;

    static const char* _voltageFirstFactName;
    static const char* _voltageSecondFactName;
    static const char* _voltageThirdFactName;
    static const char* _voltageFourthFactName;
    static const char* _voltageFifthFactName;
    static const char* _voltageSixthFactName;
    static const char* _voltageSeventhFactName;
    static const char* _voltageEighthFactName;

private:
    Fact _indexFact;

    Fact _rpmFirstFact;
    Fact _rpmSecondFact;
    Fact _rpmThirdFact;
    Fact _rpmFourthFact;
    Fact _rpmFifthFact;
    Fact _rpmSixthFact;
    Fact _rpmSeventhFact;
    Fact _rpmEighthFact;

    Fact _currentFirstFact;
    Fact _currentSecondFact;
    Fact _currentThirdFact;
    Fact _currentFourthFact;
    Fact _currentFifthFact;
    Fact _currentSixthFact;
    Fact _currentSeventhFact;
    Fact _currentEighthFact;

    Fact _voltageFirstFact;
    Fact _voltageSecondFact;
    Fact _voltageThirdFact;
    Fact _voltageFourthFact;
    Fact _voltageFifthFact;
    Fact _voltageSixthFact;
    Fact _voltageSeventhFact;
    Fact _voltageEighthFact;

};
