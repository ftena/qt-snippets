import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    id: messageBox

    property string message

    signal showText (string mytext)

    function buttonClicked(mytext) {
        console.log("buttonClicked in MessageBox.qml: " + mytext)
    }

    visible: true
    flags: Qt.Dialog
    modality: Qt.WindowModal

    Component.onCompleted: {
        messageBox.showText.connect(buttonClicked)
    }

    onShowText: console.log("Slot 'onShowText' in MessageBox.qml: "  + mytext)

    Button {
        text: message

        onClicked:
        {
            messageBox.showText ("I'm a button in MessageBox.qml")
        }
    }
}
