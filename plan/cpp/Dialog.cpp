
#include "../hpp/Dialog.hpp"
#include "../hpp/Global.hpp"
#include "../hpp/SelectFolder.hpp"
#include "../hpp/Item.hpp"
#include <QIcon>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDesktopWidget>
#include <QApplication>

Dialog::Dialog(QWidget* parent) noexcept
    : QDialog(parent)
{
    __initDialog();
    __initSelectFolderPart();
    __initItemSetPart(true);
    __dialogLayout();
}

Dialog::~Dialog() noexcept
{
}

void Dialog::__initDialog() noexcept
{
    __initDialog_setFixedSize(true);
    __initDialog_setTitle();
    __initDialog_setIcon();
    __initDialog_hideHelpBtn();
}

void Dialog::__initDialog_setFixedSize(const bool& initDialog) noexcept
{
    QDesktopWidget* desktop = QApplication::desktop();
    int x = 0, y = 0;

    if (initDialog)
    {
        setMinimumSize(dialog_initFixedSize.width(), dialog_initFixedSize.height());
        setMaximumSize(dialog_initFixedSize.width(), dialog_initFixedSize.height());

        x = (desktop->width() - dialog_initFixedSize.width()) / 2;
        y = (desktop->height() - dialog_initFixedSize.height()) / 2;
    }
    else
    {
        int width = itemCompSetting_titleTextSet.count() * dialog_unitItemWidth;

        if (width == 0)
        {
            setMinimumSize(dialog_initFixedSize.width(), dialog_initFixedSize.height());
            setMaximumSize(dialog_initFixedSize.width(), dialog_initFixedSize.height());

            x = (desktop->width() - dialog_initFixedSize.width()) / 2;
            y = (desktop->height() - dialog_initFixedSize.height()) / 2;
        }
        else
        {
            setMinimumSize(width, dialog_nonInitFixedHeight);
            setMaximumSize(width, dialog_nonInitFixedHeight);

            x = (desktop->width() - width) / 2;
            y = (desktop->height() - dialog_nonInitFixedHeight) / 2;
        }
    }

    move(x, y);
}

void Dialog::__initDialog_setTitle() noexcept
{
    setWindowTitle(dialog_title);
}

void Dialog::__initDialog_setIcon() noexcept
{
    QIcon icon(":/icon/res/icon.png");
    setWindowIcon(icon);
}

void Dialog::__initDialog_hideHelpBtn() noexcept
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

void Dialog::__initSelectFolderPart() noexcept
{
    __initSelectFolderPart_createCtrls();
    __initSelectFolderPart_decorateCtrls();
    __initSelectFolderPart_connectCtrlsEvents();
    __initSelectFolderPart_layoutCtrls();
}

void Dialog::__initSelectFolderPart_createCtrls() noexcept
{
    __selectFolderPart_horiLayout_ = new QHBoxLayout();
    __selectFolderPart_selectFolder_ = new SelectFolder();
}

void Dialog::__initSelectFolderPart_decorateCtrls() noexcept
{
    __selectFolderPart_selectFolder_->setMinimumHeight(100);
    __selectFolderPart_selectFolder_->setMaximumHeight(100);
}

void Dialog::__initSelectFolderPart_connectCtrlsEvents() noexcept
{
    connect(__selectFolderPart_selectFolder_->getLoadBtnCtrlPointer(),
            &QPushButton::clicked,
            [this]()
    {
        __initItemSetPart();
    });
}

void Dialog::__initSelectFolderPart_layoutCtrls() noexcept
{
    __selectFolderPart_horiLayout_->addWidget(__selectFolderPart_selectFolder_);
}

void Dialog::__initItemSetPart(const bool& initDialog) noexcept
{
    if (initDialog)
    {
        __initItemSetPart_createCtrls();
    }
    else
    {
        __initItemSetPart_decorateCtrls();
        __initItemSetPart_layoutCtrls();
        __initDialog_setFixedSize();
    }
}

void Dialog::__initItemSetPart_createCtrls() noexcept
{
    __itemSetPart_horiLayout_ = new QHBoxLayout();
}

void Dialog::__initItemSetPart_decorateCtrls() noexcept
{
    {
        QList<Item*> allItems = findChildren<Item*>();

        foreach (Item* item, allItems)
        {
            item->setParent(nullptr);
            delete item;
        }

        itemCompSetting_titleTextSet.resize(0);
        __itemSetPart_itemSet_.resize(0);
    }

    QVector<QString> list = getAllChildDirNames();

    for (int index = 0; index < list.count(); ++index)
    {
        if (index >= item_itemsNumberLimit) break;

        QString title = list[index];
        itemCompSetting_titleTextSet.push_back(title);
        __itemSetPart_itemSet_.push_back(new Item(index));
    }
}

void Dialog::__initItemSetPart_layoutCtrls() noexcept
{
    for (int index = 0; index < __itemSetPart_itemSet_.count(); ++index)
    {
        __itemSetPart_horiLayout_->addWidget(__itemSetPart_itemSet_[index]);
    }
}

void Dialog::__dialogLayout() noexcept
{
    __dialog_vertLayout_ = new QVBoxLayout();

    __dialog_vertLayout_->addLayout(__selectFolderPart_horiLayout_);
    __dialog_vertLayout_->addLayout(__itemSetPart_horiLayout_);

    this->setLayout(__dialog_vertLayout_);
}
