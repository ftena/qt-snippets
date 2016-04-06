import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.XmlListModel 2.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480    

    XmlListModel {
        id: xmlModel
        source: "/res/myxml.xml"
        query: "/gallery/album"

        XmlRole { name: "title"; query: "title/string()" }
        // query the img's src (the '@' indicates 'src' is an attribute, not an element)
        XmlRole { name: "img"; query: "img/@src/string()" }
    }

    ListView {
        width: 180; height: 300
        model: xmlModel
        delegate: Text { text: title + ": " + img }
    }
}
