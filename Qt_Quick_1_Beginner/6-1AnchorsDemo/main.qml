import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Anchors Demo")

    Rectangle {
        id : containerRectId
        width: 300
        height: width
        border.color: "black"
        anchors.centerIn: parent

        Rectangle {
            id : topLeftRectId
            width: 100
            height: width
            color: "magenta"
            anchors.top: siblingRect.bottom
        }

        Rectangle {
            id : topCenterRectId
            width: 100
            height: width
            color: "yellowgreen"
            anchors.left: topLeftRectId.right
        }

        Rectangle {
            id : topRightRectId
            width: 100
            height: width
            color: "dodgerblue"
            anchors.left: topCenterRectId.right
        }

        Rectangle {
            id : centerLeftRectId
            width: 100
            height: width
            color: "red"
            anchors.top: topLeftRectId.bottom
        }

        Rectangle {
            id : centerCenterRectId
            width: 100
            height: width
            color: "green"
//            anchors.left: centerLeftRectId.right
//            anchors.top: topRightRectId.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            //To have margins working, you have to set the anchor property on that anchor line
            //anchors.rightMargin: 10

            //This margin works because we have top margin set
            //anchors.topMargin: 10

//            anchors.horizontalCenterOffset: 10
//            anchors.verticalCenterOffset: 10
        }
        Rectangle {
            id : centerRightRectId
            width: 100
            height: width
            color: "blue"
            anchors.left: centerCenterRectId.right
            anchors.top: topRightRectId.bottom
        }
        Rectangle {
            id : bottomLeftRectId
            width: 100
            height: width
            color: "royalblue"
            anchors.right: centerCenterRectId.left
            anchors.top: centerCenterRectId.bottom
        }
        Rectangle {
            id : bottomCenterRectId
            width: 100
            height: width
            color: "yellow"
            anchors.left: centerCenterRectId.left
            anchors.top: centerCenterRectId.bottom
        }

        Rectangle {
            id : bottomRightRectId
            width: 100
            height: width
            color: "pink"
            anchors.left: centerCenterRectId.right
            anchors.top: centerCenterRectId.bottom
        }
    }

    Rectangle {
        id : siblingRect
        width: 200
        height: 200
        color : "black"
        anchors.right: containerRectId.left
    }
}
