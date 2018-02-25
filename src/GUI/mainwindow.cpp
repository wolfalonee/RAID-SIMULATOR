#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BACKEND/metafun.h"

namespace metafun{
    GENERATE_ALL_CHECKS(tesztVar);
    GENERATE_ALL_CHECKS(tesztFunc);
    GENERATE_ALL_CHECKS(tesztType);
    GENERATE_ALL_CHECKS(tesztEnum);
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
