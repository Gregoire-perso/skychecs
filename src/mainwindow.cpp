#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pieces->setVisible(false);
    ui->chessBoard->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startButton_clicked()
{
    // Here we instantiate the brand new Game
    m_game = new Game();
    // We hide buttons
    ui->startButton->setVisible(false);
    ui->loadButton->setVisible(false);
    // Show the menu
    





    // And then we draw the board (how do I do is another question for another day)
    //ui->chessBoard->setVisible(true);
    //ui->pieces->setVisible(true);
}


void MainWindow::on_loadButton_clicked()
{
    // Here we launch a file explorer to find the saved game
    // And we instantiate it
    // We hide buttons
    // And then we draw the board
}

