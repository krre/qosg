#include "renderthread.h"

RenderThread::RenderThread(const QSize& size, osgViewer::Viewer* viewer, osg::Texture2D* fboTexture)
    : osgViewer(viewer),
      fboTexture(fboTexture)
{
    Viewer::threads << this;
    m_size = QSize(size.width(), size.height());
}

void RenderThread::renderNext()
{
    context->makeCurrent(surface);

    if (!m_renderFbo) {
        QOpenGLFramebufferObjectFormat format;
        format.setAttachment(QOpenGLFramebufferObject::CombinedDepthStencil);
        m_renderFbo = new QOpenGLFramebufferObject(m_size, format);
    }

    m_renderFbo->bind();
    context->functions()->glViewport(0, 0, m_size.width(), m_size.height());
    osgViewer->frame();

    // We need to flush the contents to the FBO before posting
    // the texture to the other thread, otherwise, we might
    // get unexpected results.
    context->functions()->glFlush();

    m_renderFbo->bindDefault();

    unsigned int contextID = osgViewer->getCamera()->getGraphicsContext()->getState()->getContextID();
    int id = fboTexture->getTextureObject(contextID)->id();

    emit textureReady(id, m_size);
}

void RenderThread::shutDown()
{
    context->makeCurrent(surface);
    delete m_renderFbo;
    context->doneCurrent();
    delete context;

    // schedule this to be deleted only after we're done cleaning up
    surface->deleteLater();

    // Stop event processing, move the thread to GUI and make sure it is deleted.
    exit();
    moveToThread(QGuiApplication::instance()->thread());
}
