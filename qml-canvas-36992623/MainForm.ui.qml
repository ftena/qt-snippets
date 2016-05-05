import QtQuick 2.5

Rectangle {
    property alias mouseArea1: mouseArea1
    property alias mouseArea2: mouseArea2

    width: 360
    height: 360
    color: "cyan"

    Rectangle {
        width: 100;
        height: 100;
        color: "white"

        MouseArea {
            id: mouseArea1
            anchors.fill: parent
        }

        Text {
            anchors.centerIn: parent
            text: "repaint"
        }
    }

    Rectangle {
        width: 100;
        height: 100;
        x: 150
        color: "white"

        MouseArea {
            id: mouseArea2
            anchors.fill: parent
        }

        Text {
            anchors.centerIn: parent
            text: "visible = false"
        }
    }
}
