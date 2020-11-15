import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.11
import QtQuick.Layouts 1.11

Window {
    visible: true
    width: 640
    height: 480

    RowLayout {
        Button {
            text: "Set Shortcut"
            onClicked: myItem.focus = true;
        }
        TextEdit {
            id: myTextEdit
        }
    }

    Item {
        id: myItem
        focus: false
        Keys.onPressed: {
            console.log("recording shortcut")
            if ((event.key === Qt.Key_A) && (event.modifiers & Qt.ShiftModifier))
            {
                myShortCut.sequence = "Shift+A";
                focus = false;
            }
            if ((event.key === Qt.Key_X) && (event.modifiers & Qt.ControlModifier))
            {
                myShortCut.sequence = "Ctrl+X";
                focus = false;
            }
        }
    }

    Shortcut {
        id: myShortCut
        onActivated: myTextEdit.text = "shortcut " + sequence + " pressed!"
    }
}
