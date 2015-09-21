import QtQuick 2.2
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

ApplicationWindow {
    id: window
    visible: true
    title: "Table View Example"

    TableView {
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

}
