import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.2

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
