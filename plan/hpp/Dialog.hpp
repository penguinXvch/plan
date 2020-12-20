
#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <QDialog>

class QHBoxLayout;
class QLabel;
class QTextEdit;
class QPushButton;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr) noexcept;
    ~Dialog() noexcept;

private:
    void __initDialog() noexcept;
    void __initDialog_setFixedSize() noexcept;
    void __initDialog_setTitle() noexcept;
    void __initDialog_setIcon() noexcept;
    void __initDialog_hideHelpBtn() noexcept;

private:
    QHBoxLayout* __selectFolderPart_horiLayout_ = nullptr;
    QLabel* __selectFolderPart_labelCtrl_ = nullptr;
    QTextEdit* __selectFolderPart_showPathCtrl_ = nullptr;
    QPushButton* __selectFolderPart_btnCtrl_ = nullptr;

private:
    void __initSelectFolderPart() noexcept;
    void __initSelectFolderPart_createCtrls() noexcept;
    void __initSelectFolderPart_decorateCtrls() noexcept;
    void __initSelectFolderPart_layoutCtrls() noexcept;

private:
    void __dialogLayout() noexcept;
};

#endif // DIALOG_HPP
