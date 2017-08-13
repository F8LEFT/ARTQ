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

    FileBrowserDock {
        id: fileBrowser
        objectName: "fileBrowser"
    }

    PanelContainer {
        objectName: "dockContainer"
        id: dockContainer
        anchors.fill: parent
        movable: true


        panelsMetaData: [
            { container: dockContainer, innerObject: fileBrowser, name: "fileBrowser", percentWidth: 70, percentHeight: 50}
//                    { id: "panel1", container: mainContainer, qml: "qrc:/MyPanel1.qml", name: "Panel 1", percentWidth: 70, percentHeight: 50 },
        ]
    }



    // Side bar
    // Button bar
    // MainProcess Window


}
