import QtQuick 2.5
import QtQuick.Controls 1.4
import Osg 1.0 as Osg

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Cube")

    Osg.Viewer {
        anchors.fill: parent
        camera {
            clearColor: "gray"
            fovy: 30
            aspectRatio: width / height
            zNear: 0.1
            zFar: 10000
        }

        sceneData: Osg.Geode {

            Osg.ShapeDrawable {
                color: "red"
                shape: Osg.Box {
                    halfLengths: Qt.vector3d(0.5, 0.5, 0.5)
                }
            }
        }
    }
}
