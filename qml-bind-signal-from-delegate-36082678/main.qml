import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: Screen.width/2
    height: Screen.height/2

    Item {
        id: root
        anchors.fill: parent

        signal componentTriggered(string name)

        onComponentTriggered: {
            console.log(name + ' component was triggered')
        }

        ListModel {
            id: myModel

            ListElement { name: "alpha" }
            ListElement { name: "beta" }
            ListElement { name: "gamma" }
            ListElement { name: "delta" }
        }

        ListView {
            id: myListView
            width: 100
            height: 600

            model: myModel
            delegate: MyDelegate {
                name: model.name
                Component.onCompleted: {
                    trigger.connect(root.componentTriggered)
                }
            }
        }
    }
}

