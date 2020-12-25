
#include "../hpp/ItemCompDisplay.hpp"
#include <QHBoxLayout>
#include <QListWidget>

ItemCompDisplay::ItemCompDisplay(QWidget* parent) noexcept
    : QWidget(parent)
{
    __init();
}

ItemCompDisplay::~ItemCompDisplay() noexcept
{
}

void ItemCompDisplay::clearListWidgetItem() noexcept
{
    int count = __list_->count();

    for (int _ = 0; _ < count; ++_)
    {
        QListWidgetItem* item = __list_->takeItem(0);
        delete item;
        item = nullptr;
    }
}

void ItemCompDisplay::addListWidgetItem(const QString& text) noexcept
{
    QListWidgetItem* item = new QListWidgetItem(text, __list_);
    __list_->addItem(item);
}

void ItemCompDisplay::__init() noexcept
{
    __init_createCtrls();
    __init_layoutCtrls();
    __init_beautifyCtrls();
}

void ItemCompDisplay::__init_createCtrls() noexcept
{
    __horiLayout_ = new QHBoxLayout();
    __list_ = new QListWidget();
}

void ItemCompDisplay::__init_layoutCtrls() noexcept
{
    __horiLayout_->addWidget(__list_);

    this->setLayout(__horiLayout_);
}

void ItemCompDisplay::__init_beautifyCtrls() noexcept
{
    QString styleSheet = " font-size:   16px;    "
                         " font-weight: bold;    "
                         " font-family: Consolas ";

    __list_->setStyleSheet(styleSheet);
}
