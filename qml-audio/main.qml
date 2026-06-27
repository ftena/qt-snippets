import QtQuick
import QtQuick.Window 
import QtMultimedia 

Window {
    visible: true
    width: 360
    height: 360
    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton

        onClicked: {
            if (mouse.button == Qt.RightButton)
                playMP3.play()
            else
                playWAV.play()
        }
    }

    SoundEffect {
        id: playWAV
        source: "res/kid_giggle.wav"

        onPlayingChanged: {
            console.log("SoundEffect - onPlayingChanged - category: " + category)
        }
    }

    MediaPlayer {
        id: playMP3
        source: "res/kid_giggle.mp3"

        onPlaying: {
            console.log("MediaPlayer - onPlaying - duration: " + duration)
        }
    }
}

