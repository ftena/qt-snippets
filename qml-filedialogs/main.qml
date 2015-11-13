import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.1

Window {
    FileDialog {
        id: fileDialog        
        modality: Qt.WindowModal
        title: "Choose the files"
        /* By default, selectExisting is true. */
        // selectExisting: true
        /*
          Setting selectMultiple to true implies that selectExisting must be true.
        */
        selectMultiple: true
        /*
          By default, selectFolder is false
        */
        // selectFolder: false
        sidebarVisible: true
        onAccepted: {
            console.log("onAccepted: " + fileUrls)
        }
        onRejected: { console.log("onRejected") }

        MouseArea {
            anchors.fill:parent

            onClicked: {
                console.log("here")
            }
        }

        Component.onCompleted: visible = true
    }

}
