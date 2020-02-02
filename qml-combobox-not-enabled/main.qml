import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    visible: true
    width: 640
    height: 480

    Row {
        spacing: 2
        ComboBox {
            id: one
            width: 200
            model: [ "ON", "OFF" ]

            onCurrentIndexChanged: {
                if (currentIndex === find("ON")) {
                    two.enabled = false
                } else
                {
                    two.enabled = true
                }
            }
        }

        ComboBox {
            id: two
            width: 200
            model: [ "HELLO", "BYE" ]
        }
    }
}
