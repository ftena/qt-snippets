import QtQuick 2.5

Rectangle {
    id: root
    width: 100
    height: 50
    color: "steelblue"
    border.color: "white"
    border.width: 2

    property string name

    signal trigger(string name)

    Text {
        anchors.centerIn: parent
        text: model.name
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.log(root.name + ' clicked')
            root.trigger(root.name)
        }
    }
}
