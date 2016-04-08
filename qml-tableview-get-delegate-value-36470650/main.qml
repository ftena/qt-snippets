import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    visible: true
    width: 300

    Button {
        text: "click me"

        function getValues(lw_order, orderModelId) {
            for (var index = 0 ; index < lw_order.rowCount; index++)
            {
                print("row: " + index)
                print(" OrderedID: " + orderModelId.get(index).OrderedID + "; " +
                      " OrderedItems: " + orderModelId.get(index).OrderedItems + "; " +
                      " OrderedAmount: " + orderModelId.get(index).OrderedAmount)
            }
        }

        onClicked: {
            getValues(lw_order, orderModelId)
        }
    }

    ListModel {
        id: orderModelId
        ListElement {
            OrderedID: "1"
            OrderedItems: "10"
            OrderedAmount: "15"
        }

        ListElement {
            OrderedID: "2"
            OrderedItems: "20"
            OrderedAmount: "25"
        }

        ListElement {
            OrderedID: "3"
            OrderedItems: "30"
            OrderedAmount: "35"
        }
    }

    TableView {
        id: lw_order
        x: 0
        y: 50
        width: 300
        height: 300
        model: orderModelId

        TableViewColumn
        {
            id: tableorderid
            role: "OrderedID"
            title: "ID"
            width: 50
        }
        TableViewColumn
        {
            role: "OrderedItems"
            title: "Items"
            width: 100
        }
        TableViewColumn
        {
            id: tableamountid
            role: "OrderedAmount"
            title: "Amount"
            width: 70
            delegate: Item {
                SpinBox {
                    id: tableamountspin
                    anchors.verticalCenter: parent.verticalCenter
                    minimumValue: 1
                    width: 70
                    value: styleData.value

                    onValueChanged: {
                        if (focus == true) {
                            console.log("onValueChanged - row: "  + styleData.row + " column: " + styleData.column + " value: " + value)
                            orderModelId.setProperty(styleData.row, "OrderedAmount", value.toString())
                        }
                    }
                }
            }
        }
    }
}

