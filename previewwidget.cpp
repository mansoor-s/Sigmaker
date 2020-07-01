#include "previewwidget.h"

PreviewWidget::PreviewWidget(QWidget *parent) : QWidget(parent)
{
    this->paintImage();
}

void PreviewWidget::paintImage()
{
    auto imageWidth = 600;
    auto imageHeight = 80;
    this->previewImage = QImage(imageWidth, imageHeight, QImage::Format_RGB32);

    QPainter painter(&this->previewImage);
    painter.fillRect(QRect(0,0, imageWidth,imageHeight),Qt::white);

    painter.setPen(QPen(Qt::black));

    painter.setFont(this->font);
    painter.drawText(QRect(5, 0, imageWidth, imageHeight), this->previewText);
}

void PreviewWidget::textChanged(const QString &text)
{
    this->previewText = text;
    this->paintImage();
    this->repaint();
}


void PreviewWidget::setText(const QString text)
{
    textChanged(text);
}

void PreviewWidget::setFont(const QFont font)
{
    this->font = font;
    this->paintImage();
    this->repaint();
}

void PreviewWidget::setTransparentBg(bool isTransparent)
{
    //TODO
}

QImage PreviewWidget::getImage()
{
    return this->previewImage;
}



void PreviewWidget::paintEvent(QPaintEvent * e)
{
    QPainter painter(this);
    painter.drawImage(0,0, this->previewImage);
}













