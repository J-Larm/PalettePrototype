#ifndef PALETTE_H
#define PALETTE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Palette; }
QT_END_NAMESPACE

class Palette : public QMainWindow
{
    Q_OBJECT

    size_t currentPaletteColumn;
    size_t currentPaletteRow;

public:
    Palette(QWidget *parent = nullptr);
    ~Palette();

private slots:
    void onPaletteButtonClick(QColor color);

    void addPalette();

private:
    Ui::Palette *ui;

    void addPaletteButton(QColor color);

    QWidget* parentForPaletteButtons;
};
#endif // PALETTE_H
