
#ifndef ITEMCOMPSETTING_HPP
#define ITEMCOMPSETTING_HPP

#include <QWidget>

class QHBoxLayout;
class QLabel;
class QLineEdit;
class QVBoxLayout;
class QPushButton;

class ItemCompSetting : public QWidget
{
    Q_OBJECT

public:
    explicit ItemCompSetting(int index, QWidget* parent = nullptr) noexcept;
    ~ItemCompSetting() noexcept;

public:
    QPushButton* getLoadBtnCtrlPointer() noexcept;
    QPushButton* getFinishBtnCtrlPointer() noexcept;
    int getLineEditCtrlDisplayNumber() noexcept;

public:
    void setFinish() noexcept;

private:
    QVBoxLayout* __vertLayout_ = nullptr;
    QHBoxLayout* __labelEdit_horiLayout_ = nullptr;
    QHBoxLayout* __addMinusBtns_horiLayout_ = nullptr;
    QHBoxLayout* __loadFinishBtns_horiLayout_ = nullptr;
    QLabel* __title_labelCtrl_ = nullptr;
    QLabel* __curNumber_labelCtrl_ = nullptr;
    QLineEdit* __curNumber_lineEditCtrl_ = nullptr;
    QPushButton* __addOne_btnCtrl_ = nullptr;
    QPushButton* __minusOne_btnCtrl_ = nullptr;
    QPushButton* __load_btnCtrl_ = nullptr;
    QPushButton* __finish_btnCtrl_ = nullptr;

private:
    void __init() noexcept;
    void __init_createCtrls() noexcept;
    void __init_decorateCtrls() noexcept;
    void __init_connectCtrlsEvents() noexcept;
    void __init_layoutCtrls() noexcept;
    void __init_beautifyCtrls() noexcept;

private:
    int __index_ = -1;
};

#endif // ITEMCOMPSETTING_HPP
