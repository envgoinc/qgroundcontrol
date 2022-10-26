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

//import "androidwidgets.h"

//import <EnvgoFactGroup.h>

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
    property string _groundSpeed:          _activeVehicle ? (isNaN(_activeVehicle.groundSpeed.value) ? "0.0" : _activeVehicle.groundSpeed.value.toFixed(1)) + ' ' + _activeVehicle.groundSpeed.units : "0.0"
    property string _heading:              _activeVehicle   ? _activeVehicle.heading.rawValue : 0
    Rectangle{
        id: batteryPercentage


        
        anchors{
            left: parent.left
            top: parent.top
        }
        MouseArea{
            anchors.fill: parent
            onClicked: (mouse)=>  {
                if (batteryPercentageInfo.font.bold == true) {
                    batteryPercentageInfo.font.bold = false
                }
                else {
                    batteryPercentageInfo.font.bold = true
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
        Text {
            id: batteryPercentageInfo
            anchors{
                top: batteryPercentageTitle.bottom
                bottom: parent.bottom
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.pointSize: 30
            text: getBatteryPercentageText()
        } 
        height: parent.height / 3
        width: parent.width / 4
        color: "transparent"
        border.color: "black"
    }
    Rectangle{
        id: heightAboveWater
        anchors{
            left: batteryPercentage.right
            top: parent.top
        }
        Text {
            id: heightAboveTheWaterTitle
            text: qsTr("Height Above The Water")
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
                top: heightAboveTheWaterTitle.bottom
                bottom: parent.bottom
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.pointSize: 30
            text: qsTr("2 cm")
        }
        height: parent.height / 3
        width: parent.width / 4
        color: "transparent"
        border.color: "black"
    }
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
            text: qsTr("4.55 km")
        }
        height: parent.height / 3
        width: parent.width / 4
        color: "transparent"
        border.color: "black"
    }
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
            text: qsTr("Flight Mode 1")
        }
        height: parent.height / 3
        width: parent.width / 4
        color: "transparent"
        border.color: "black"
    }
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
            anchors{
                top: temperatureTitle.bottom
                bottom: parent.bottom
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.pointSize: 30
            text: qsTr("50 deg c")
        }
        height: parent.height / 3
        width: parent.width / 4
        color: "transparent"
        border.color: "black"
    }
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
            anchors{
                top: speedTitle.bottom
                bottom: parent.bottom
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.pointSize: 30
            text: _groundSpeed
        }
        height: parent.height / 3
        width: parent.width / 2
        color: "transparent"
        border.color: "black"
    }
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
            anchors{
                top: statsTitle.bottom
                bottom: parent.bottom
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.pointSize: 30
            text: qsTr("fake stat 1")
        }
        height: parent.height / 3
        width: parent.width / 4
        color: "transparent"
        border.color: "black"
    }
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
            text: qsTr("FWD")
        }
        height: parent.height / 3
        width: parent.width / 4
        color: "transparent"
        border.color: "black"
    }
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
        Text {
            anchors{
                top: electricalPowerTitle.bottom
                bottom: parent.bottom
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.pointSize: 30
            text: qsTr("30 Watts")
        }
        height: parent.height / 3
        width: parent.width / 4
        color: "transparent"
        border.color: "black"
    }
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
            text: qsTr("30%")
        }
        height: parent.height / 3
        width: parent.width / 4
        color: "transparent"
        border.color: "black"
    }
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
            anchors{
                top: navTitle.bottom
                bottom: parent.bottom
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.pointSize: 30
            text: _heading
        }
        height: parent.height / 3
        width: parent.width / 4
        color: "transparent"
        border.color: "black"
    }

    // TelemetryValuesBar {
    //     id:                 telemetryPanel
    //     x:                  recalcXPosition()
    //     anchors.bottom:     parent.bottom
    //     anchors.left:       parent.left
    //     anchors.right:      parent.right
    //     // States for custom layout support
    //     states: [
    //         State {
    //             name: "bottom"
    //             when: telemetryPanel.bottomMode
    //             AnchorChanges {
    //                 target:                 telemetryPanel
    //                 anchors.top:            undefined
    //                 anchors.bottom:         parent.bottom
    //                 anchors.left:           parent.left
    //                 anchors.right:          parent.right
    //                 anchors.verticalCenter: undefined
    //             }
    //             PropertyChanges {
    //                 target: telemetryPanel
    //                 x: recalcXPosition()
    //             }
    //         },
    //         State {
    //             name: "right-video"
    //             when: !telemetryPanel.bottomMode && photoVideoControl.visible
    //             AnchorChanges {
    //                 target: telemetryPanel
    //                 anchors.top: photoVideoControl.bottom
    //                 anchors.bottom: undefined
    //                 anchors.right: parent.right
    //                 anchors.verticalCenter: undefined
    //             }
    //         },
    //         State {
    //             name: "right-novideo"
    //             when: !telemetryPanel.bottomMode && !photoVideoControl.visible
    //             AnchorChanges {
    //                 target:                 telemetryPanel
    //                 anchors.top:            undefined
    //                 anchors.bottom:         undefined
    //                 anchors.left:           parent.left
    //                 anchors.right:          parent.right
    //                 anchors.verticalCenter: parent.verticalCenter
    //             }
    //         }
    //     ]
    //     function recalcXPosition() {
    //         // First try centered
    //         var halfRootWidth   = _root.width / 2
    //         var halfPanelWidth  = telemetryPanel.width / 2
    //         var leftX           = (halfRootWidth - halfPanelWidth) - _toolsMargin
    //         var rightX          = (halfRootWidth + halfPanelWidth) + _toolsMargin
    //         if (leftX >= parentToolInsets.leftEdgeBottomInset || rightX <= parentToolInsets.rightEdgeBottomInset ) {
    //             // It will fit in the horizontalCenter
    //             return halfRootWidth - halfPanelWidth
    //         } else {
    //             // Anchor to left edge
    //             return parentToolInsets.leftEdgeBottomInset + _toolsMargin
    //         }
    //     }
    // } 






/*    QGCToolInsets {
        id:                     _totalToolInsets
        // leftEdgeTopInset:       toolStrip.leftInset
        // leftEdgeCenterInset:    toolStrip.leftInset
        leftEdgeBottomInset:    parentToolInsets.leftEdgeBottomInset
        rightEdgeTopInset:      parentToolInsets.rightEdgeTopInset
        rightEdgeCenterInset:   parentToolInsets.rightEdgeCenterInset
        rightEdgeBottomInset:   parentToolInsets.rightEdgeBottomInset
        topEdgeLeftInset:       parentToolInsets.topEdgeLeftInset
        topEdgeCenterInset:     parentToolInsets.topEdgeCenterInset
        topEdgeRightInset:      parentToolInsets.topEdgeRightInset
        bottomEdgeLeftInset:    parentToolInsets.bottomEdgeLeftInset
        bottomEdgeCenterInset:  mapScale.centerInset
        bottomEdgeRightInset:   0
    }
    FlyViewMissionCompleteDialog {
        missionController:      _missionController
        geoFenceController:     _geoFenceController
        rallyPointController:   _rallyPointController
    }
    Row {
        id:                 multiVehiclePanelSelector
        anchors.margins:    _toolsMargin
        anchors.top:        parent.top
        anchors.right:      parent.right
        width:              _rightPanelWidth
        spacing:            ScreenTools.defaultFontPixelWidth
        visible:            QGroundControl.multiVehicleManager.vehicles.count > 1 && QGroundControl.corePlugin.options.flyView.showMultiVehicleList
        property bool showSingleVehiclePanel:  !visible || singleVehicleRadio.checked
        QGCMapPalette { id: mapPal; lightColors: true }
        QGCRadioButton {
            id:             singleVehicleRadio
            text:           qsTr("Single")
            checked:        true
            textColor:      mapPal.text
        }
        QGCRadioButton {
            text:           qsTr("Multi-Vehicle")
            textColor:      mapPal.text
        }
    }
    
    //Sizing
    property double workingHeight : parent.Height
    property double workingWidth : parent.width
    Column{
        Row {
            ColumnLayout{
                QGCButton{
                    id: batteryButton
                    text: qsTr("Battery \n\n56%")
                    background: Rectangle {
                        implicitWidth: workingWidth / 4
                        implicitHeight: 200
                        opacity: enabled ? 1.0 : 0.3
                        border.width: 1
                        border.color: control.down ? "#17a81a" : "#21be2b"
                    }
                    
                }
                /*QGCLabel{
                    anchors.centerIn: parent
                    //Layout.preferredHeight: workingHeight /6
                    text: qsTr("54%")
                    font.pixelSize: 22
                } */
            }

  /*          QGCButton{
                text: "Height Above\n Water\n\n5.2m"
                font.pixelSize: 32
                background: Rectangle {
                    implicitWidth: workingWidth / 4
                    implicitHeight: 200
                    opacity: enabled ? 1.0 : 0.3
                    border.width: 1
                    border.color: control.down ? "#17a81a" : "#21be2b"
                }
            }
            //Distance Related Information
            ColumnLayout{
                QGCButton{
                    text: "Distance\n Travelled\n5.2m; 60 min \n30 seconds"
                    background: Rectangle {
                        implicitWidth: workingWidth / 4
                        implicitHeight: 200
                        opacity: enabled ? 1.0 : 0.3
                        border.width: 1
                        border.color: control.down ? "#17a81a" : "#21be2b"
                    }
                }
                /*QGCLabel{
                    anchors.centerIn: parent
                    //Layout.preferredHeight: workingHeight /6
                    text: qsTr("5.2m\n60 min 30 seconds")
                    font.pixelSize: 22
                }
            }
      /*
            //Flight Mode Related Information
            Frame {
                ColumnLayout{
                    QGCLabel{
                        text: qsTr("Flight Mode")
                    } 
                    QGCComboBox{
                        id: controller
                        Layout.preferredWidth: workingWidth / 4
                        //Layout.preferredHeight: workingHeight / 3
                        model: ListModel {
                            ListElement {
                                text: "Flight Mode 1"
                            }
                            ListElement {
                                text: "Flight Mode 2"
                            }
                            ListElement {
                                text: "Flight Mode 3"
                            }
                            ListElement {
                                text: "Flight Mode 4 "
                            }
                        }
                    }
                }
            }  
        }
        Row {
            ColumnLayout{
                QGCButton{
                    text: "Temperature"
                    background: Rectangle {
                        implicitWidth: workingWidth / 4
                        implicitHeight: 300
                        opacity: enabled ? 1.0 : 0.3
                        border.width: 1
                        border.color: control.down ? "#17a81a" : "#21be2b"
                    }
                }
                /*QGCLabel{
                    anchors.centerIn: parent
                    //Layout.preferredHeight: workingHeight /6
                    text: qsTr("45 degrees C")
                    font.pixelSize: 22
                }
            }
            // Speed Button
            ColumnLayout {
                QGCButton{
                    //id: speedDisplay
                    text: "Speed"//\n\n" + globals.activeVehicle.groundSpeed.value + "km";
                    background: Rectangle {
                        implicitWidth: workingWidth / 2
                        implicitHeight: 300
                        opacity: enabled ? 1.0 : 0.3
                        border.width: 1
                        border.color: control.down ? "#17a81a" : "#21be2b"
                    }
                }
                /*QGCLabel{
                    anchors.centerIn: parent
                    //Layout.preferredHeight: workingHeight /6
                    text: qsTr("Very Fast")
                    font.pixelSize: 22
                }
            }
/*
            ColumnLayout{
                QGCButton{
                    text: "Statistics"
                    background: Rectangle {
                        implicitWidth: workingWidth / 4
                        implicitHeight: 300
                        opacity: enabled ? 1.0 : 0.3
                        border.width: 1
                        border.color: control.down ? "#17a81a" : "#21be2b"
                    }
                }/*
                QGCLabel{
                    anchors.centerIn: parent
                    //Layout.preferredHeight: workingHeight /6
                    text: qsTr("Fake Stat 1 \nFake Stat 2 \nFake Stat 3")
                    font.pixelSize: 22
                }
            }
        }
        Row {
            QGCButton{
                text: "Gear"
                background: Rectangle {
                    implicitWidth: workingWidth / 4
                    implicitHeight: 200
                    opacity: enabled ? 1.0 : 0.3
                    border.width: 1
                    border.color: control.down ? "#17a81a" : "#21be2b"
                }
            }
            QGCButton{
                text: "Power Output"
                background: Rectangle {
                    implicitWidth: workingWidth / 4
                    implicitHeight: 200
                    opacity: enabled ? 1.0 : 0.3
                    border.width: 1
                    border.color: control.down ? "#17a81a" : "#21be2b"
                }
            }
            QGCButton{
                text: "Efficiency"
                background: Rectangle {
                        implicitWidth: workingWidth / 4
                        implicitHeight: 200
                        opacity: enabled ? 1.0 : 0.3
                        border.width: 1
                        border.color: control.down ? "#17a81a" : "#21be2b"
                    }
            }
            Frame {
                ColumnLayout{
                    QGCLabel{
                         Layout.preferredWidth: workingWidth / 4
                        text: qsTr("NAV")
                    } 
                    FlyViewInstrumentPanel {
                    //id:                         instrumentPanel
                    //anchors.margins:            _toolsMargin
                    //anchors.bottom:             parent.bottom
                    //anchors.right:              parent.right
                    width:                      _rightPanelWidth
                    //spacing:                    _toolsMargin
                    visible:                    QGroundControl.corePlugin.options.flyView.showInstrumentPanel && multiVehiclePanelSelector.showSingleVehiclePanel
                    //availableHeight:            parent.height - y - _toolsMargin
                    //property real rightInset: visible ? parent.width - x : 0
                }
                }
            } 
        }
    }
    
    MultiVehicleList {
        anchors.margins:    _toolsMargin
        //anchors.top:        multiVehiclePanelSelector.bottom
        //anchors.right:      parent.right
        width:              _rightPanelWidth
        height:             parent.height - y - _toolsMargin
        visible:            !multiVehiclePanelSelector.showSingleVehiclePanel
    } 
    
    
    PhotoVideoControl {
        id:                     photoVideoControl
        anchors.margins:        _toolsMargin
        anchors.right:          parent.right
        width:                  _rightPanelWidth
        state:                  _verticalCenter ? "verticalCenter" : "topAnchor"
        states: [
            State {
                name: "verticalCenter"
                AnchorChanges {
                    target:                 photoVideoControl
                    anchors.top:            undefined
                    anchors.verticalCenter: _root.verticalCenter
                }
            },
            State {
                name: "topAnchor"
                AnchorChanges {
                    target:                 photoVideoControl
                    anchors.verticalCenter: undefined
                    anchors.top:            instrumentPanel.bottom
                }
            }
        ]
        property bool _verticalCenter: !QGroundControl.settingsManager.flyViewSettings.alternateInstrumentPanel.rawValue
    }
    /**/

    //-- Virtual Joystick
/*
    Loader {
        id:                         virtualJoystickMultiTouch
        z:                          QGroundControl.zOrderTopMost + 1
        width:                      parent.width  - (_pipOverlay.width / 2)
        height:                     Math.min(parent.height * 0.25, ScreenTools.defaultFontPixelWidth * 16)
        visible:                    _virtualJoystickEnabled && !QGroundControl.videoManager.fullScreen && !(_activeVehicle ? _activeVehicle.usingHighLatencyLink : false)
        anchors.bottom:             parent.bottom
        anchors.bottomMargin:       parentToolInsets.leftEdgeBottomInset + ScreenTools.defaultFontPixelHeight * 2
        anchors.horizontalCenter:   parent.horizontalCenter
        source:                     "qrc:/qml/VirtualJoystick.qml"
        active:                     _virtualJoystickEnabled && !(_activeVehicle ? _activeVehicle.usingHighLatencyLink : false)
        property bool autoCenterThrottle: QGroundControl.settingsManager.appSettings.virtualJoystickAutoCenterThrottle.rawValue
        property bool _virtualJoystickEnabled: QGroundControl.settingsManager.appSettings.virtualJoystick.rawValue
    }
    /*
    FlyViewToolStrip {
        id:                     toolStrip
        anchors.leftMargin:     _toolsMargin + parentToolInsets.leftEdgeCenterInset
        anchors.topMargin:      _toolsMargin + parentToolInsets.topEdgeLeftInset
        anchors.left:           parent.left
        anchors.top:            parent.top
        z:                      QGroundControl.zOrderWidgets
        maxHeight:              parent.height - y - parentToolInsets.bottomEdgeLeftInset - _toolsMargin
        visible:                !QGroundControl.videoManager.fullScreen
        onDisplayPreFlightChecklist: preFlightChecklistPopup.createObject(mainWindow).open()
        property real leftInset: x + width
    }
    */
/*
    FlyViewAirspaceIndicator {
        anchors.top:                parent.top
        anchors.topMargin:          ScreenTools.defaultFontPixelHeight * 0.25
        anchors.horizontalCenter:   parent.horizontalCenter
        z:                          QGroundControl.zOrderWidgets
        show:                       mapControl.pipState.state !== mapControl.pipState.pipState
    }
    VehicleWarnings {
        anchors.centerIn:   parent
        z:                  QGroundControl.zOrderTopMost
    }
    MapScale {
        id:                 mapScale
        anchors.margins:    _toolsMargin
        anchors.left:       toolStrip.right
        anchors.top:        parent.top
        mapControl:         _mapControl
        buttonsOnLeft:      false
        visible:            !ScreenTools.isTinyScreen && QGroundControl.corePlugin.options.flyView.showMapScale && mapControl.pipState.state === mapControl.pipState.fullState
        property real centerInset: visible ? parent.height - y : 0
    }
    Component {
        id: preFlightChecklistPopup
        FlyViewPreFlightChecklistPopup {
        }
    }
}
*/