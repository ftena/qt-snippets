import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

ApplicationWindow {
    visible: true
    width: Screen.width /2
    height: Screen.height/2

    Rectangle {
        x: parent.width/4
        y: parent.height/4
        width: parent.width/2
        height: parent.width/2

        color: "steelblue"

        Text {
            text: "main.qml"
            y: 30
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: 24; font.bold: true
        }
    }
}
