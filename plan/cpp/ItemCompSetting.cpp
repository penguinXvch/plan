
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

QPushButton* ItemCompSetting::getLoadBtnCtrlPointer() noexcept
{
    return __load_btnCtrl_;
}

QPushButton* ItemCompSetting::getFinishBtnCtrlPointer() noexcept
{
    return __finish_btnCtrl_;
}

int ItemCompSetting::getLineEditCtrlDisplayNumber() noexcept
{
    return __curNumber_lineEditCtrl_->text().toInt();
}

void ItemCompSetting::setFinish() noexcept
{
    __curNumber_lineEditCtrl_->setEnabled(false);
    __addOne_btnCtrl_->setEnabled(false);
    __minusOne_btnCtrl_->setEnabled(false);
    __load_btnCtrl_->setEnabled(false);
    __finish_btnCtrl_->setEnabled(false);

    __curNumber_lineEditCtrl_->setText("0");
}

void ItemCompSetting::__init() noexcept
{
    __init_createCtrls();
    __init_decorateCtrls();
    __init_connectCtrlsEvents();
    __init_layoutCtrls();
    __init_beautifyCtrls();
}

void ItemCompSetting::__init_createCtrls() noexcept
{
    __vertLayout_ = new QVBoxLayout();
    __labelEdit_horiLayout_ = new QHBoxLayout();
    __addMinusBtns_horiLayout_ = new QHBoxLayout();
    __loadFinishBtns_horiLayout_ = new QHBoxLayout();
    __title_labelCtrl_ = new QLabel();
    __curNumber_labelCtrl_ = new QLabel();
    __curNumber_lineEditCtrl_ = new QLineEdit();
    __addOne_btnCtrl_ = new QPushButton();
    __minusOne_btnCtrl_ = new QPushButton();
    __load_btnCtrl_ = new QPushButton();
    __finish_btnCtrl_ = new QPushButton();
}

void ItemCompSetting::__init_decorateCtrls() noexcept
{
    __title_labelCtrl_->setAlignment(Qt::AlignCenter);
    __title_labelCtrl_->setText(itemCompSetting_titleTextSet[__index_]);
    __curNumber_labelCtrl_->setText(itemCompSetting_curNumberText);
    __curNumber_lineEditCtrl_->setAlignment(Qt::AlignCenter);
    __curNumber_lineEditCtrl_->setValidator(new QRegExpValidator(QRegExp("^([0-9]|10)$"), this));
    __curNumber_lineEditCtrl_->setText(QString::number(itemCompSetting_defaultNumber));
    __addOne_btnCtrl_->setText("+");
    __minusOne_btnCtrl_->setText("-");
    __load_btnCtrl_->setText(itemCompSetting_loadBtnText);
    __finish_btnCtrl_->setText(itemCompSetting_finishBtnText);
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
    __labelEdit_horiLayout_->addWidget(__curNumber_labelCtrl_);
    __labelEdit_horiLayout_->addWidget(__curNumber_lineEditCtrl_);
    __addMinusBtns_horiLayout_->addWidget(__addOne_btnCtrl_);
    __addMinusBtns_horiLayout_->addWidget(__minusOne_btnCtrl_);
    __loadFinishBtns_horiLayout_->addWidget(__load_btnCtrl_);
    __loadFinishBtns_horiLayout_->addWidget(__finish_btnCtrl_);

    __vertLayout_->addWidget(__title_labelCtrl_);
    __vertLayout_->addLayout(__labelEdit_horiLayout_);
    __vertLayout_->addLayout(__addMinusBtns_horiLayout_);
    __vertLayout_->addLayout(__loadFinishBtns_horiLayout_);

    this->setLayout(__vertLayout_);
}

void ItemCompSetting::__init_beautifyCtrls() noexcept
{
    QString styleSheet = " font-size:   18px;   "
                         " font-weight: normal; "
                         " font-family: YouYuan ";

    __curNumber_labelCtrl_->setStyleSheet(styleSheet);
    __curNumber_lineEditCtrl_->setStyleSheet(styleSheet);
    __addOne_btnCtrl_->setStyleSheet(styleSheet);
    __minusOne_btnCtrl_->setStyleSheet(styleSheet);
    __load_btnCtrl_->setStyleSheet(styleSheet);
    __finish_btnCtrl_->setStyleSheet(styleSheet);

    QString title_styleSheet = " color:       #FF4500; "
                               " font-size:   22px;    "
                               " font-weight: bold;    "
                               " font-family: YouYuan  ";

    __title_labelCtrl_->setStyleSheet(title_styleSheet);
}
