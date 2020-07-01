#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QList<QFont> fontsList)
    : QMainWindow(nullptr)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    aboutDialog = new AboutDialog(this);
    this->fontsList = fontsList;
    this->changeFont();

    connect(ui->aboutButton, SIGNAL(clicked()), this, SLOT(showAboutDialog()));
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->signitureInput, SIGNAL(textChanged(const QString&)), ui->preview, SLOT(textChanged(const QString&)));

    connect(ui->prevFontButton, SIGNAL(clicked()), this, SLOT(prevFont()));
    connect(ui->nextFontButton, SIGNAL(clicked()), this, SLOT(nextFont()));

}

void MainWindow::showAboutDialog()
{
    aboutDialog->show();
}

void MainWindow::nextFont()
{
    this->fontIdx++;
    this->changeFont();
}

void MainWindow::prevFont()
{
    this->fontIdx--;
    this->changeFont();
}

void MainWindow::changeFont()
{
    if(this->fontIdx < 0) {
        this->fontIdx = this->fontIdx + this->fontsList.length();
    }
    this->fontIdx = this->fontIdx % this->fontsList.length();

    auto font = this->fontsList.at(this->fontIdx);
    font.setPointSize(this->fontSize);

    ui->preview->setFont(font);
    ui->currentStyle->setText(QString("Current Font: ") + font.family());
}


MainWindow::~MainWindow()
{
    delete ui;
}
