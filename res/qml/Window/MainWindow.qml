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

    // Side bar
    // Button bar
    // MainProcess Window


}
