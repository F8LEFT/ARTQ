import QtQuick 2.8

import QtQuick.Controls 1.4
import QtQml.Models 2.3

TreeView {
    id: fileTree
    anchors.fill: parent
    model:projectFileSystemModel
    rootIndex: rootPathIndex
    selection: sel

    TableViewColumn {
        title: "Name"
        role: "fileName"
        resizable: true
    }

    TableViewColumn {
        title: "Size"
        role: "size"
        resizable: true
        horizontalAlignment: Text.AlignRight
        width: 70
    }

}
