import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    visible: true
    width: 300
    height: 300

    Timer {
        id: myTimer
            interval: 5000; repeat: false
            onTriggered: myButton.background.color = "blue"
        }

    Button {
        id: myButton
        x: 100
        y: 100
        text: "my button"
        background: Rectangle {
            color: "blue"
        }

        onClicked: {
            myButton.background.color = "green"
            myTimer.start();
            console.log("clicked");
        }
    }
}

