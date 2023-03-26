#include "palette.h"
#include "palettepushbutton.h"
#include "ui_palette.h"

Palette::Palette(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Palette)
{
    ui->setupUi(this);

    parentForPaletteButtons = parent;

    currentPaletteColumn = 0;
    currentPaletteRow = 0;

    addPaletteButton(QColor(0,0,0));
    addPaletteButton(QColor(255,0,0));
    addPaletteButton(QColor(0,255,0));
    addPaletteButton(QColor(0,0,255));

    // Button For Adding

    connect(ui->pushButton, &QPushButton::clicked, this, &Palette::addPalette);

}

Palette::~Palette()
{
    delete ui;
}

void Palette::onPaletteButtonClick(QColor color)
{
    qDebug("Color %d %d %d", color.red(), color.green(), color.blue());
    QString style = QString("background-color:rgb(%1, %2, %3)").arg(QString::number(color.red()), QString::number(color.green()), QString::number(color.blue()));
    ui->currentColorDisplay->setStyleSheet(style);
}

void Palette::addPalette()
{
    addPaletteButton(QColor(0,0,0));
}

void Palette::addPaletteButton(QColor color)
{
    PalettePushButton* paletteButton = new PalettePushButton(parentForPaletteButtons, color);
    connect(paletteButton, &PalettePushButton::sendColor, this, &Palette::onPaletteButtonClick);
    ui->gridLayout->addWidget(paletteButton, currentPaletteRow, currentPaletteColumn);

    qDebug("%d, %d", (int)currentPaletteColumn, (int)currentPaletteRow);

    currentPaletteColumn++;
    if (currentPaletteColumn > 3)
    {
        currentPaletteRow++;
        currentPaletteColumn = 0;
    }

}



