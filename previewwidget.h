#ifndef SIGNITUREPREVIEWWIDGET_H
#define SIGNITUREPREVIEWWIDGET_H

#include <QWidget>
#include <QDebug>

#include <QImage>
#include <QPainter>

class PreviewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PreviewWidget(QWidget *parent = nullptr);
    void setText(const QString text);
    void setFont(const QFont font);
    void setTransparentBg(bool isTransparent);
    QImage getImage();

private:
    QString previewText = "Placeholder";
    void paintImage();
    QFont font;

    QImage previewImage;

public slots:
    void textChanged(const QString &);
    void paintEvent(QPaintEvent *);

signals:

};

#endif // SIGNITUREPREVIEWWIDGET_H
