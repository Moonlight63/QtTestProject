import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Dialogs.qml 1.0
import QtQuick.Extras 1.4

Item {
    id: item1
    width: 400
    height: 400

    SwipeView {
        id: swipeView
        currentIndex: 1
        anchors.top: tabBar.bottom
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.topMargin: 0

        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Label {
                id: label
                x: 184
                y: 70
                text: qsTr("Label")
            }

            DelayButton {
                id: delayButton
                x: 148
                y: 203
                text: qsTr("Button")
            }

            Gauge {
                id: gauge
                x: 270
                y: 146
                value: 10
            }

            PieMenu {
                id: pieMenu
                x: 15
                y: 70
            }

            ToggleButton {
                id: toggleButton
                x: 292
                y: 19
                width: 108
                height: 87
                text: qsTr("Button")
                checked: false
            }
        }

        Item {
            Layout.fillHeight: true
            Layout.fillWidth: true

            Button {
                id: button
                x: 166
                y: 79
                text: qsTr("Button")
            }
        }
    }

    TabBar {
        id: tabBar
        y: 0
        currentIndex: swipeView.currentIndex
        anchors.rightMargin: 0
        anchors.leftMargin: 0
        TabButton {
            text: qsTr("Tab 0")
        }

        TabButton {
            text: "Tab 1"
        }
        anchors.right: swipeView.right
        anchors.left: swipeView.left
    }
}
