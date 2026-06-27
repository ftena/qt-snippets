import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ColumnLayout {
    spacing: 1

    Repeater {
        model: 7

        Rectangle {
            width: 100
            height: childrenRect.height
            border.width: 1
            color: "yellow"
            Layout.fillWidth: true

            Text {
                text: "index no. " +  index
                color: "black"
            }
        }
    }
}
