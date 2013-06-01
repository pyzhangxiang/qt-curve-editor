#ifndef __SPLINEDISPLAYERWIDGET_H__
#define __SPLINEDISPLAYERWIDGET_H__

#include "GlobalData.h"

#include <QtOpenGL/QGLWidget>
#include <QtGui/QMouseEvent>

#include <vector>

class SplineDisplayerWidget : public QGLWidget{
    Q_OBJECT

public:
    int m_axis;
    aaAaa::Vector3 m_CameraPos;

    static const int Z_VALUE = -10;
    static const int CAMERA_D = 1;
    static const int Y_FACTOR = 1;
    static const float MY_PI;

    QPoint lastPos;

    int ctrlSelected;

    std::vector<double> *m_framedata;
    bool m_bIfModify;

    aaAaa::aaSpline *m_spline_data;
    double m_deltaT;

    int m_width, m_height;

public:
    SplineDisplayerWidget(double deltaT, QWidget *parent = 0);
    ~SplineDisplayerWidget(void);

public:
    void setAE(aaAaa::aaSpline *sdata);

    void setCurrentSelected(int index);

private:
    void drawGrid(void);
    void drawSpline(void);

    aaAaa::Vector2 screen2gl(int x, int y);
    int checkSelected(aaAaa::Vector2 point);

protected:
//		void paintEvent(QPaintEvent *event);
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *);

signals:
    void selectValuesChanged(float t, float v);
};



#endif // __SPLINEDISPLAYERWIDGET_H__
