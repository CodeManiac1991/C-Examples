#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
  ,m_fVar(0)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(on_pushButton_2_clicked()));
    timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(deleteGL()));

    opengl_window = new SceneGL;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    opengl_window->show();
    timer->start(5);
    timer2->start(4);
}

void MainWindow::on_pushButton_2_clicked()
{
    m_fVar +=1;
    opengl_window->rotate(m_fVar);
}

void MainWindow::deleteGL()
{
    opengl_window->update();
}

void MainWindow::on_pushButton_3_clicked()
{
    opengl_window->setY(0.5f);
    opengl_window->update();
}

void MainWindow::on_pushButton_4_clicked()
{
    opengl_window->setY(-0.5f);
    opengl_window->update();
}

void MainWindow::on_pushButton_6_clicked()
{
    opengl_window->setX(-0.5f);
    opengl_window->update();
}

void MainWindow::on_pushButton_5_clicked()
{
    opengl_window->setX(0.5f);
    opengl_window->update();
}

void MainWindow::on_pushButton_18_clicked()
{
    opengl_window->rotateX(-0.5f);
    opengl_window->update();
}

void MainWindow::on_pushButton_17_clicked()
{
    opengl_window->rotateX(0.5f);
    opengl_window->update();
}

void MainWindow::on_pushButton_15_clicked()
{
    opengl_window->rotateY(-0.5f);
    opengl_window->update();
}

void MainWindow::on_pushButton_16_clicked()
{
    opengl_window->rotateY(0.5f);
    opengl_window->update();
}
