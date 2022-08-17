import QtQuick 2.9
import QtQuick 2.15
import QtCharts 2.3
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    color:"black"
Rectangle{

    width:300
    height:300
    color:"black"
        ChartView {
            backgroundColor: "black"
            height: 30
            width:30
            title: "Spline"
            anchors.fill: parent
            antialiasing: true
            ValuesAxis {
                id: xAxis
                min: 0
                max: 10
            }
            ValuesAxis {
                id: yAxis
                min: 0
                max: 10
            }
            SplineSeries {
                name: "SplineSeries"
                axisX:xAxis
                axisY:yAxis

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
