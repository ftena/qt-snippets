import QtQuick 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.0
import QtQuick.Window 2.1


Window {
    visible: true
    width: 538
    height: 360

    ListModel {
        id: mymodel

        ListElement {
            title: "VideoName"
            filesize: "1.5GB"
            length: "20:00"
        }

        ListElement {
            title: "VideoName"
            filesize: "1.5GB"
            length: "20:00"
        }

        ListElement {
            title: "VideoName"
            filesize: "1.5GB"
            length: "20:00"
        }
    }

    TableView {
        width: parent.width; height: parent.height
        anchors.centerIn: parent

        TableViewColumn {
            resizable: false
            role: "title"
            title: "Title"
            width: 250
        }

        TableViewColumn {
            role: "filesize"
            title: "Size"
            width: 100
            resizable: false
        }

        TableViewColumn {
            role: "length"
            title: "Length"
            width: 100
            resizable: false

        }

        model: mymodel

        rowDelegate: Rectangle {
            color: styleData.selected ? "#000" : "#fff"
            height: styleData.selected ? 54 : 20
        }

        itemDelegate: RowLayout {

            anchors.fill: parent

            Loader{
                id: loaderEditor
                sourceComponent: editor
                Connections {
                    target: loaderEditor.item
                }

                Component {
                    id: editor
                    TextInput {
                        id: textinput
                        color: styleData.textColor
                        text: styleData.value

                        onEditingFinished: {
                            mymodel.setProperty(styleData.row, styleData.role,
                                                loaderEditor.item.text)
                        }

                        MouseArea {
                            id: mouseArea
                            anchors.fill: parent
                            hoverEnabled: true
                            onClicked: {
                                textinput.forceActiveFocus()
                                textinput.selectAll()
                            }
                        }
                    }
                }
            }
        }
    }
}
