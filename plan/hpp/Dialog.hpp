
#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <QDialog>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr) noexcept;
    ~Dialog();

private:
    void __initDialog() noexcept;
    void __setDialogFixedSize() noexcept;
    void __setDialogIcon() noexcept;
    void __hideDialogHelpBtn() noexcept;
};

#endif // DIALOG_HPP
