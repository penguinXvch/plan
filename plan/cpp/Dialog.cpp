
#include "../hpp/Dialog.hpp"
#include "../hpp/Global.hpp"
#include <QIcon>

Dialog::Dialog(QWidget *parent) noexcept
    : QDialog(parent)
{
    __initDialog();
}

Dialog::~Dialog()
{
}

void Dialog::__initDialog() noexcept
{
    __setDialogFixedSize();
    setWindowTitle(dialogTitle);
    __setDialogIcon();
    __hideDialogHelpBtn();
}

void Dialog::__setDialogFixedSize() noexcept
{
    setMinimumSize(dialogFixedSize.width(), dialogFixedSize.height());
    setMaximumSize(dialogFixedSize.width(), dialogFixedSize.height());
}

void Dialog::__setDialogIcon() noexcept
{
    QIcon icon(":/icon/res/icon.png");
    setWindowIcon(icon);
}

void Dialog::__hideDialogHelpBtn() noexcept
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}
