import QtQuick 2.7

Page1Form {


    yDown.onClicked: {
        adapterMaster.yDown();
    }
    xDown.onClicked: {
        adapterMaster.xDown();
    }
    yUp.onClicked: {
        adapterMaster.yUp();
    }
    xUp.onClicked: {
        adapterMaster.xUp();
    }

    yDown.onPressAndHold: {
        adapterMaster.yDownHold();
    }
    xDown.onPressAndHold: {
        adapterMaster.xDownHold();
    }
    yUp.onPressAndHold: {
        adapterMaster.yUpHold();
    }
    xUp.onPressAndHold: {
        adapterMaster.xUpHold();
    }

    yDown.onReleased: {
        adapterMaster.yDownReleased();
    }
    xDown.onReleased: {
        adapterMaster.xDownReleased();
    }
    yUp.onReleased: {
        adapterMaster.yUpReleased();
    }
    xUp.onReleased: {
        adapterMaster.xUpReleased();
    }

    button1.onClicked: {
        console.log("Button Pressed. Entered text: " + textField1.text);
    }
}
