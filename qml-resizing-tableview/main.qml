import QtQuick 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2

ApplicationWindow {
    id: window
    width: 800
    visible: true
    title: "Table View Example"

    TableView {
        id: tableView

        frameVisible: false
        sortIndicatorVisible: true

        anchors.fill: parent

        Layout.minimumWidth: 400
        Layout.minimumHeight: 240
        Layout.preferredWidth: 600
        Layout.preferredHeight: 400

        TableViewColumn {
            id: titleColumn
            title: "Title"
            role: "title"
            movable: false
            resizable: false
            width: window.width / 4

        }

        TableViewColumn {
            id: authorColumn
            title: "Author"
            role: "author"
            movable: false
            width: 100
        }

        TableViewColumn {
            id: pages
            title: "Num. pages"
            role: "pages"
            movable: false
            width: 75
        }

        model: sourceModel

        onClicked: {

        }

        ListModel {
            id: sourceModel
            ListElement {
                title: "Moby-Dick"
                author: "Herman Melville"
                pages: "100"
            }
            ListElement {
                title: "The Adventures of Tom Sawyer"
                author: "Mark Twain"
                pages: "200"
            }
            ListElement {
                title: "Cat’s Cradle"
                author: "Kurt Vonnegut"
                pages: "300"
            }
        }
    }
}
