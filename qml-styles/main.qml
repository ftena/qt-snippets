import QtQuick 2.2
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Example")


    TabView {
        anchors.fill: parent

        Tab { title: "One" ; Item {}}
        Tab { title: "Two" ; Item {}}
        Tab { title: "Three" ; Item {}}
        Tab { title: "Four" ; Item {}}
        style: tabViewStyle
    }

    Component {
        id: tabViewStyle
        TabViewStyle {
            tabsMovable: true

            tab: Item {
                implicitWidth: 97
                implicitHeight: 28

                Image {
                    id: image
                    anchors.centerIn: parent
                    source: styleData.selected ? "images/tab_selected.png" : "images/tab.png"
                }
                Text {
                    id: text
                    text: styleData.selected ? "" : styleData.title
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }

            frame: Rectangle { color: "steelblue" }
        }
    }
}
