
#ifndef ITEMCOMPDISPLAY_HPP
#define ITEMCOMPDISPLAY_HPP

#include <QWidget>

class ItemCompDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit ItemCompDisplay(QWidget* parent = nullptr) noexcept;
    ~ItemCompDisplay() noexcept;
};

#endif // ITEMCOMPDISPLAY_HPP
