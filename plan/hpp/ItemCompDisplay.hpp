
#ifndef ITEMCOMPDISPLAY_HPP
#define ITEMCOMPDISPLAY_HPP

#include <QWidget>

class QListWidget;

class ItemCompDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit ItemCompDisplay(QWidget* parent = nullptr) noexcept;
    ~ItemCompDisplay() noexcept;

private:
    QListWidget* __list_ = nullptr;
};

#endif // ITEMCOMPDISPLAY_HPP
