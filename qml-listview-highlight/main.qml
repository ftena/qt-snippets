import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 400
    height: 400

    Rectangle {
        id: root
        width: 400
        height: 400

        ListView {
            id: listView
            width: parent.width / 2
            height: parent.height

            model: ListModel {
                Component.onCompleted: {
                    for (var i = 0; i < 7; ++i) {
                        append({value: i});
                    }
                }
            }

            delegate: Item {
                id: delegateItem
                width: listView.width
                height: 50

                Rectangle {
                    id: dragRect
                    width: listView.width
                    height: 50
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    color: 'transparent' // if not, the highlight is not displayed
                    border.color: Qt.darker(color)

                    Text {
                        anchors.centerIn: parent
                        text: modelData
                    }

                    MouseArea {
                         anchors.fill: parent
                         onClicked: listView.currentIndex = index
                    }

                }
            }

            highlight: Rectangle {
                        color: 'grey'
                        radius: 5
                        Text {
                            anchors { right: parent.right; verticalCenter: parent.verticalCenter; rightMargin: 15; }
                            text: '[X]'
                            color: 'white'
                        }
                    }

            onCurrentItemChanged: console.log(model.get(listView.currentIndex).value + ' selected')
        }
    }
}

