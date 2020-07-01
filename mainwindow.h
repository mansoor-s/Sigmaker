#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QBrush>
#include <QGraphicsScene>
#include <QFile>
#include <QCommonStyle>

#include "aboutdialog.h"
#include "previewwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QList<QFont> fontsList);
    ~MainWindow();


protected slots:
    void showAboutDialog();
    void nextFont();
    void prevFont();

private:
    Ui::MainWindow *ui;
    AboutDialog *aboutDialog;
    PreviewWidget *previewWidget;
    QList<QFont> fontsList;
    int fontIdx = 0;
    int fontSize = 24;

    void changeFont();

};
#endif // MAINWINDOW_H
