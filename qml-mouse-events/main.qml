import QtQuick
import QtQuick.Controls
import QtQuick.Window

ApplicationWindow {
    id: mainwindow
    width: 640
    height: 480
    visible: true

    Flickable {        
        width: 300; height: 300
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
                    console.log("closed hand cursor")
                }

                onReleased: {
                    cursorShape = Qt.OpenHandCursor
                    console.log("open hand cursor")
                }

                cursorShape: Qt.OpenHandCursor
            }
        }
    }
}
