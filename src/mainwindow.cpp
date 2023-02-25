#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startButton_clicked()
{
    // Here we instantiate the brand new Game
    // We hide buttons
    // And then we draw the board (how do I do is another question for another day)
}


void MainWindow::on_loadButton_clicked()
{
    // Here we launch a file explorer to find the saved game
    // And we instantiate it
    // We hide buttons
    // And then we draw the board
}

