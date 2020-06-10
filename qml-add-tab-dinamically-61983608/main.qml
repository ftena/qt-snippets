import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3

ApplicationWindow{
    id: win
    visible: true
    width: 800
    height: 600

    Component{
        id: myComponent
        MyTab{
            id: myTabId
        }
    }

    Button{
        id: myButton
        text: "click me";
        anchors.top: parent.top
        anchors.topMargin: 5
        onClicked: {
            var title = "hey!"
            tb.myAddTab(title, myComponent)
        }
    }

    TabView{
        id: tb
        anchors.top: myButton.bottom
        anchors.topMargin: 5
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.left: parent.left

        Tab{
            id: myTab1
            title: "First Tab"
            MyTab{
                id: myTabId
            }
        }

        function myAddTab(title, componentID){
            var t = tb.addTab(title, componentID)
        }
    }
}
