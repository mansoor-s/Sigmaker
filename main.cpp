#include "mainwindow.h"

#include <QApplication>
#include <QList>
#include <QFont>
#include <QDirIterator>
#include <QFontDatabase>

QList<QFont> loadFonts();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto fonts = loadFonts();
    MainWindow w(fonts);

    w.show();
    return a.exec();
}


QList<QFont> loadFonts()
{
    QList<QFont> fonts;
    QDirIterator it(":/fonts/fonts", QDirIterator::Subdirectories);
    while (it.hasNext()) {
        auto fontPath = it.next();
        if(!fontPath.endsWith(".ttf")) {
            continue;
        }

        int id = QFontDatabase::addApplicationFont(fontPath);
        QString family = QFontDatabase::applicationFontFamilies(id).at(0);
        QFont loadedFont(family);
        fonts.append(loadedFont);
    }

    return fonts;
}
