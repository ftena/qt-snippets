import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2

ApplicationWindow {
    id: mainwindow
    width: 640
    height: 480
    visible: true

    Flickable {
        width: 200; height: 200
        contentWidth: image.width
        contentHeight: image.height
        clip: true

        onMovementEnded: {
            mousearea.cursorShape = Qt.OpenHandCursor
            console.log("onMovementEnded")
        }

        Image {
            id: image;
            source: "images/icon.png"

            MouseArea {
                id: mousearea
                anchors.fill: parent

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
}
