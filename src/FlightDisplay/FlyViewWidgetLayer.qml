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

    property string _estHeight:             _activeVehicle ? (isNaN(_activeVehicle.envgo.estHeight.rawValue) ? "0.0" :"Est: " +  _activeVehicle.envgo.estHeight.rawValue + ' ' + _activeVehicle.envgo.estHeight.units) : ' '
    property string _desiredHeight:         _activeVehicle ? (isNaN(_activeVehicle.envgo.desiredHeight.rawValue) ? "0.0" : "Des: " + _activeVehicle.envgo.desiredHeight.rawValue + ' ' + _activeVehicle.envgo.desiredHeight.units) : ' '
    property string _distanceTravelled:     _activeVehicle ? (isNaN(_activeVehicle.flightDistance.value) ? "FlightDistance Error" : _activeVehicle.flightDistance.value.toFixed(1)) + ' ' + _activeVehicle.flightDistance.units : ' '
    property string _flightMode:            _activeVehicle ? _activeVehicle.flightMode : ' '
    property string _escTemperature:        _activeVehicle ? (isNaN(_activeVehicle.escInfo.temperatureFirst.rawValue) ? "Esc Temp: 0.0" :"Esc Temp: " + _activeVehicle.escInfo.temperatureFirst.rawValue) + ' ' + _activeVehicle.escInfo.temperatureFirst.units : ' '
    property string _batteryTemperature:    _activeVehicle ? (isNaN(globals.activeVehicle.batteries.get(1).temperature.rawValue) ? "0.0" : globals.activeVehicle.batteries.get(1).temperature.rawValue) + ' ' + globals.activeVehicle.batteries.get(1).temperature.units : ' '
    property string _groundSpeed:           _activeVehicle ? (isNaN(_activeVehicle.groundSpeed.value) ? "0.0 m/s" : _activeVehicle.groundSpeed.value.toFixed(1)) + ' ' + _activeVehicle.groundSpeed.units : "Connect To Vehicle"
    property string _gear:                  _activeVehicle ? (isNaN(_activeVehicle.envgo.gear.rawValue) ? "N/A" :  _activeVehicle.envgo.gear.rawValue) : ' '
    property string _efficiency:            _activeVehicle ? (isNaN(_activeVehicle.envgo.efficiency.rawValue) ? "0.0" : _activeVehicle.envgo.efficiency.rawValue) + ' ' + _activeVehicle.envgo.efficiency.units : ' '
    property string _heading:               _activeVehicle   ? _activeVehicle.heading.rawValue : ' '
    

    

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
                //verticalAlignment: Text.AlignVCenter
                font.bold: true
                font.pointSize: 30
                text:_desiredHeight
            }
            
            Text {
                anchors{
                    top: desHeight.bottom
                    bottom: parent.bottom
                    left: parent.left
                    right: parent.right
                }
                horizontalAlignment: Text.AlignHCenter
                //verticalAlignment: Text.AlignVCenter
                font.bold: true
                font.pointSize: 30
                text: _estHeight
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

    // Flight Mode
    Rectangle{
        id: flightMode
        anchors{
            left: distanceTravelled.right
            top: parent.top
        }
        Text {
            id: flightModeTitle
            text: qsTr("Flight Mode")
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
                top: flightModeTitle.bottom
                bottom: parent.bottom
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.pointSize: 30
            text: _flightMode
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
        color: "transparent"
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

    






//     QGCToolInsets {
//         id:                     _totalToolInsets
//         // leftEdgeTopInset:       toolStrip.leftInset
//         // leftEdgeCenterInset:    toolStrip.leftInset
//         leftEdgeBottomInset:    parentToolInsets.leftEdgeBottomInset
//         rightEdgeTopInset:      parentToolInsets.rightEdgeTopInset
//         rightEdgeCenterInset:   parentToolInsets.rightEdgeCenterInset
//         rightEdgeBottomInset:   parentToolInsets.rightEdgeBottomInset
//         topEdgeLeftInset:       parentToolInsets.topEdgeLeftInset
//         topEdgeCenterInset:     parentToolInsets.topEdgeCenterInset
//         topEdgeRightInset:      parentToolInsets.topEdgeRightInset
//         bottomEdgeLeftInset:    parentToolInsets.bottomEdgeLeftInset
//         bottomEdgeCenterInset:  mapScale.centerInset
//         bottomEdgeRightInset:   0
//     }
//     FlyViewMissionCompleteDialog {
//         missionController:      _missionController
//         geoFenceController:     _geoFenceController
//         rallyPointController:   _rallyPointController
//     }
//     Row {
//         id:                 multiVehiclePanelSelector
//         anchors.margins:    _toolsMargin
//         anchors.top:        parent.top
//         anchors.right:      parent.right
//         width:              _rightPanelWidth
//         spacing:            ScreenTools.defaultFontPixelWidth
//         visible:            QGroundControl.multiVehicleManager.vehicles.count > 1 && QGroundControl.corePlugin.options.flyView.showMultiVehicleList
//         property bool showSingleVehiclePanel:  !visible || singleVehicleRadio.checked
//         QGCMapPalette { id: mapPal; lightColors: true }
//         QGCRadioButton {
//             id:             singleVehicleRadio
//             text:           qsTr("Single")
//             checked:        true
//             textColor:      mapPal.text
//         }
//         QGCRadioButton {
//             text:           qsTr("Multi-Vehicle")
//             textColor:      mapPal.text
//         }
//     }
    
    
    
//     MultiVehicleList {
//         anchors.margins:    _toolsMargin
//         //anchors.top:        multiVehiclePanelSelector.bottom
//         //anchors.right:      parent.right
//         width:              _rightPanelWidth
//         height:             parent.height - y - _toolsMargin
//         visible:            !multiVehiclePanelSelector.showSingleVehiclePanel
//     } 
    
    
//     PhotoVideoControl {
//         id:                     photoVideoControl
//         anchors.margins:        _toolsMargin
//         anchors.right:          parent.right
//         width:                  _rightPanelWidth
//         state:                  _verticalCenter ? "verticalCenter" : "topAnchor"
//         states: [
//             State {
//                 name: "verticalCenter"
//                 AnchorChanges {
//                     target:                 photoVideoControl
//                     anchors.top:            undefined
//                     anchors.verticalCenter: _root.verticalCenter
//                 }
//             },
//             State {
//                 name: "topAnchor"
//                 AnchorChanges {
//                     target:                 photoVideoControl
//                     anchors.verticalCenter: undefined
//                     anchors.top:            instrumentPanel.bottom
//                 }
//             }
//         ]
//         property bool _verticalCenter: !QGroundControl.settingsManager.flyViewSettings.alternateInstrumentPanel.rawValue
//     }

//     //-- Virtual Joystick

//     Loader {
//         id:                         virtualJoystickMultiTouch
//         z:                          QGroundControl.zOrderTopMost + 1
//         width:                      parent.width  - (_pipOverlay.width / 2)
//         height:                     Math.min(parent.height * 0.25, ScreenTools.defaultFontPixelWidth * 16)
//         visible:                    _virtualJoystickEnabled && !QGroundControl.videoManager.fullScreen && !(_activeVehicle ? _activeVehicle.usingHighLatencyLink : false)
//         anchors.bottom:             parent.bottom
//         anchors.bottomMargin:       parentToolInsets.leftEdgeBottomInset + ScreenTools.defaultFontPixelHeight * 2
//         anchors.horizontalCenter:   parent.horizontalCenter
//         source:                     "qrc:/qml/VirtualJoystick.qml"
//         active:                     _virtualJoystickEnabled && !(_activeVehicle ? _activeVehicle.usingHighLatencyLink : false)
//         property bool autoCenterThrottle: QGroundControl.settingsManager.appSettings.virtualJoystickAutoCenterThrottle.rawValue
//         property bool _virtualJoystickEnabled: QGroundControl.settingsManager.appSettings.virtualJoystick.rawValue
//     }
    
//     FlyViewToolStrip {
//         id:                     toolStrip
//         anchors.leftMargin:     _toolsMargin + parentToolInsets.leftEdgeCenterInset
//         anchors.topMargin:      _toolsMargin + parentToolInsets.topEdgeLeftInset
//         anchors.left:           parent.left
//         anchors.top:            parent.top
//         z:                      QGroundControl.zOrderWidgets
//         maxHeight:              parent.height - y - parentToolInsets.bottomEdgeLeftInset - _toolsMargin
//         visible:                !QGroundControl.videoManager.fullScreen
//         onDisplayPreFlightChecklist: preFlightChecklistPopup.createObject(mainWindow).open()
//         property real leftInset: x + width
//     }
    

//     FlyViewAirspaceIndicator {
//         anchors.top:                parent.top
//         anchors.topMargin:          ScreenTools.defaultFontPixelHeight * 0.25
//         anchors.horizontalCenter:   parent.horizontalCenter
//         z:                          QGroundControl.zOrderWidgets
//         show:                       mapControl.pipState.state !== mapControl.pipState.pipState
//     }
//     VehicleWarnings {
//         anchors.centerIn:   parent
//         z:                  QGroundControl.zOrderTopMost
//     }
//     MapScale {
//         id:                 mapScale
//         anchors.margins:    _toolsMargin
//         anchors.left:       toolStrip.right
//         anchors.top:        parent.top
//         mapControl:         _mapControl
//         buttonsOnLeft:      false
//         visible:            !ScreenTools.isTinyScreen && QGroundControl.corePlugin.options.flyView.showMapScale && mapControl.pipState.state === mapControl.pipState.fullState
//         property real centerInset: visible ? parent.height - y : 0
//     }
}
    