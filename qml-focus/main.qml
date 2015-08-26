import QtQuick 2.5
import QtQuick.Controls 1.3

ApplicationWindow {
    id: mainwindow
    title: qsTr("Hello")
    width: 640
    height: 480
    visible: true

    Shortcut {
            sequence: "Shift+A"
            onActivated: rect.blue()
            context: Qt.ApplicationShortcut
    }

    Shortcut {
            sequence: "Shift+Ctrl+S"
            onActivated: rect.red()
            context: Qt.ApplicationShortcut
    }

    Shortcut {
            sequence: "Shift+D"
            onActivated: text.text = 'Key Shift + D was pressed'
            context: Qt.ApplicationShortcut
    }

    Item {
        anchors.fill: parent

        Keys.onPressed: {
            if ( (event.key === Qt.Key_Q) && (event.modifiers & Qt.ShiftModifier) ) {
                rect.blue()
            } else if ( (event.key === Qt.Key_W) && (event.modifiers & Qt.AltModifier) ) {
                rect.red()
            } else if ( (event.key === Qt.Key_E) && (event.modifiers & Qt.AltModifier) ) {
                text.text = 'Key E was pressed'
            }
        }

        Rectangle{
            id: rect
            width: 100
            height: 100
            color: "black"

            function blue() {color = "blue"}
            function red() {color = "red"}
        }

        Text {
            id: text
            anchors.centerIn: parent
            font.pointSize: 20
        }

        TextInput {
            id: textinput
            anchors.top: text.bottom
            text: "sample text"

            Keys.onPressed: {
                if (event.key === Qt.Key_Escape) {
                    console.log('Key Escape was pressed');
                    parent.focus = true;
                }
            }
        }
    }
}
