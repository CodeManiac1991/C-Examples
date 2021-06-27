#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "wopengl.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void deleteGL();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

private:
    Ui::MainWindow *ui;
    float m_fVar;
    QTimer *timer;
    QTimer *timer2;
    SceneGL *opengl_window;
};

#endif // MAINWINDOW_H
