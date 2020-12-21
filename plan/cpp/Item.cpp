
#include "../hpp/Item.hpp"
#include "../hpp/ItemCompSetting.hpp"
#include "../hpp/ItemCompDisplay.hpp"
#include <QVBoxLayout>

Item::Item(int index, QWidget* parent) noexcept
    : QWidget(parent)
    , __index_(index)
{
    __init();
}

Item::~Item() noexcept
{
}

void Item::__init() noexcept
{
    __init_createCtrls();
    __init_layoutCtrls();
}

void Item::__init_createCtrls() noexcept
{
    __vertLayout_ = new QVBoxLayout();
    __itemCompSetting_ = new ItemCompSetting(__index_);
    __itemCompDisplay_ = new ItemCompDisplay();
}

void Item::__init_layoutCtrls() noexcept
{
    __vertLayout_->addWidget(__itemCompSetting_);
    __vertLayout_->addWidget(__itemCompDisplay_);

    this->setLayout(__vertLayout_);
}
