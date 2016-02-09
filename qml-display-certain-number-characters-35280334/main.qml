import QtQuick 2.5
import QtQuick.Window 2.2
import "myscript.js" as MyFunctions

Window {
    visible: true

    // It shows 2 chars.
    // We need to play with the width depending
    // on the text style, size, etc.
    Text {
        width: 13
        text: "FRENCH"
        clip: true
    }

    // Best option.
    // It shows 2 chars.
    Text {
        y: 30
        text: MyFunctions.substring("FRENCH")
    }

    // It shows 2 chars with '...'
    Text {
        y: 60
        width: 25
        text: "FRENCH"
        elide: Text.ElideRight
    }
}

