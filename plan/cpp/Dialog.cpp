
#include "../hpp/Dialog.hpp"
#include "../hpp/Global.hpp"
#include "../hpp/Item.hpp"
#include <QIcon>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>

Dialog::Dialog(QWidget *parent) noexcept
    : QDialog(parent)
{
    __initDialog();
    __initSelectFolderPart();
    __initItemSetPart();
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
    __initSelectFolderPart_connectCtrlsEvents();
    __initSelectFolderPart_layoutCtrls();
}

void Dialog::__initSelectFolderPart_createCtrls() noexcept
{
    __selectFolderPart_horiLayout_ = new QHBoxLayout();
    __selectFolderPart_labelCtrl_ = new QLabel();
    __selectFolderPart_showPathCtrl_ = new QTextEdit();
    __selectFolderPart_vertLayout_ = new QVBoxLayout();
    __selectFolderPart_selectBtnCtrl_ = new QPushButton();
    __selectFolderPart_loadBtnCtrl_ = new QPushButton();
}

void Dialog::__initSelectFolderPart_decorateCtrls() noexcept
{
    __selectFolderPart_labelCtrl_->setText(dialog_selectFolderPart_labelText);
    __selectFolderPart_showPathCtrl_->setText(readLastSavedResourcePath());
    __selectFolderPart_selectBtnCtrl_->setText(dialog_selectFolderPart_selectBtnText);
    __selectFolderPart_loadBtnCtrl_->setText(dialog_selectFolderPart_loadBtnText);
}

void Dialog::__initSelectFolderPart_connectCtrlsEvents() noexcept
{
    connect(__selectFolderPart_selectBtnCtrl_, &QPushButton::clicked, [this]()
    {
        QFileDialog::Options options =
                QFileDialog::ShowDirsOnly           |
                QFileDialog::DontResolveSymlinks    |
                QFileDialog::HideNameFilterDetails  |
                QFileDialog::DontUseSheet           |
                QFileDialog::ReadOnly;
        QString path = QFileDialog::getExistingDirectory(this, QObject::tr("选择目录"), QString(), options);

        if (!path.isEmpty())
        {
            __selectFolderPart_showPathCtrl_->setText(path);
            writeSelectedResourcePath(path);
        }
    });
}

void Dialog::__initSelectFolderPart_layoutCtrls() noexcept
{
    __selectFolderPart_horiLayout_->addWidget(__selectFolderPart_labelCtrl_);
    __selectFolderPart_horiLayout_->addWidget(__selectFolderPart_showPathCtrl_);

    __selectFolderPart_vertLayout_->addWidget(__selectFolderPart_selectBtnCtrl_);
    __selectFolderPart_vertLayout_->addWidget(__selectFolderPart_loadBtnCtrl_);

    __selectFolderPart_horiLayout_->addLayout(__selectFolderPart_vertLayout_);
}

void Dialog::__initItemSetPart() noexcept
{
    __initItemSetPart_createCtrls();
    __initItemSetPart_decorateCtrls();
    __initItemSetPart_layoutCtrls();
}

void Dialog::__initItemSetPart_createCtrls() noexcept
{
    __ItemSetPart_horiLayout_ = new QHBoxLayout();
}

void Dialog::__initItemSetPart_decorateCtrls() noexcept
{
    for (int index = 0; index < 4; ++index)
    {
        QString title = "test " + QString::number(index);
        itemCompSetting_titleTextSet.push_back(title);
        __ItemSetPart_ItemSet_.push_back(new Item(index));
    }
}

void Dialog::__initItemSetPart_layoutCtrls() noexcept
{
    for (int index = 0; index < __ItemSetPart_ItemSet_.count(); ++index)
    {
        __ItemSetPart_horiLayout_->addWidget(__ItemSetPart_ItemSet_[index]);
    }
}

void Dialog::__dialogLayout() noexcept
{
    __dialog_vertLayout_ = new QVBoxLayout();

    __dialog_vertLayout_->addLayout(__selectFolderPart_horiLayout_);
    __dialog_vertLayout_->addLayout(__ItemSetPart_horiLayout_);

    this->setLayout(__dialog_vertLayout_);
}
