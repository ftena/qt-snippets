import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 600
    height: 600

    Rectangle {
        id: root
        width: 400
        height: 400

        ListView {
            id: control
            width: parent.width / 2
            height: parent.height
            anchors.right: parent.right

            property int multipleBegin: 0 // to control shift key and multiple selection
            signal checkOne(int idx) // to emit single selection
            signal checkMultiple(int idx) // to emit multiple selection

            Connections{
                target: control

                // Update the start index for multiple selection when
                // it is performed a single selection
                function onCheckOne (idx)
                {
                    control.multipleBegin=idx;
                }
            }

            clip: true
            boundsBehavior: Flickable.StopAtBounds // the contents cannot been dragged beyond the boundary of the flickable

            ListModel {
                id: myModel
                ListElement { number: "1"; extraData: "extra-1-" }
                ListElement { number: "2"; extraData: "extra{2}" }
                ListElement { number: "3"; extraData: "extra_3_" }
                ListElement { number: "4"; extraData: "extra*4*" }
                ListElement { number: "5"; extraData: "extra$5$" }
            }

            model: myModel

            delegate: Item {
                id: item_delegate
                width: control.width
                height: 50

                // Remember: the delegate is a component so we don't have
                // one delegate per view but rather one delegate per visible item
                property bool checked: false

                Rectangle {
                    id: rect
                    width: control.width
                    height: 50
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter

                    border.color: "gray"
                    color: item_delegate.checked? "green" : "red"
                    Connections {
                        target: control
                        function onCheckOne (idx) { item_delegate.checked=(idx===index); }
                        function onCheckMultiple (idx) {

                            if (idx > control.multipleBegin) {
                                item_delegate.checked = (index >= control.multipleBegin && index <= idx);
                            } else {
                                item_delegate.checked = (index <= control.multipleBegin && index >= idx);
                            }
                        }
                    }

                    Text {
                        anchors.centerIn: parent
                        text: number + " / " + extraData
                    }
                }

                MouseArea {
                    id: item_mousearea
                    anchors.fill: parent

                    onClicked: {

                        switch (mouse.modifiers) {
                        case Qt.ControlModifier:
                            item_delegate.checked =! item_delegate.checked;
                            break;
                        case Qt.ShiftModifier:
                            control.checkMultiple(index);
                            break;
                        default:
                            control.checkOne(index);
                            control.multipleBegin = index;
                            break;
                        }
                    }

                    onPressAndHold: {
                        // It is possible to do the same using the onPress handler
                        // but then it collides with the current ControlModifier functionality.
                        // In fact, due to the default case in the onClicked handler, it is not
                        // strictly necessary to implement this slot.
                        console.log("onPressAndHold: " + index)
                        control.checkMultiple(index)
                    }

                    onPositionChanged: {
                        console.log("onPositionChanged: " + index)

                        // map the coordinate
                        var point = mapToItem (control, mouse.x, mouse.y)

                        console.log("mouse position (x, y): " + mouse.x, mouse.y
                                    + " mapToItem (x, y): "
                                    + point.x,
                                    + point.y)

                        var item = control.childAt(point.x, point.y)

                        if(item)
                        {
                            var indexAtPoint = control.indexAt(point.x, point.y)
                            var itemAtIndex = control.itemAtIndex(indexAtPoint)

                            console.log("item found at index: " + indexAtPoint
                                        + " data from item model: " + itemAtIndex.ListView.view.model.get(indexAtPoint).extraData)

                            control.checkMultiple(indexAtPoint)
                        }
                    }

                    onReleased: {
                        // another option is to put here the code from onPositionChanged
                        // but it is actually a different approach with a different behaviour
                    }
                }
            }
        }
    }
}

