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

            property int mulBegin: 0

            signal checkOne(int idx)
            signal checkMul(int idx)

            Connections{
                target: control

                function onCheckOne(idx)
                {
                    control.mulBegin=idx;
                }
            }

            clip: true
            boundsBehavior: Flickable.StopAtBounds

            model: ListModel {
                Component.onCompleted: {
                    for (var i = 0; i < 7; ++i) {
                        append({value: i});
                    }
                }
            }

            delegate: Item {
                id: item_delegate
                width: control.width
                height: 50

                property bool checked: false

                Rectangle {
                    id: dragRect2
                    width: control.width
                    height: 50
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter

                    border.color: "gray"
                    color: item_delegate.checked? "green" : "red"
                    Connections{
                        target: control
                        function onCheckOne(idx) { item_delegate.checked=(idx===index); }
                        function onCheckMul(idx) {

                            if(idx>control.mulBegin){
                                item_delegate.checked=(index>=control.mulBegin&&index<=idx);
                            }else{
                                item_delegate.checked=(index<=control.mulBegin&&index>=idx);
                            }
                        }
                    }

                    Text {
                        anchors.centerIn: parent
                        text: modelData
                    }
                }

                MouseArea {
                    id: item_mousearea
                    anchors.fill: parent

                    onClicked: {

                        switch(mouse.modifiers){
                        case Qt.ControlModifier:
                            item_delegate.checked=!item_delegate.checked;
                            break;
                        case Qt.ShiftModifier:
                            control.checkMul(index);
                            break;
                        default:
                            control.checkOne(index);
                            control.mulBegin=index;
                            break;
                        }
                    }

                    onPressAndHold: {
                        // It is possible to do the same using the onPress handler
                        // but then it collides with the current ControlModifier functionality.
                        // In fact, due to the default case in the onClicked handler, it is not
                        // strictly necessary to implement this slot.
                        console.log("onPressAndHold: " + index)
                        control.checkMul(index)
                    }

                    onPositionChanged: {
                        console.log("onPositionChanged: " + index)

                        // map the coordinate
                        var point = mapToItem(control, mouse.x, mouse.y)

                        console.log("mouse position (x, y): " + mouse.x, mouse.y
                                    + " mapToItem (x, y): "
                                    + point.x,
                                    + point.y)

                        var item = control.childAt(point.x, point.y)

                        if(item)
                        {
                            var indexEnd = control.indexAt(point.x, point.y)

                            console.log("item found: " + indexEnd)

                            control.checkMul(indexEnd)
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

