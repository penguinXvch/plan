
#ifndef ITEM_HPP
#define ITEM_HPP

#include <QWidget>

class Item : public QWidget
{
    Q_OBJECT

public:
    explicit Item(QWidget* parent = nullptr) noexcept;
    ~Item() noexcept;
};

#endif // ITEM_HPP
