import QtQuick 2.5
import QtQuick.Controls 1.4
import QOsg 0.1 as QOsg

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Cube")

    QOsg.Viewer {
        anchors.fill: parent
        allowThrow: true
        camera {
            clearColor: "gray"
            fovy: 30
            aspectRatio: width / height
            zNear: 0.1
            zFar: 10000
        }

        sceneData: QOsg.Geode {

            QOsg.ShapeDrawable {
                color: "red"
                shape: Osg.Box {
                    halfLengths: Qt.vector3d(0.5, 0.5, 0.5)
                }
            }
        }
    }
}
