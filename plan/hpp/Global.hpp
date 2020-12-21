
#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <QVector>

class QSize;
class QString;

extern QSize dialogFixedSize;
extern QString dialogTitle;

extern QString dialog_selectFolderPart_labelText;
extern QString dialog_selectFolderPart_selectBtnText;
extern QString dialog_selectFolderPart_loadBtnText;

// [begin] ItemCompSetting

extern int itemCompSetting_defaultNumber;
extern QString itemCompSetting_curNumberText;
extern QString itemCompSetting_loadBtnText;
extern QVector<QString> itemCompSetting_titleTextSet;

// [end] ItemCompSetting

QString readLastSavedResourcePath() noexcept;
void writeSelectedResourcePath(const QString& path) noexcept;

#endif // GLOBAL_HPP
