
#ifndef ITEM_HPP
#define ITEM_HPP

#include <QWidget>

class QVBoxLayout;
class ItemCompSetting;
class ItemCompDisplay;

class Item : public QWidget
{
    Q_OBJECT

public:
    explicit Item(int index, QWidget* parent = nullptr) noexcept;
    ~Item() noexcept;

public:
    void setFinish() noexcept;

private:
    QVBoxLayout* __vertLayout_ = nullptr;
    ItemCompSetting* __itemCompSetting_ = nullptr;
    ItemCompDisplay* __itemCompDisplay_ = nullptr;

private:
    void __init() noexcept;
    void __init_createCtrls() noexcept;
    void __init_connectCtrlsEvents() noexcept;
    void __init_layoutCtrls() noexcept;

private:
    int __index_ = -1;
};

#endif // ITEM_HPP
