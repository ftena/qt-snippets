import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 500
    height: 500

    Rectangle {
        width: 300
        height: 400

        Component {
            id: listDelegate

            Item {
                width: 400;
                height: 50;

                Row {
                    Column {
                        width: 100
                        Text { text: codigo }
                    }
                    Column {
                        width: 100
                        Text { text: nombre }
                    }
                    Column {
                        width: 100
                        Text { text: fecha }
                    }
                }
            }
        }

        ListModel {
            id: listModel

            ListElement {
                codigo: "111"
                nombre: "AAA"
                fecha: "28/08/2001"
            }
            ListElement {
                codigo: "222"
                nombre: "BBB"
                fecha: "28/08/2002"
            }
            ListElement {
                codigo: "333"
                nombre: "CCC"
                fecha: "28/08/2003"
            }
        }

        ListView {
            id: listView
            anchors.fill: parent
            model: listModel
            delegate: listDelegate
            focus: true
            header: myheader
        }
    }

    Component {     //instantiated when header is processed
        id: myheader
        Rectangle {
            gradient: mygradient
            border {color: "#9EDDF2"; width: 2}
            width: parent.width; height: 50

            Row {
                Column {
                    width: 100
                    Text { text: "Codigo" }
                }

                Column {
                    width: 100
                    Text { text: "Nombre" }
                }

                Column {
                    width: 100
                    Text { text: "Fecha" }
                }
            }
        }
    }

    Gradient {
        id: mygradient
        GradientStop { position: 0.0; color: "#8EE2FE"}
        GradientStop { position: 0.66; color: "#7ED2EE"}
    }
}

