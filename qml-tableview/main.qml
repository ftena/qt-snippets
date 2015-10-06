import QtQuick 2.2
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

ApplicationWindow {
    id: window
    visible: true
    title: "Table View Example"

    TableView {
        y: 70
        width: 500

        TableViewColumn {
            role: "title"
            title: "Title"
            width: 100
        }
        TableViewColumn {
            role: "author"
            title: "Author"
            width: 100
        }

        TableViewColumn{
            width: 300
            delegate: Text {
                text: model.title + " "  + model.author
                font.family: "Courier New"
                font.pixelSize: 18
                color: "red"
            }
        }

        onClicked: {
            leftText.text = libraryModel.get(row).title + " " + libraryModel.get(row).author;
            centerText.text = libraryModel.get(row).title;
            rightText.text = libraryModel.get(row).author;
        }

        model: libraryModel

        ListModel {
            id: libraryModel
            ListElement {
                title: "A Masterpiece"
                author: "Gabriel"
            }
            ListElement {
                title: "Brilliance"
                author: "Jens"
            }
            ListElement {
                title: "Outstanding"
                author: "Frederik"
            }
        }
    }

    TextField {
        id:  leftText
    }

    TextField {
        id:  centerText
        anchors.left: leftText.right
    }

    TextField {
        id:  rightText
        anchors.left: centerText.right
    }
}
