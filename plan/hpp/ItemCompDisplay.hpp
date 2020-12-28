
#ifndef ITEMCOMPDISPLAY_HPP
#define ITEMCOMPDISPLAY_HPP

#include <QWidget>

class QHBoxLayout;
class QListWidget;

class ItemCompDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit ItemCompDisplay(QWidget* parent = nullptr) noexcept;
    ~ItemCompDisplay() noexcept;

public:
    void clearListWidgetItem() noexcept;
    void addListWidgetItem(const QString& text) noexcept;

public:
    void setFinish() noexcept;

private:
    QHBoxLayout* __horiLayout_ = nullptr;
    QListWidget* __list_ = nullptr;

private:
    void __init() noexcept;
    void __init_createCtrls() noexcept;
    void __init_layoutCtrls() noexcept;
    void __init_beautifyCtrls() noexcept;
};

#endif // ITEMCOMPDISPLAY_HPP
