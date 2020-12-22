
#include "../hpp/SelectFolder.hpp"
#include "../hpp/Global.hpp"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QFileDialog>

SelectFolder::SelectFolder(QWidget* parent) noexcept
    : QWidget(parent)
{
    __init();
}

SelectFolder::~SelectFolder() noexcept
{
}

QPushButton* SelectFolder::getLoadBtnCtrlPointer() noexcept
{
    return __loadBtnCtrl_;
}

void SelectFolder::__init() noexcept
{
    __init_createCtrls();
    __init_decorateCtrls();
    __init_connectCtrlsEvents();
    __init_layoutCtrls();
}

void SelectFolder::__init_createCtrls() noexcept
{
    __horiLayout_ = new QHBoxLayout();
    __labelCtrl_ = new QLabel();
    __showPathCtrl_ = new QTextEdit();
    __vertLayout_ = new QVBoxLayout();
    __selectBtnCtrl_ = new QPushButton();
    __loadBtnCtrl_ = new QPushButton();
}

void SelectFolder::__init_decorateCtrls() noexcept
{
    __labelCtrl_->setText(selectFolder_labelText);
    __showPathCtrl_->setReadOnly(true);
    __showPathCtrl_->setText(readLastSavedResourcePath());
    __selectBtnCtrl_->setText(selectFolder_selectBtnText);
    __loadBtnCtrl_->setText(selectFolder_loadBtnText);
}

void SelectFolder::__init_connectCtrlsEvents() noexcept
{
    connect(__selectBtnCtrl_, &QPushButton::clicked, [this]()
    {
        QFileDialog::Options options =
                QFileDialog::ShowDirsOnly           |
                QFileDialog::DontResolveSymlinks    |
                QFileDialog::HideNameFilterDetails  |
                QFileDialog::DontUseSheet           |
                QFileDialog::ReadOnly;

        QString path = QFileDialog::getExistingDirectory(this,
            selectFolder_getExistingDir_titleText, QString(), options);

        if (!path.isEmpty())
        {
            __showPathCtrl_->setText(path);
            selectFolder_curPath = path;
        }
    });

    connect(__loadBtnCtrl_, &QPushButton::clicked, []()
    {
        if (!selectFolder_curPath.isEmpty())
        {
            writeSelectedResourcePath(selectFolder_curPath);
        }
    });
}

void SelectFolder::__init_layoutCtrls() noexcept
{
    __horiLayout_->addWidget(__labelCtrl_);
    __horiLayout_->addWidget(__showPathCtrl_);

    __vertLayout_->addWidget(__selectBtnCtrl_);
    __vertLayout_->addWidget(__loadBtnCtrl_);

    __horiLayout_->addLayout(__vertLayout_);

    this->setLayout(__horiLayout_);
}
