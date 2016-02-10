import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    id: mainWindow
    visible: true        

    Button {
        text: "Main Button"
        onClicked:
        {
            var component = Qt.createComponent("MessageBox.qml");
            if (component.status === Component.Ready) {
                var dialog = component.createObject(parent);
                dialog.title = "Message Box";
                dialog.message = "Click me!";
                dialog.show();
                dialog.showText.connect(myButtonClicked)
            }
        }
    }

    function myButtonClicked(mytext) {
        console.log("buttonClicked in mainWindow: " + mytext)
    }
}

