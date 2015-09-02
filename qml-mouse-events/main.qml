import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2

ApplicationWindow {
    id: mainwindow
    width: 640
    height: 480
    visible: true

    Rectangle {
        width: 320
        height: 240
        color: "green"

        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton

            onPressed: {
              cursorShape = Qt.ClosedHandCursor
              console.log("closed")
            }

            onReleased: {
              cursorShape = Qt.OpenHandCursor
              console.log("open")
            }

            cursorShape: Qt.OpenHandCursor
        }
    }
}
