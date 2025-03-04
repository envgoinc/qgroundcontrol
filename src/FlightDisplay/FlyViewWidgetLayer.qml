/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

import QtQuick                  2.12
import QtQuick.Controls         2.4
import QtQuick.Dialogs          1.3
import QtQuick.Layouts          1.12

import QtLocation               5.3
import QtPositioning            5.3
import QtQuick.Window           2.2
import QtQml.Models             2.2

import QGroundControl               1.0
import QGroundControl.Controls      1.0
import QGroundControl.Airspace      1.0
import QGroundControl.Airmap        1.0
import QGroundControl.Controllers   1.0
import QGroundControl.Controls      1.0
import QGroundControl.FactSystem    1.0
import QGroundControl.FlightDisplay 1.0
import QGroundControl.FlightMap     1.0
import QGroundControl.Palette       1.0
import QGroundControl.ScreenTools   1.0
import QGroundControl.Vehicle       1.0
import QGroundControl.FactControls  1.0


// This is the ui overlay layer for the widgets/tools for Fly View
Item {
    id: _root

    property var    parentToolInsets
    property var    totalToolInsets:        _totalToolInsets
    property var    mapControl

    property var    _activeVehicle:         QGroundControl.multiVehicleManager.activeVehicle
    property var    _planMasterController:  globals.planMasterControllerFlyView
    property var    _missionController:     _planMasterController.missionController
    property var    _geoFenceController:    _planMasterController.geoFenceController
    property var    _rallyPointController:  _planMasterController.rallyPointController
    property var    _guidedController:      globals.guidedControllerFlyView
    property real   _margins:               ScreenTools.defaultFontPixelWidth / 2
    property real   _toolsMargin:           ScreenTools.defaultFontPixelWidth * 0.75
    property rect   _centerViewport:        Qt.rect(0, 0, width, height)
    property real   _rightPanelWidth:       ScreenTools.defaultFontPixelWidth * 30

    property string _estHeight:             _activeVehicle ? (isNaN(_activeVehicle.envgo.estHeight.rawValue)                        ? "0.0"                     :   "Est: " + _activeVehicle.envgo.estHeight.rawValue + ' ' + "cm")                                                                 : ' '
    property string _desiredHeight:         _activeVehicle ? (isNaN(_activeVehicle.envgo.desiredHeight.rawValue)                    ? "0.0"                     :   "Des: " + _activeVehicle.envgo.desiredHeight.rawValue + ' ' + "cm")                                                             : ' '
    property string _sternHeight:           _activeVehicle ? (isNaN(_activeVehicle.envgo.sternHeight.rawValue)                      ? "0.0"                     :   "Strn: " + _activeVehicle.envgo.sternHeight.rawValue + ' ' + "cm")                                                              : ' '
    property string _distanceTravelled:     _activeVehicle ? (isNaN(_activeVehicle.flightDistance.value)                            ? "FlightDistance Error"    :   _activeVehicle.flightDistance.value.toFixed(1)) + ' ' + _activeVehicle.flightDistance.units                                     : ' '
    property string _escState0:             _activeVehicle ? (isNaN(_activeVehicle.escInfo.stateFirst.value)                        ? "Esc 0: N/A"              :   "Esc 0: " + _activeVehicle.escInfo.stateFirst.value)                                                                            : ' '
    property string _escState1:             _activeVehicle ? (isNaN(_activeVehicle.escInfo.stateSecond.value)                       ? "Esc 1: N/A"              :   "Esc 1: " + _activeVehicle.escInfo.stateSecond.value)                                                                           : ' '
    property string _escState2:             _activeVehicle ? (isNaN(_activeVehicle.escInfo.stateThird.value)                        ? "Esc 2: N/A"              :   "Esc 2: " + _activeVehicle.escInfo.stateThird.value)                                                                            : ' '
    property string _escState3:             _activeVehicle ? (isNaN(_activeVehicle.escInfo.stateFourth.value)                       ? "Esc 3: N/A"              :   "Esc 3: " + _activeVehicle.escInfo.stateFourth.value)                                                                           : ' '
    property string _escState4:             _activeVehicle ? (isNaN(_activeVehicle.escInfo.stateFifth.value)                        ? "Esc 4: N/A"              :   "Esc 4: " + _activeVehicle.escInfo.stateFifth.value)                                                                            : ' '
    property string _escTemperature:        _activeVehicle ? (isNaN(_activeVehicle.escInfo.temperatureFirst.rawValue)               ? "Esc Temp: 0.0"           :   "Esc Temp: " + _activeVehicle.escInfo.temperatureFirst.rawValue) + ' ' + _activeVehicle.escInfo.temperatureFirst.units          : ' '
    property string _groundSpeed:           _activeVehicle ? (isNaN(_activeVehicle.groundSpeed.value)                               ? "0.0 m/s"                 :   _activeVehicle.groundSpeed.value.toFixed(1)) + ' ' + _activeVehicle.groundSpeed.units                                           : "Connect To Vehicle"
    property string _gear:                  _activeVehicle ? (isNaN(_activeVehicle.envgo.gear.rawValue)                             ? "N/A"                     :   _activeVehicle.envgo.gear.rawValue)                                                                                             : ' '
    property string _efficiency:            _activeVehicle ? (isNaN(_activeVehicle.envgo.efficiency.rawValue)                       ? "0.0"                     :   _activeVehicle.envgo.efficiency.rawValue) + ' ' + _activeVehicle.envgo.efficiency.units                                         : ' '
    property string _sonarFront:            _activeVehicle ? (isNaN(_activeVehicle.envgo.sonarFront.rawValue)                       ? "0.0"                     :   "Snr Bow: " + _activeVehicle.envgo.sonarFront.rawValue + ' ' + "cm")                                                            : ' '
    property string _sonarBackStarboard:    _activeVehicle ? (isNaN(_activeVehicle.envgo.sonarBackStarboard.rawValue)               ? "0.0"                     :   "Snr BackStar: " + _activeVehicle.envgo.sonarBackStarboard.rawValue + ' ' + "cm")                                               : ' '
    property string _sonarBackPort:         _activeVehicle ? (isNaN(_activeVehicle.envgo.sonarBackPort.rawValue)                    ? "0.0"                     :   "Snr BackPort: " + _activeVehicle.envgo.sonarBackPort.rawValue + ' ' + "cm")                                                    : ' '
    property string _heading:               _activeVehicle ? _activeVehicle.heading.rawValue : ' '
    

    

    // 1st Row
    // Battery Percentage
    Rectangle{
        id: batteryPercentage


        
        anchors{
            left: parent.left
            top: parent.top
        }
        MouseArea{
            anchors.fill: parent
            onClicked: (mouse)=>  {
                if (battery1PercentageInfo.font.bold == true) {
                    battery1PercentageInfo.font.bold = false
                }
                else {
                    battery1PercentageInfo.font.bold = true
                }
            }
        }

        Text {
            id: batteryPercentageTitle
            text: qsTr("Battery Percentage")
            anchors{
                top: parent.top
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 20
            font.underline: true
        }

        ColumnLayout{
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            anchors{
                        top: batteryPercentageTitle.bottom
                        left: parent.left
                        right: parent.right
                    }
            Repeater{
                model: _activeVehicle ? _activeVehicle.batteries : 0    


                delegate: Text {
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                    font.pointSize: 24
                    text: object.function.enumStringValue + ": " + object.percentRemaining.valueString + ' ' +  object.percentRemaining.units
                    color: {
                        if (object.percentRemaining.rawValue < 10){
                            return "red"
                        }
                        else if (object.percentRemaining.rawValue < 30){
                            return "gold"
                        }
                        else {
                            return "black"
                        }
                    }
                }           

            }
        }
        
        
        height: parent.height / 3
        width: parent.width / 4
        border.color: "black"
    }

    // Height Above Water
    Rectangle{
        id: heightAboveWater
        anchors{
            left: batteryPercentage.right
            top: parent.top
        }
        Text {
            id: heightAboveTheWaterTitle
            text: qsTr("Height Above Water")
            anchors{
                top: parent.top
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 20
            font.underline: true
        }
        ColumnLayout{
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            anchors{
                        top: batteryPercentageTitle.bottom
                        left: parent.left
                        right: parent.right
                    }
            Text {
                id: desHeight
                anchors{
                    top: heightAboveTheWaterTitle.bottom
                    bottom: parent.bottom
                    left: parent.left
                    right: parent.right
                }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.bold: true
                font.pointSize: 20
                text:_desiredHeight
            }
            
            Text {
                id:estHeight
                anchors{
                    top: desHeight.bottom
                    // bottom: parent.bottom
                    left: parent.left
                    right: parent.right
                }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.bold: true
                font.pointSize: 20
                text: _estHeight
            }

            Text {
                anchors{
                    top: estHeight.bottom
                    // bottom: parent.bottom
                    left: parent.left
                    right: parent.right
                }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.bold: true
                font.pointSize: 20
                text: _sternHeight
            }
        }
        height: parent.height / 3
        width: parent.width / 4
        color: "transparent"
        border.color: "black"
    }

    // Distance Travelled
    Rectangle{
        id: distanceTravelled
        anchors{
            left: heightAboveWater.right
            top: parent.top
        }
        Text {
            id: distanceTravelledTitle
            text: qsTr("Distance Travelled")
            anchors{
                top: parent.top
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 20
            font.underline: true
        }
        Text {
            anchors{
                top: distanceTravelledTitle.bottom
                bottom: parent.bottom
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.pointSize: 30
            text: _distanceTravelled
        }
        height: parent.height / 3
        width: parent.width / 4
        color: "transparent"
        border.color: "black"
    }

    // ESC State
    Rectangle{
        id: escState
        anchors{
            left: distanceTravelled.right
            top: parent.top
        }
        Text {
            id: escStateTitle
            text: qsTr("ESC State")
            anchors{
                top: parent.top
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 20
            font.underline: true
        }
        Text {
            id:state0
            anchors{
                top: escStateTitle.bottom
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.pointSize: 20
            text: _escState0
        }
        Text {
            id:state1
            anchors{
                top: state0.bottom
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.pointSize: 20 
            text: _escState1
        }
        Text {
            id:state2
            anchors{
                top: state1.bottom
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.pointSize: 20
            text: _escState2
        }
        Text {
            id:state3
            anchors{
                top: state2.bottom
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.pointSize: 20
            text: _escState3
        }
        Text {
            id:state4
            anchors{
                top: state3.bottom
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.pointSize: 20
            text: _escState4
        }
        height: parent.height / 3
        width: parent.width / 4
        color: "transparent"
        border.color: "black"
    }

    // 2nd Row
    // Temperature
    Rectangle{
        id: temperature
        anchors{
            left: parent.left
            top: batteryPercentage.bottom
        }
        Text {
            id: temperatureTitle
            text: qsTr("Temperature")
            anchors{
                top: parent.top
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 20
            font.underline: true
        }
        Text {
            id: escTempinfo
            anchors{
                top: temperatureTitle.bottom
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.pointSize: 24
            text: _escTemperature
        }
        ColumnLayout{
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            anchors{
                        top: escTempinfo.bottom
                        left: parent.left
                        right: parent.right
                    }
            Repeater{
                model: _activeVehicle ? _activeVehicle.batteries : 0    
                delegate: Text {
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                    font.pointSize: 20
                    text: object.function.enumStringValue + ": " + object.temperature.rawValue + ' ' + object.temperature.units
                }           

            }
        }
        height: parent.height / 3
        width: parent.width / 4
        color: "transparent"
        border.color: "black"
    }

    // Speed
    Rectangle{
        id: speed
        anchors{
            left: temperature.right
            top: heightAboveWater.bottom
        }
        Text {
            id: speedTitle
            text: qsTr("Speed")
            anchors{
                top: parent.top
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 20
            font.underline: true
        }
       
        Text {
            id: groundSpeed
            anchors{
                top: speedTitle.bottom
                bottom: parent.bottom
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.pointSize: 44
            text: _groundSpeed
        }
        GuidedActionConfirm {
            anchors{
                top: speedTitle.bottom
                bottom: parent.bottom
                left: parent.left
                right: parent.right
            }
            Layout.fillWidth:   true
            guidedController:   _guidedController
            guidedValueSlider:     _guidedValueSlider
        }
        height: parent.height / 3
        width: parent.width / 2
        color: "transparent"
        border.color: "black"
    }

    // Stats
    Rectangle{
        id: stats
        anchors{
            left: speed.right
            top: heightAboveWater.bottom
        }
        Text {
            id: statsTitle
            text: qsTr("Stats")
            anchors{
                top: parent.top
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 20
            font.underline: true
        }
        Text {
            id:sonarFront
            anchors{
                top: statsTitle.bottom
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 20
            font.bold: true
            text: _sonarFront
        }
        Text {
            id:sonarBackStarboard
            anchors{
                top: sonarFront.bottom
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 20
            font.bold: true
            text: _sonarBackStarboard
        }
        Text {
            id:sonarBackPort
            anchors{
                top: sonarBackStarboard.bottom
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 20
            font.bold: true
            text: _sonarBackPort
        }
        TelemetryValuesBar {
            id:                 telemetryPanel
            x:                  recalcXPosition()
            anchors.top:        statsTitle
            anchors.bottom:     parent.bottom
            anchors.left:       parent.left
            anchors.right:      parent.right
            // States for custom layout support
            states: [
                State {
                    name: "bottom"
                    when: telemetryPanel.bottomMode
                    AnchorChanges {
                        target:                 telemetryPanel
                        anchors.top:            undefined
                        anchors.bottom:         parent.bottom
                        anchors.left:           parent.left
                        anchors.right:          parent.right
                        anchors.verticalCenter: undefined
                    }
                    PropertyChanges {
                        target: telemetryPanel
                        x: recalcXPosition()
                    }
                },
                State {
                    name: "right-video"
                    when: !telemetryPanel.bottomMode && photoVideoControl.visible
                    AnchorChanges {
                        target: telemetryPanel
                        anchors.top: photoVideoControl.bottom
                        anchors.bottom: undefined
                        anchors.right: parent.right
                        anchors.verticalCenter: undefined
                    }
                },
                State {
                    name: "right-novideo"
                    when: !telemetryPanel.bottomMode && !photoVideoControl.visible
                    AnchorChanges {
                        target:                 telemetryPanel
                        anchors.top:            undefined
                        anchors.bottom:         undefined
                        anchors.left:           parent.left
                        anchors.right:          parent.right
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }
            ]
            function recalcXPosition() {
                // First try centered
                var halfRootWidth   = _root.width / 2
                var halfPanelWidth  = telemetryPanel.width / 2
                var leftX           = (halfRootWidth - halfPanelWidth) - _toolsMargin
                var rightX          = (halfRootWidth + halfPanelWidth) + _toolsMargin
                if (leftX >= parentToolInsets.leftEdgeBottomInset || rightX <= parentToolInsets.rightEdgeBottomInset ) {
                    // It will fit in the horizontalCenter
                    return halfRootWidth - halfPanelWidth
                } else {
                    // Anchor to left edge
                    return parentToolInsets.leftEdgeBottomInset + _toolsMargin
                }
            }
        } 
        height: parent.height / 3
        width: parent.width / 4
        color: "transparent"
        border.color: "black"
    }

    // 3rd Row
    // Gear
    Rectangle{
        id: gear
        anchors{
            left: parent.left
            top: temperature.bottom
        }
        color: {
            switch (_gear - 0) {
                case 0: return "light blue"
                case 1: return "green"
                case -1: return "yellow"
            }
        }
        Text {
            id: gearTitle
            text: qsTr("Gear")
            anchors{
                top: parent.top
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 20
            font.underline: true
        }
        Text {
            anchors{
                top: gearTitle.bottom
                bottom: parent.bottom
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.pointSize: 30
            text: {
                if (_gear != ' '){
                    switch (_gear - 0) {
                        case 0: return "N"
                        case 1: return "F"
                        case -1: return "R"
                    }
                }
                
            }
        }
        height: parent.height / 3
        width: parent.width / 4
        //color: "transparent"
        border.color: "black"
    }

    // Electrical Power
    Rectangle{
        id: electricalPower
        anchors{
            left: gear.right
            top: speed.bottom
        }
        Text {
            id: electricalPowerTitle
            text: qsTr("Electrical Power")
            anchors{
                top: parent.top
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 20
            font.underline: true
        }
        ColumnLayout{
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            anchors{
                        top: electricalPowerTitle.bottom
                        left: parent.left
                        right: parent.right
                    }
            Repeater{
                model: _activeVehicle ? _activeVehicle.batteries : 0    


                delegate: Text {
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                    font.pointSize: 20
                    text: object.function.enumStringValue + ": " + object.instantPower.rawValue  + " W"
                }           

            }
        }
        height: parent.height / 3
        width: parent.width / 4
        color: "transparent"
        border.color: "black"
    }

    //Efficiency
    Rectangle{
        id: efficiency
        anchors{
            left: electricalPower.right
            top: speed.bottom
        }
        Text {
            id: efficiencyTitle
            text: qsTr("Efficiency")
            anchors{
                top: parent.top
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 20
            font.underline: true
        }
        Text {
            anchors{
                top: efficiencyTitle.bottom
                bottom: parent.bottom
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.pointSize: 30
            text: _efficiency
        }
        height: parent.height / 3
        width: parent.width / 4
        color: "transparent"
        border.color: "black"
    }

    // Nav
    Rectangle{
        id: nav
        anchors{
            left: efficiency.right
            top: stats.bottom
        }
        Text {
            id: navTitle
            text: qsTr("Nav")
            anchors{
                top: parent.top
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 20
            font.underline: true
        }
        Text {
            id: navDeg
            anchors{
                top: navTitle.bottom
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.pointSize: 30
            text: _heading
        }
        Text {
            anchors{
                top: navDeg.bottom
                bottom: parent.bottom
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.pointSize: 30
            text: {
                if (_heading != ' ') {
                    var a = _heading % 45
                    switch(_heading - a) {
                        case 0:     return "N"
                        case 45:    return "NE"
                        case 90:    return "E"
                        case 135:   return "SE"
                        case 180:   return "S"
                        case 225:   return "SW"
                        case 270:   return "W"
                        case 315:   return "NW"
                    }
                    return "ERROR"
                }
                else {
                    return ' '
                }
                 
            }
        }
        height: parent.height / 3
        width: parent.width / 4
        color: "transparent"
        border.color: "black"
        
    }

    Component {
        id: preFlightChecklistPopup
        FlyViewPreFlightChecklistPopup {
        }
    }

}