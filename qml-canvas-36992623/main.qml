import QtQuick 2.5
import QtQuick.Controls 1.4

ApplicationWindow {
    visible: true
    width: 1050
    height: 700
    color: "#b09273"
    title: qsTr("Hello World")

    MainForm {
        anchors.fill: parent
        id: mainform

        mouseArea1.onClicked: {
            mojCanvas.visible = true;

            var context = mojCanvas.getContext("2d");

            // Make canvas all white
            context.beginPath();
            context.clearRect(0, 0, mojCanvas.width, mojCanvas.height);
            context.fill();

            // Draw a line
            context.beginPath();
            context.lineWidth = 2;
            context.moveTo(30, 30);
            context.strokeStyle = "red"
            context.lineTo(width-30, height-30);
            context.stroke();

            // New arc color
            mojCanvas.myColor = "cyan";

            mojCanvas.requestPaint();
        }

        mouseArea2.onClicked: {
            mojCanvas.visible = false
        }
    }

    Canvas {
        id: mojCanvas
        width: 1050
        height: 590
        anchors.top: parent.top
        anchors.topMargin: 55
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 55
        anchors.left: parent.left
        anchors.right: parent.right
        contextType: "2d"

        property color myColor: "indigo"

        Path {
            id: myPath
            startX: 450; startY: 590

            PathArc {
                x: 0; y: 269.30848034096934944;
                radiusX:625; radiusY: 625;
                useLargeArc: false
                direction: PathArc.Counterclockwise
            }
        }

        onPaint: {
            context.strokeStyle = myColor;
            context.lineWidth = 3;
            context.path = myPath;
            context.stroke();
        }
    }
}
