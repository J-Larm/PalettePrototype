#include "palettepushbutton.h"

PalettePushButton::PalettePushButton(QWidget *parent, QColor color) :
    QPushButton(parent)
{
    paletteColor = color;
    qDebug("Color: %d, %d, %d", color.red(), color.green(), color.blue());
    QString style = QString("background-color:rgb(%1, %2, %3)").arg(QString::number(color.red()), QString::number(color.green()), QString::number(color.blue()));
    this->setStyleSheet(style);
    this->setText("");

    connect(this, &PalettePushButton::clicked, this, &PalettePushButton::prepareToSendcolor);
}

void PalettePushButton::prepareToSendcolor()
{
    qDebug("Preparing to Send Color");
    emit sendColor(paletteColor);
}
