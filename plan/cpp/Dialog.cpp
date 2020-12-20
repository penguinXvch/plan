
#include "../hpp/Dialog.hpp"
#include "../hpp/Global.hpp"
#include <QIcon>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>

Dialog::Dialog(QWidget *parent) noexcept
    : QDialog(parent)
{
    __initDialog();
    __initSelectFolderPart();
    __dialogLayout();
}

Dialog::~Dialog() noexcept
{
}

void Dialog::__initDialog() noexcept
{
    __initDialog_setFixedSize();
    __initDialog_setTitle();
    __initDialog_setIcon();
    __initDialog_hideHelpBtn();
}

void Dialog::__initDialog_setFixedSize() noexcept
{
    setMinimumSize(dialogFixedSize.width(), dialogFixedSize.height());
    setMaximumSize(dialogFixedSize.width(), dialogFixedSize.height());
}

void Dialog::__initDialog_setTitle() noexcept
{
    setWindowTitle(dialogTitle);
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
    __initSelectFolderPart_layoutCtrls();
}

void Dialog::__initSelectFolderPart_createCtrls() noexcept
{
    __selectFolderPart_horiLayout_ = new QHBoxLayout();
    __selectFolderPart_labelCtrl_ = new QLabel();
    __selectFolderPart_showPathCtrl_ = new QTextEdit();
    __selectFolderPart_btnCtrl_ = new QPushButton();
}

void Dialog::__initSelectFolderPart_decorateCtrls() noexcept
{
    __selectFolderPart_labelCtrl_->setText(dialog_selectFolderPart_labelText);
    __selectFolderPart_showPathCtrl_->setText(getLastSavedResourcePath());
    __selectFolderPart_btnCtrl_->setText(dialog_selectFolderPart_btnText);
}

void Dialog::__initSelectFolderPart_layoutCtrls() noexcept
{
    __selectFolderPart_horiLayout_->addWidget(__selectFolderPart_labelCtrl_);
    __selectFolderPart_horiLayout_->addWidget(__selectFolderPart_showPathCtrl_);
    __selectFolderPart_horiLayout_->addWidget(__selectFolderPart_btnCtrl_);
}

void Dialog::__dialogLayout() noexcept
{
    this->setLayout(__selectFolderPart_horiLayout_);
}
