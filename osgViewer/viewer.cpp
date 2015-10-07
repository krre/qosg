#include "viewer.h"
#include <QtGui/QOpenGLFramebufferObject>
#include <QtQuick/QQuickWindow>
#include <qsgsimpletexturenode.h>

void ViewerRenderer::render() {
    qDebug() << "render";
//    update();
}

QOpenGLFramebufferObject *ViewerRenderer::createFramebufferObject(const QSize &size) {
    QOpenGLFramebufferObjectFormat format;
    format.setAttachment(QOpenGLFramebufferObject::CombinedDepthStencil);
//    format.setSamples(4);
    return new QOpenGLFramebufferObject(size, format);
}

QQuickFramebufferObject::Renderer* Viewer::createRenderer() const
{
    return new ViewerRenderer();
}
