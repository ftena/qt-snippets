import QtQuick 2.15
import QtCharts 2.15
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Rectangle {
        width: 300
        height: 300
        ChartView {
            title: "Spline"
            anchors.fill: parent
            antialiasing: true

            SplineSeries {
                name: "SplineSeries"

                XYPoint { x: 0; y: 0.0 }
                XYPoint { x: 1.1; y: 3.2 }
                XYPoint { x: 1.9; y: 2.4 }
                XYPoint { x: 2.1; y: 2.1 }
                XYPoint { x: 2.9; y: 2.6 }
                XYPoint { x: 3.4; y: 2.3 }
                XYPoint { x: 4.1; y: 3.1 }
            }
        }
    }
}

