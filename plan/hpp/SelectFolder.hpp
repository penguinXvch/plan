
#ifndef SELECTFOLDER_HPP
#define SELECTFOLDER_HPP

#include <QWidget>

class QHBoxLayout;
class QLabel;
class QTextEdit;
class QVBoxLayout;
class QPushButton;

class SelectFolder : public QWidget
{
    Q_OBJECT

public:
    explicit SelectFolder(QWidget* parent = nullptr) noexcept;
    ~SelectFolder() noexcept;

private:
    QHBoxLayout* __horiLayout_ = nullptr;
    QLabel* __labelCtrl_ = nullptr;
    QTextEdit* __showPathCtrl_ = nullptr;
    QVBoxLayout* __vertLayout_ = nullptr;
    QPushButton* __selectBtnCtrl_ = nullptr;
    QPushButton* __loadBtnCtrl_ = nullptr;

private:
    void __init() noexcept;
    void __init_createCtrls() noexcept;
    void __init_decorateCtrls() noexcept;
    void __init_connectCtrlsEvents() noexcept;
    void __init_layoutCtrls() noexcept;

private:
    QString __curPath_;
};

#endif // SELECTFOLDER_HPP
