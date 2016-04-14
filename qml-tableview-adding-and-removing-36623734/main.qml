import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    visible: true
    width: 500
    height: 500

    Rectangle {
        width: 250
        height: 400


        Component {
            id: listDelegate

            Item {
                width: 250; height: 50

                Row {
                    Column {
                        width: 200
                        Text { text: 'mytext: ' + mytext }
                    }
                    Column {
                        width: 50
                        Image {
                            id: deleteButton
                            source: "delete.jpg"
                            MouseArea {
                                anchors.fill: parent;

                                onClicked:{
                                    console.debug("clicked:"+ index);
                                    listModel.remove(index);
                                }
                            }
                        }
                    }
                }
            }
        }

        ListModel {
            id: listModel

            ListElement {
                mytext: "AAA"
            }
            ListElement {
                mytext: "BBB"
            }
        }

        ListView {
            id: listView
            anchors.fill: parent
            model: listModel
            delegate: listDelegate
            focus: true
        }
    }

    Button {
        y: 450
        text: "add"

        onClicked: {
            listModel.append({"mytext": "XXX"})
        }
    }
}

