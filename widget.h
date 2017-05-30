#ifndef WIDGET_H
#define WIDGET_H

#include <QOpenGLWidget>
#include<QMatrix4x4>
#include<QOpenGLShaderProgram>
#include<QOpenGLTexture>
#include<QOpenGLBuffer>

struct VertexData
{
    VertexData()
    {

    }
    VertexData(QVector3D p, QVector2D t):
        position(p),textCoord(t)
    {
    }

    QVector3D position;
    QVector2D textCoord;    
};

class Widget : public QOpenGLWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void initShaders();
    void initFace(float width, float height);

private:
    QMatrix4x4 m_projectionMatrix;
    QOpenGLShaderProgram m_program;
    QOpenGLTexture *m_texture;
    QOpenGLBuffer m_arrayBuffer;
    QOpenGLBuffer m_indexBuffer;

};

#endif // WIDGET_H
