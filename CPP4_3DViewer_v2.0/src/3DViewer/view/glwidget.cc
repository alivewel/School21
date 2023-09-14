#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent) {
  backgroundColor.setRgb(0, 0, 0);
  verticesColor.setRgb(255, 255, 255);
  facetsColor.setRgb(255, 255, 255);
}

void GLWidget::initializeGL() { glEnable(GL_DEPTH_TEST); }

void GLWidget::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
}

void GLWidget::paintGL() {
  glClearColor(backgroundColor.redF(), backgroundColor.greenF(),
               backgroundColor.blueF(), 1.0f);  // 1
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  if (isParallel) {
    glFrustum(-1, 1, -1, 1, 1, 99999);
  } else {
    glOrtho(-10, 10, -10, 10, -10, 99999);
  }
  glTranslated(0, -1, -10);
  glRotated(xRot_, 1, 0, 0);
  glRotated(yRot_, 0, 1, 0);
  glRotated(zRot_, 0, 0, 1);
  PaintModel();
}

void GLWidget::PaintPoints() {
  if (displayPoint) {
    glColor3d(verticesColor.redF(), verticesColor.greenF(),
              verticesColor.blueF());
    glPointSize(sizeOfVertices);
    if (displayPoint == 1) {
      glEnable(GL_POINT_SMOOTH);
      glDrawArrays(GL_POINTS, 0, verticesAmount);  // рисуем точки
      glDisable(GL_POINT_SMOOTH);
    } else {
      glDrawArrays(GL_POINTS, 0, verticesAmount);  // рисуем точки
    }
  }
}

void GLWidget::PaintLines() {
  glColor3d(facetsColor.redF(), facetsColor.greenF(),
            facetsColor.blueF());  // цвет линии
  glLineWidth(thicknessOfFacets);  // толщина линии
  if (isSolid) {
    glLineStipple(1, 0x3333);  // пунктир
    glEnable(GL_LINE_STIPPLE);
  }
  glDrawElements(GL_LINES, facetsAmount * 2, GL_UNSIGNED_INT,
                 facets.data());  // соединяем точки
  glDisable(GL_LINE_STIPPLE);
}

void GLWidget::PaintModel() {
  glVertexPointer(3, GL_DOUBLE, 0, vertices.data());
  glEnableClientState(GL_VERTEX_ARRAY);
  PaintPoints();
  PaintLines();
  glDisableClientState(GL_VERTEX_ARRAY);
}

void GLWidget::mousePressEvent(QMouseEvent *mo) { mousePosition_ = mo->pos(); }

void GLWidget::mouseMoveEvent(QMouseEvent *mo) {
  xRot_ = 1 / M_PI * (mo->pos().y() - mousePosition_.y());
  yRot_ = 1 / M_PI * (mo->pos().x() - mousePosition_.x());
  update();
}
