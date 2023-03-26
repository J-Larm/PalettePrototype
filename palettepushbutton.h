#ifndef PALETTEPUSHBUTTON_H
#define PALETTEPUSHBUTTON_H

#include <QPushButton>
#include <QObject>

class PalettePushButton : public QPushButton
{
    Q_OBJECT

    QColor paletteColor;

public:
    PalettePushButton(QWidget* parent, QColor color);

private slots:
    void prepareToSendcolor();

signals:
    void sendColor(QColor color);

};

#endif // PALETTEPUSHBUTTON_H
