
#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <QDialog>

class QHBoxLayout;
class QLabel;
class QTextEdit;
class QVBoxLayout;
class QPushButton;
class Item;

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
    QVBoxLayout* __selectFolderPart_vertLayout_ = nullptr;
    QPushButton* __selectFolderPart_selectBtnCtrl_ = nullptr;
    QPushButton* __selectFolderPart_loadBtnCtrl_ = nullptr;

private:
    void __initSelectFolderPart() noexcept;
    void __initSelectFolderPart_createCtrls() noexcept;
    void __initSelectFolderPart_decorateCtrls() noexcept;
    void __initSelectFolderPart_connectCtrlsEvents() noexcept;
    void __initSelectFolderPart_layoutCtrls() noexcept;

private:
    QHBoxLayout* __ItemSetPart_horiLayout_ = nullptr;
    QVector<Item*> __ItemSetPart_ItemSet_;

private:
    void __initItemSetPart() noexcept;
    void __initItemSetPart_createCtrls() noexcept;
    void __initItemSetPart_decorateCtrls() noexcept;
    void __initItemSetPart_layoutCtrls() noexcept;

private:
    QVBoxLayout* __dialog_vertLayout_ = nullptr;

private:
    void __dialogLayout() noexcept;
};

#endif // DIALOG_HPP
