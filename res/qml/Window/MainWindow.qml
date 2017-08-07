import QtQuick 2.8

import SharedComponents 1.0

Rectangle {
    property alias mouseArea: mouseArea

    width: 360
    height: 360

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }

    PanelContainer {
        id: mainContainer
        anchors.fill: parent
        movable: true

//        panelsMetaData: [
//            { id: "", container: mainContainer, }
//        ]
    }



    // Side bar
    // Button bar
    // MainProcess Window


}
