
#include "../hpp/Item.hpp"
#include "../hpp/Global.hpp"
#include "../hpp/ItemCompSetting.hpp"
#include "../hpp/ItemCompDisplay.hpp"
#include <QVBoxLayout>
#include <QPushButton>

Item::Item(int index, QWidget* parent) noexcept
    : QWidget(parent)
    , __index_(index)
{
    __init();
}

Item::~Item() noexcept
{
}

void Item::setFinish() noexcept
{
    __itemCompSetting_->setFinish();
    __itemCompDisplay_->setFinish();
}

void Item::__init() noexcept
{
    __init_createCtrls();
    __init_connectCtrlsEvents();
    __init_layoutCtrls();
}

void Item::__init_createCtrls() noexcept
{
    __vertLayout_ = new QVBoxLayout();
    __itemCompSetting_ = new ItemCompSetting(__index_);
    __itemCompDisplay_ = new ItemCompDisplay();
}

void Item::__init_connectCtrlsEvents() noexcept
{
    connect(__itemCompSetting_->getLoadBtnCtrlPointer(), &QPushButton::clicked, [this]()
    {
        __itemCompDisplay_->clearListWidgetItem();

        QString path = selectFolder_curPath + "/" + itemCompSetting_titleTextSet[__index_];
        QVector<QString> files = getAllChildFileNames(path);
        QVector<QString> selectFiles =
            selectFilesAlgorithm(files, __itemCompSetting_->getLineEditCtrlDisplayNumber());

        foreach (QString text, selectFiles)
        {
            __itemCompDisplay_->addListWidgetItem(text);
        }
    });

    connect(__itemCompSetting_->getFinishBtnCtrlPointer(), &QPushButton::clicked, [this]()
    {
        setFinish();

        QString path = selectFolder_curPath + "/" + itemCompSetting_titleTextSet[__index_];
        writeTodayFinishedItem(path);
    });
}

void Item::__init_layoutCtrls() noexcept
{
    __vertLayout_->addWidget(__itemCompSetting_);
    __vertLayout_->addWidget(__itemCompDisplay_);

    this->setLayout(__vertLayout_);
}
