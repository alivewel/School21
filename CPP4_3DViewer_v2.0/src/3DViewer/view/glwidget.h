#ifndef CPP4_3DVIEWER_V2_SRC_3DVIEWER_VIEW_GLWIDGET_H
#define CPP4_3DVIEWER_V2_SRC_3DVIEWER_VIEW_GLWIDGET_H

#define GL_SILENCE_DEPRECATION

#include <GLUT/glut.h>
#include <OpenGL/gl.h>

#include <QColor>
#include <QFileDialog>
#include <QOpenGLWidget>
#include <QtGui/QColor>
#include <QtOpenGL>
#include <iostream>

class GLWidget : public QOpenGLWidget {
  Q_OBJECT

 public:
  GLWidget(QWidget* parent = nullptr);

  double zoom = 1;
  double moveX = 0.0, moveY = 0.0, moveZ = 0.0;
  double rotateX = 0.0, rotateY = 0.0, rotateZ = 0.0;
  QColor backgroundColor;
  QColor verticesColor;
  QColor facetsColor;
  int isSolid = 0;
  int isParallel = 0;
  int displayPoint = 0;
  float sizeOfVertices = 0.0, thicknessOfFacets = 0.0;
  int x = 0, y = 1, z = 2;

  long verticesAmount = 0;
  long facetsAmount = 0;
  std::vector<double> vertices;
  std::vector<int> facets;

  void DecreaseModel();
  void OpenFile(const char* filename, int* error);
  void PaintModel();

 private:
  float xRot_ = 0.0, yRot_ = 0.0, zRot_ = 0.0;
  QPoint mousePosition_;

  void initializeGL();
  void resizeGL(int w, int h);
  void paintGL();

  void PaintLines();
  void PaintPoints();
  void mousePressEvent(QMouseEvent*);
  void mouseMoveEvent(QMouseEvent*);
};

#endif  // CPP4_3DVIEWER_V2_SRC_3DVIEWER_VIEW_GLWIDGET_H
