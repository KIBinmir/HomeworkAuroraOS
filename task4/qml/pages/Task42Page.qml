import QtQuick 2.0
import Sailfish.Silica 1.0
import module.name 1.0

Page {
    objectName: "mainPage"
    allowedOrientations: Orientation.All
    MyList {
        id: lst
    }
//
    Column {
        anchors.fill: parent
        property alias source: addItemBut
        property alias source2: delItemBut
        TextField {
            id: fld1
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: Theme.paddingMedium
            width: Theme.buttonWidthLarge
            height: 100
            color: "black"
            placeholderText: qsTr("Введите слово")
            label: qsTr("Enter number №1")
        }
        Button {
            id: addItemBut
            width: parent.width
            anchors.top: fld1.bottom
            height: 100
            color: "white"
            text: "Add item"
            onClicked: {
                lst.addItem(fld1.text.toString())
                fld1.text = ""
            }
        }
        Button {
            id: delItemBut
            width: parent.width
            height: 100
            anchors.top: addItemBut.bottom
            color: "white"
            text: "Remove item"
            onClicked: {
                console.log("removed item: " + lst.popItem())
            }
        }
        Text {
            id: txt
            width: parent.width
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: delItemBut.bottom
            text: lst.listToString
        }
        Component.onCompleted: {
            source.clicked(lst.listToStringChanged())
            source2.clicked(lst.listToStringChanged())
        }

        /*Repeater {
            id: mylst
            width: parent.width
            //height: parent.height - addItemBut.height - delItemBut.height
            anchors.top: txt.bottom
            model: lst
            Rectangle {
                width: parent.width
                height: 100
                anchors.horizontalCenter: parent.horizontalCenter
                border.color: "white"
                color: "blue"
                border.width: 1
                Text {
                    text: txt + ind
                    color: "white"
                    anchors.centerIn: parent
                }
            }
        }*/
    }
}
