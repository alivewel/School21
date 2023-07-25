#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <graphwindow.h>
#include <QVector>

extern "C" {
#include "../../s21_calc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    graphwindow *graphwindow;

private slots:
    void digits_numbers();
    void functions();
    void on_pushButton_dot_clicked();
    void operations();
    void arithmetic();
    void clearEverything();
    void clearLastSymbol();
    void calculate();
    void value_x();
    void graph();
    void funcPushGraph();

signals:
    void signal(QString);

};
#endif // MAINWINDOW_H
