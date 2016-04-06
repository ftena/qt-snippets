import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 600
    height: 600

    Rectangle {
        id: root
        width: 400
        height: 400

        ListView {
            id: listView
            width: parent.width / 2
            height: parent.height

            property int dragItemIndex: -1

            model: ListModel {
                Component.onCompleted: {
                    for (var i = 0; i < 10; ++i) {
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
                    color: "salmon"
                    border.color: Qt.darker(color)

                    Text {
                        anchors.centerIn: parent
                        text: modelData
                    }

                    MouseArea {
                        id: mouseArea
                        anchors.fill: parent
                        drag.target: dragRect

                        drag.onActiveChanged: {
                            if (mouseArea.drag.active) {
                                listView.dragItemIndex = index;
                            }
                            dragRect.Drag.drop();
                        }
                    }

                    states: [
                        State {
                            when: dragRect.Drag.active
                            ParentChange {
                                target: dragRect
                                parent: root
                            }

                            AnchorChanges {
                                target: dragRect
                                anchors.horizontalCenter: undefined
                                anchors.verticalCenter: undefined
                            }
                        }
                    ]

                    Drag.active: mouseArea.drag.active
                    Drag.hotSpot.x: dragRect.width / 2
                    Drag.hotSpot.y: dragRect.height / 2
                }
            }
        }

        ListView {
            id: listView2
            width: parent.width / 2
            height: parent.height
            anchors.right: parent.right

            property int dragItemIndex: -1

            DropArea {
                id: dropArea
                anchors.fill: parent
                onDropped: {
                    listView2.model.append(listView.model.get(listView.dragItemIndex))
                    listView.model.remove(listView.dragItemIndex)
                    listView.dragItemIndex = -1;
                }
            }

            model: ListModel {
                Component.onCompleted: {
                    for (var i = 0; i < 1; ++i) {
                        append({value: i});
                    }
                }
            }

            delegate: Item {
                id: delegateItem2
                width: listView2.width
                height: 50

                Rectangle {
                    id: dragRect2
                    width: listView2.width
                    height: 50
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    color: "salmon"
                    border.color: Qt.darker(color)

                    Text {
                        anchors.centerIn: parent
                        text: modelData
                    }
                }
            }
        }
    }
}

