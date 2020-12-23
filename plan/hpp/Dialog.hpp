
#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <QDialog>

class QHBoxLayout;
class QVBoxLayout;
class SelectFolder;
class Item;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget* parent = nullptr) noexcept;
    ~Dialog() noexcept;

private:
    void __initDialog() noexcept;
    void __initDialog_setFixedSize(const bool& initDialog = false) noexcept;
    void __initDialog_setTitle() noexcept;
    void __initDialog_setIcon() noexcept;
    void __initDialog_hideHelpBtn() noexcept;

private:
    QHBoxLayout* __selectFolderPart_horiLayout_ = nullptr;
    SelectFolder* __selectFolderPart_selectFolder_ = nullptr;

private:
    void __initSelectFolderPart() noexcept;
    void __initSelectFolderPart_createCtrls() noexcept;
    void __initSelectFolderPart_decorateCtrls() noexcept;
    void __initSelectFolderPart_connectCtrlsEvents() noexcept;
    void __initSelectFolderPart_layoutCtrls() noexcept;

private:
    QHBoxLayout* __itemSetPart_horiLayout_ = nullptr;
    QVector<Item*> __itemSetPart_itemSet_;

private:
    void __initItemSetPart(const bool& initDialog = false) noexcept;
    void __initItemSetPart_createCtrls() noexcept;
    void __initItemSetPart_decorateCtrls() noexcept;
    void __initItemSetPart_layoutCtrls() noexcept;

private:
    QVBoxLayout* __dialog_vertLayout_ = nullptr;

private:
    void __dialogLayout() noexcept;
};

#endif // DIALOG_HPP
