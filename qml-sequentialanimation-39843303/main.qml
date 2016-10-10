import QtQuick 2.3
import QtQuick.Controls 1.1

ApplicationWindow {
    visible: true
    width: 350
    height: 300

    Rectangle {
        id: window
        width: 350
        height: 300

        Canvas {
            id: canvas
            anchors.fill: parent
            antialiasing: true

            onPaint: {
                var context = canvas.getContext("2d")
                context.clearRect(0, 0, width, height)
                context.strokeStyle = "black"
                context.path = pathAnim.path
                context.stroke()
            }
        }

        SequentialAnimation {
            id: mySeqAnim
            running: true

            PauseAnimation { duration: 1000 }

            PathAnimation {
                id: pathAnim

                duration: 2000
                easing.type: Easing.InQuad

                target: box
                orientation: PathAnimation.RightFirst
                anchorPoint: Qt.point(box.width/2, box.height/2)
                path: myPath1
            }

            onStopped: {
                console.log("test")

                pathAnim.path = myPath2;

                mySeqAnim.start();
            }
        }

        Path {
            id: myPath1
            startX: 50; startY: 100

            PathLine { x: 300; y: 100 }

            onChanged: canvas.requestPaint()
        }

        Path {
            id: myPath2
            startX: 300; startY: 100

            PathLine { x: 50; y: 100 }

            onChanged: canvas.requestPaint()
        }

        Rectangle {
            id: box

            x: 25; y: 75
            width: 50; height: 50
            border.width: 1
            antialiasing: true

            Text {
                anchors.centerIn: parent
            }
        }
    }
}
