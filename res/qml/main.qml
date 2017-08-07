import QtQuick 2.8
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.3

import "./Window" as AWindow

ApplicationWindow {
    objectName: "RootWindow"
    visible: true
    title: qsTr("Android Reverse Toolkit Q v") + version
    property string version
    property string compileTime

    width: 640
    height: 480

    MessageDialog {			// show about message
        id: aboutDialog
        title: "About Android Reverse Toolkit Q " + version
        text: "Author: F8LEFT - CURRWIN"
        informativeText: "Compiled on:<br>" + compileTime + "<br>" +
                         "<br>This program is free and opensource software. Source code can " +
                         "be found in <a href=\"https://github.com/F8LEFT/ART\">" +
                         "https://github.com/F8LEFT/ART</a>. You can redistribute " +
                         "it and/or modify it under the terms of the GNU General Public " +
                         "License as published by the Free Software Foundation, either " +
                         "version 3 of the License, of (at your option) any later version." +
                         "<br>"
    }

    FileDialog {			// show a dialog to open dex/apk file to decompile
        id: fileOpenDialog
        title: "Please choose a file to open"
        folder: shortcuts.home
        nameFilters: ["Apk file(*.apk)", "Dex file (*.dex)", "Any file (*)"]

        onAccepted: {
            // TODO Send a signal to start decompile process
        }
        onRejected: {
            // TODO Do nothing
        }
    }

    menuBar: MenuBar {
        Menu {
            title: "&File"
            MenuItem {
                text: "&Open"
                shortcut: StandardKey.Open
                onTriggered: {
                    // TODO acuired to close current project
                    fileOpenDialog.open()
                }
            }

            MenuItem {
                text: "E&xit"
                shortcut: StandardKey.Quit
                onTriggered: Qt.quit()
            }
        }

        Menu {
            title: "&Help"
            MenuItem {
                text: "About..."
                onTriggered: aboutDialog.open()
            }
        }
    }


    toolBar: ToolBar {
        RowLayout {
            anchors.fill: parent
            anchors.margins: spacing
        }
    }

    AWindow.MainWindow {
        id: mainWindow

    }


    // Content View is MainForm

    statusBar: StatusBar {
        // just use status bar to show debug line status
    }
}
