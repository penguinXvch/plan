
#include "../hpp/ItemCompSetting.hpp"
#include "../hpp/Global.hpp"
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QRegExpValidator>

ItemCompSetting::ItemCompSetting(int index, QWidget* parent) noexcept
    : QWidget(parent)
    , __index_(index)
{
    __init();
}

ItemCompSetting::~ItemCompSetting() noexcept
{
}

void ItemCompSetting::__init() noexcept
{
    __init_createCtrls();
    __init_decorateCtrls();
    __init_connectCtrlsEvents();
    __init_layoutCtrls();
}

void ItemCompSetting::__init_createCtrls() noexcept
{
    __vertLayout_ = new QVBoxLayout();
    __horiLayout_ = new QHBoxLayout();
    __title_labelCtrl_ = new QLabel();
    __curNumber_labelCtrl_ = new QLabel();
    __curNumber_lineEditCtrl_ = new QLineEdit();
    __addOne_btnCtrl_ = new QPushButton();
    __minusOne_btnCtrl_ = new QPushButton();
    __load_btnCtrl_ = new QPushButton();
}

void ItemCompSetting::__init_decorateCtrls() noexcept
{
    __title_labelCtrl_->setAlignment(Qt::AlignCenter);
    __title_labelCtrl_->setText(itemCompSetting_titleTextSet[__index_]);
    __curNumber_labelCtrl_->setText(itemCompSetting_curNumberText);
    __curNumber_lineEditCtrl_->setValidator(new QRegExpValidator(QRegExp("^([0-9]|10)$"), this));
    __curNumber_lineEditCtrl_->setText(QString::number(itemCompSetting_defaultNumber));
    __addOne_btnCtrl_->setText("+");
    __minusOne_btnCtrl_->setText("-");
    __load_btnCtrl_->setText(itemCompSetting_loadBtnText);
}

void ItemCompSetting::__init_connectCtrlsEvents() noexcept
{
    connect(__addOne_btnCtrl_, &QPushButton::clicked, [this]()
    {
        int number = __curNumber_lineEditCtrl_->text().toInt();
        if (++number > 10) number = 10;
        __curNumber_lineEditCtrl_->setText(QString::number(number));
    });

    connect(__minusOne_btnCtrl_, &QPushButton::clicked, [this]()
    {
        int number = __curNumber_lineEditCtrl_->text().toInt();
        if (--number < 0) number = 0;
        __curNumber_lineEditCtrl_->setText(QString::number(number));
    });
}

void ItemCompSetting::__init_layoutCtrls() noexcept
{
    __horiLayout_->addWidget(__curNumber_labelCtrl_);
    __horiLayout_->addWidget(__curNumber_lineEditCtrl_);
    __horiLayout_->addWidget(__addOne_btnCtrl_);
    __horiLayout_->addWidget(__minusOne_btnCtrl_);

    __vertLayout_->addWidget(__title_labelCtrl_);
    __vertLayout_->addLayout(__horiLayout_);
    __vertLayout_->addWidget(__load_btnCtrl_);

    this->setLayout(__vertLayout_);
}
