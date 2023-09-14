/********************************************************************************
** Form generated from reading UI file 'viewer.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWER_H
#define UI_VIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <view/glwidget.h>

QT_BEGIN_NAMESPACE

class Ui_Viewer
{
public:
    QWidget *centralwidget;
    GLWidget *GLwidget;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_zoom;
    QDoubleSpinBox *doubleSpinBox_zoom;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label__move_x;
    QDoubleSpinBox *doubleSpinBox_move_x;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label__move_y;
    QDoubleSpinBox *doubleSpinBox_move_y;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_move_z;
    QDoubleSpinBox *doubleSpinBox_move_z;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_rotate_x;
    QDoubleSpinBox *doubleSpinBox_rotate_x;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_rotate_y;
    QDoubleSpinBox *doubleSpinBox_rotate_y;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_rotate_z;
    QDoubleSpinBox *doubleSpinBox_rotate_z;
    QFrame *line_5;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_filename_text;
    QLabel *label_filename_value;
    QFrame *line_6;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_number_of_vertices_text;
    QLabel *label_number_of_vertices_info;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_number_of_facets_text;
    QLabel *label_number_of_facets_info;
    QPushButton *pushButton_vertices_set_color;
    QPushButton *pushButton_facets_set_color;
    QPushButton *pushButton_background_set_color;
    QFrame *line_7;
    QPushButton *pushButton_screenshot;
    QPushButton *pushButton_gif;
    QFrame *line_8;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_projection_type;
    QComboBox *comboBox_projection_type;
    QWidget *layoutWidget7;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_facets_type;
    QComboBox *comboBox_facets_type;
    QWidget *layoutWidget8;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_way_to_display;
    QComboBox *comboBox_way_to_display;
    QFrame *line_9;
    QWidget *layoutWidget9;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_size_of_vertices;
    QDoubleSpinBox *doubleSpinBox_size_of_vertices;
    QWidget *layoutWidget10;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_thickness_of_facets;
    QDoubleSpinBox *doubleSpinBox_thickness_of_facets;
    QPushButton *pushButton_save_settings;
    QPushButton *pushButton_load_settings;
    QPushButton *uploadFileButton;
    QPushButton *pushButton_default_settings;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Viewer)
    {
        if (Viewer->objectName().isEmpty())
            Viewer->setObjectName(QString::fromUtf8("Viewer"));
        Viewer->resize(1092, 1100);
        centralwidget = new QWidget(Viewer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        GLwidget = new GLWidget(centralwidget);
        GLwidget->setObjectName(QString::fromUtf8("GLwidget"));
        GLwidget->setGeometry(QRect(280, 10, 791, 1021));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 80, 260, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(10, 260, 260, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(10, 390, 260, 3));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 220, 261, 23));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_zoom = new QLabel(layoutWidget);
        label_zoom->setObjectName(QString::fromUtf8("label_zoom"));

        horizontalLayout->addWidget(label_zoom);

        doubleSpinBox_zoom = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_zoom->setObjectName(QString::fromUtf8("doubleSpinBox_zoom"));
        doubleSpinBox_zoom->setMinimum(1.000000000000000);
        doubleSpinBox_zoom->setValue(1.000000000000000);

        horizontalLayout->addWidget(doubleSpinBox_zoom);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 280, 261, 91));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label__move_x = new QLabel(layoutWidget1);
        label__move_x->setObjectName(QString::fromUtf8("label__move_x"));

        horizontalLayout_2->addWidget(label__move_x);

        doubleSpinBox_move_x = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox_move_x->setObjectName(QString::fromUtf8("doubleSpinBox_move_x"));
        doubleSpinBox_move_x->setMinimum(-100.000000000000000);
        doubleSpinBox_move_x->setMaximum(100.000000000000000);

        horizontalLayout_2->addWidget(doubleSpinBox_move_x);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label__move_y = new QLabel(layoutWidget1);
        label__move_y->setObjectName(QString::fromUtf8("label__move_y"));

        horizontalLayout_3->addWidget(label__move_y);

        doubleSpinBox_move_y = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox_move_y->setObjectName(QString::fromUtf8("doubleSpinBox_move_y"));
        doubleSpinBox_move_y->setMinimum(-100.000000000000000);
        doubleSpinBox_move_y->setMaximum(100.000000000000000);

        horizontalLayout_3->addWidget(doubleSpinBox_move_y);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_move_z = new QLabel(layoutWidget1);
        label_move_z->setObjectName(QString::fromUtf8("label_move_z"));

        horizontalLayout_4->addWidget(label_move_z);

        doubleSpinBox_move_z = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox_move_z->setObjectName(QString::fromUtf8("doubleSpinBox_move_z"));
        doubleSpinBox_move_z->setMinimum(-100.000000000000000);
        doubleSpinBox_move_z->setMaximum(100.000000000000000);

        horizontalLayout_4->addWidget(doubleSpinBox_move_z);


        verticalLayout->addLayout(horizontalLayout_4);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 410, 261, 91));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_rotate_x = new QLabel(layoutWidget2);
        label_rotate_x->setObjectName(QString::fromUtf8("label_rotate_x"));

        horizontalLayout_5->addWidget(label_rotate_x);

        doubleSpinBox_rotate_x = new QDoubleSpinBox(layoutWidget2);
        doubleSpinBox_rotate_x->setObjectName(QString::fromUtf8("doubleSpinBox_rotate_x"));
        doubleSpinBox_rotate_x->setMinimum(-1000.000000000000000);
        doubleSpinBox_rotate_x->setMaximum(1000.000000000000000);

        horizontalLayout_5->addWidget(doubleSpinBox_rotate_x);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_rotate_y = new QLabel(layoutWidget2);
        label_rotate_y->setObjectName(QString::fromUtf8("label_rotate_y"));

        horizontalLayout_6->addWidget(label_rotate_y);

        doubleSpinBox_rotate_y = new QDoubleSpinBox(layoutWidget2);
        doubleSpinBox_rotate_y->setObjectName(QString::fromUtf8("doubleSpinBox_rotate_y"));
        doubleSpinBox_rotate_y->setMinimum(-1000.000000000000000);
        doubleSpinBox_rotate_y->setMaximum(1000.000000000000000);

        horizontalLayout_6->addWidget(doubleSpinBox_rotate_y);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_rotate_z = new QLabel(layoutWidget2);
        label_rotate_z->setObjectName(QString::fromUtf8("label_rotate_z"));

        horizontalLayout_7->addWidget(label_rotate_z);

        doubleSpinBox_rotate_z = new QDoubleSpinBox(layoutWidget2);
        doubleSpinBox_rotate_z->setObjectName(QString::fromUtf8("doubleSpinBox_rotate_z"));
        doubleSpinBox_rotate_z->setMinimum(-1000.000000000000000);
        doubleSpinBox_rotate_z->setMaximum(1000.000000000000000);

        horizontalLayout_7->addWidget(doubleSpinBox_rotate_z);


        verticalLayout_2->addLayout(horizontalLayout_7);

        line_5 = new QFrame(centralwidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(10, 200, 260, 3));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 100, 261, 21));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_filename_text = new QLabel(layoutWidget3);
        label_filename_text->setObjectName(QString::fromUtf8("label_filename_text"));

        horizontalLayout_8->addWidget(label_filename_text);

        label_filename_value = new QLabel(layoutWidget3);
        label_filename_value->setObjectName(QString::fromUtf8("label_filename_value"));
        label_filename_value->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(label_filename_value);

        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(10, 520, 260, 3));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        layoutWidget4 = new QWidget(centralwidget);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 130, 261, 18));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_number_of_vertices_text = new QLabel(layoutWidget4);
        label_number_of_vertices_text->setObjectName(QString::fromUtf8("label_number_of_vertices_text"));

        horizontalLayout_9->addWidget(label_number_of_vertices_text);

        label_number_of_vertices_info = new QLabel(layoutWidget4);
        label_number_of_vertices_info->setObjectName(QString::fromUtf8("label_number_of_vertices_info"));
        label_number_of_vertices_info->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(label_number_of_vertices_info);

        layoutWidget5 = new QWidget(centralwidget);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(10, 160, 261, 18));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_number_of_facets_text = new QLabel(layoutWidget5);
        label_number_of_facets_text->setObjectName(QString::fromUtf8("label_number_of_facets_text"));

        horizontalLayout_10->addWidget(label_number_of_facets_text);

        label_number_of_facets_info = new QLabel(layoutWidget5);
        label_number_of_facets_info->setObjectName(QString::fromUtf8("label_number_of_facets_info"));
        label_number_of_facets_info->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_10->addWidget(label_number_of_facets_info);

        pushButton_vertices_set_color = new QPushButton(centralwidget);
        pushButton_vertices_set_color->setObjectName(QString::fromUtf8("pushButton_vertices_set_color"));
        pushButton_vertices_set_color->setGeometry(QRect(50, 560, 181, 32));
        pushButton_facets_set_color = new QPushButton(centralwidget);
        pushButton_facets_set_color->setObjectName(QString::fromUtf8("pushButton_facets_set_color"));
        pushButton_facets_set_color->setGeometry(QRect(50, 590, 181, 32));
        pushButton_background_set_color = new QPushButton(centralwidget);
        pushButton_background_set_color->setObjectName(QString::fromUtf8("pushButton_background_set_color"));
        pushButton_background_set_color->setGeometry(QRect(50, 530, 181, 32));
        line_7 = new QFrame(centralwidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(10, 630, 260, 3));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        pushButton_screenshot = new QPushButton(centralwidget);
        pushButton_screenshot->setObjectName(QString::fromUtf8("pushButton_screenshot"));
        pushButton_screenshot->setGeometry(QRect(40, 860, 201, 32));
        pushButton_gif = new QPushButton(centralwidget);
        pushButton_gif->setObjectName(QString::fromUtf8("pushButton_gif"));
        pushButton_gif->setGeometry(QRect(40, 890, 201, 32));
        line_8 = new QFrame(centralwidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(10, 750, 260, 3));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);
        layoutWidget6 = new QWidget(centralwidget);
        layoutWidget6->setObjectName(QString::fromUtf8("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(10, 640, 261, 32));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_projection_type = new QLabel(layoutWidget6);
        label_projection_type->setObjectName(QString::fromUtf8("label_projection_type"));

        horizontalLayout_11->addWidget(label_projection_type);

        comboBox_projection_type = new QComboBox(layoutWidget6);
        comboBox_projection_type->addItem(QString());
        comboBox_projection_type->addItem(QString());
        comboBox_projection_type->setObjectName(QString::fromUtf8("comboBox_projection_type"));

        horizontalLayout_11->addWidget(comboBox_projection_type);

        layoutWidget7 = new QWidget(centralwidget);
        layoutWidget7->setObjectName(QString::fromUtf8("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(10, 670, 261, 32));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget7);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_facets_type = new QLabel(layoutWidget7);
        label_facets_type->setObjectName(QString::fromUtf8("label_facets_type"));

        horizontalLayout_12->addWidget(label_facets_type);

        comboBox_facets_type = new QComboBox(layoutWidget7);
        comboBox_facets_type->addItem(QString());
        comboBox_facets_type->addItem(QString());
        comboBox_facets_type->setObjectName(QString::fromUtf8("comboBox_facets_type"));

        horizontalLayout_12->addWidget(comboBox_facets_type);

        layoutWidget8 = new QWidget(centralwidget);
        layoutWidget8->setObjectName(QString::fromUtf8("layoutWidget8"));
        layoutWidget8->setGeometry(QRect(10, 700, 261, 32));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget8);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        label_way_to_display = new QLabel(layoutWidget8);
        label_way_to_display->setObjectName(QString::fromUtf8("label_way_to_display"));

        horizontalLayout_13->addWidget(label_way_to_display);

        comboBox_way_to_display = new QComboBox(layoutWidget8);
        comboBox_way_to_display->addItem(QString());
        comboBox_way_to_display->addItem(QString());
        comboBox_way_to_display->addItem(QString());
        comboBox_way_to_display->setObjectName(QString::fromUtf8("comboBox_way_to_display"));

        horizontalLayout_13->addWidget(comboBox_way_to_display);

        line_9 = new QFrame(centralwidget);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setGeometry(QRect(10, 840, 260, 3));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);
        layoutWidget9 = new QWidget(centralwidget);
        layoutWidget9->setObjectName(QString::fromUtf8("layoutWidget9"));
        layoutWidget9->setGeometry(QRect(11, 770, 261, 23));
        horizontalLayout_14 = new QHBoxLayout(layoutWidget9);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        label_size_of_vertices = new QLabel(layoutWidget9);
        label_size_of_vertices->setObjectName(QString::fromUtf8("label_size_of_vertices"));

        horizontalLayout_14->addWidget(label_size_of_vertices);

        doubleSpinBox_size_of_vertices = new QDoubleSpinBox(layoutWidget9);
        doubleSpinBox_size_of_vertices->setObjectName(QString::fromUtf8("doubleSpinBox_size_of_vertices"));

        horizontalLayout_14->addWidget(doubleSpinBox_size_of_vertices);

        layoutWidget10 = new QWidget(centralwidget);
        layoutWidget10->setObjectName(QString::fromUtf8("layoutWidget10"));
        layoutWidget10->setGeometry(QRect(10, 800, 261, 23));
        horizontalLayout_15 = new QHBoxLayout(layoutWidget10);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        label_thickness_of_facets = new QLabel(layoutWidget10);
        label_thickness_of_facets->setObjectName(QString::fromUtf8("label_thickness_of_facets"));

        horizontalLayout_15->addWidget(label_thickness_of_facets);

        doubleSpinBox_thickness_of_facets = new QDoubleSpinBox(layoutWidget10);
        doubleSpinBox_thickness_of_facets->setObjectName(QString::fromUtf8("doubleSpinBox_thickness_of_facets"));

        horizontalLayout_15->addWidget(doubleSpinBox_thickness_of_facets);

        pushButton_save_settings = new QPushButton(centralwidget);
        pushButton_save_settings->setObjectName(QString::fromUtf8("pushButton_save_settings"));
        pushButton_save_settings->setGeometry(QRect(40, 920, 100, 32));
        pushButton_load_settings = new QPushButton(centralwidget);
        pushButton_load_settings->setObjectName(QString::fromUtf8("pushButton_load_settings"));
        pushButton_load_settings->setGeometry(QRect(140, 920, 100, 32));
        uploadFileButton = new QPushButton(centralwidget);
        uploadFileButton->setObjectName(QString::fromUtf8("uploadFileButton"));
        uploadFileButton->setGeometry(QRect(80, 10, 120, 51));
        pushButton_default_settings = new QPushButton(centralwidget);
        pushButton_default_settings->setObjectName(QString::fromUtf8("pushButton_default_settings"));
        pushButton_default_settings->setGeometry(QRect(40, 950, 201, 32));
        Viewer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Viewer);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1092, 24));
        Viewer->setMenuBar(menubar);
        statusbar = new QStatusBar(Viewer);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Viewer->setStatusBar(statusbar);

        retranslateUi(Viewer);

        QMetaObject::connectSlotsByName(Viewer);
    } // setupUi

    void retranslateUi(QMainWindow *Viewer)
    {
        Viewer->setWindowTitle(QCoreApplication::translate("Viewer", "3DViewer_v2.0", nullptr));
        label_zoom->setText(QCoreApplication::translate("Viewer", "Zooming", nullptr));
        label__move_x->setText(QCoreApplication::translate("Viewer", "Move X", nullptr));
        label__move_y->setText(QCoreApplication::translate("Viewer", "Move Y", nullptr));
        label_move_z->setText(QCoreApplication::translate("Viewer", "Move Z", nullptr));
        label_rotate_x->setText(QCoreApplication::translate("Viewer", "Rotate on X", nullptr));
        label_rotate_y->setText(QCoreApplication::translate("Viewer", "Rotate on Y", nullptr));
        label_rotate_z->setText(QCoreApplication::translate("Viewer", "Rotate on Z", nullptr));
        label_filename_text->setText(QCoreApplication::translate("Viewer", "Filename:", nullptr));
        label_filename_value->setText(QString());
        label_number_of_vertices_text->setText(QCoreApplication::translate("Viewer", "Number of vertices:", nullptr));
        label_number_of_vertices_info->setText(QString());
        label_number_of_facets_text->setText(QCoreApplication::translate("Viewer", "Number of edges:", nullptr));
        label_number_of_facets_info->setText(QString());
        pushButton_vertices_set_color->setText(QCoreApplication::translate("Viewer", "Set vertices color", nullptr));
        pushButton_facets_set_color->setText(QCoreApplication::translate("Viewer", "Set facets color", nullptr));
        pushButton_background_set_color->setText(QCoreApplication::translate("Viewer", "Set background color", nullptr));
        pushButton_screenshot->setText(QCoreApplication::translate("Viewer", "Make a ScreenShot ", nullptr));
        pushButton_gif->setText(QCoreApplication::translate("Viewer", "Make a GIF", nullptr));
        label_projection_type->setText(QCoreApplication::translate("Viewer", "Projection type", nullptr));
        comboBox_projection_type->setItemText(0, QCoreApplication::translate("Viewer", "Parallel", nullptr));
        comboBox_projection_type->setItemText(1, QCoreApplication::translate("Viewer", "Central", nullptr));

        label_facets_type->setText(QCoreApplication::translate("Viewer", "Facets type", nullptr));
        comboBox_facets_type->setItemText(0, QCoreApplication::translate("Viewer", "Solid", nullptr));
        comboBox_facets_type->setItemText(1, QCoreApplication::translate("Viewer", "Dotted", nullptr));

        label_way_to_display->setText(QCoreApplication::translate("Viewer", "Vertices type", nullptr));
        comboBox_way_to_display->setItemText(0, QCoreApplication::translate("Viewer", "There is no", nullptr));
        comboBox_way_to_display->setItemText(1, QCoreApplication::translate("Viewer", "\320\241ircle", nullptr));
        comboBox_way_to_display->setItemText(2, QCoreApplication::translate("Viewer", " Square", nullptr));

        label_size_of_vertices->setText(QCoreApplication::translate("Viewer", "Size of vertices:", nullptr));
        label_thickness_of_facets->setText(QCoreApplication::translate("Viewer", " Thickness of facets", nullptr));
        pushButton_save_settings->setText(QCoreApplication::translate("Viewer", "Save settings", nullptr));
        pushButton_load_settings->setText(QCoreApplication::translate("Viewer", "Load settings", nullptr));
        uploadFileButton->setText(QCoreApplication::translate("Viewer", "Upload File", nullptr));
        pushButton_default_settings->setText(QCoreApplication::translate("Viewer", "Default settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Viewer: public Ui_Viewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWER_H
