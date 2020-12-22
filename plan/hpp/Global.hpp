
#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <QVector>

class QSize;
class QString;

//-------------------------------------------------------------
// Dialog

extern QSize dialog_fixedSize;
extern QString dialog_title;

QVector<QString> getAllChildDirNames() noexcept;
QVector<QString> getAllChildFileNames(const QString& path) noexcept;

QVector<QString> selectFilesAlgorithm(const QVector<QString>& files,
                                      const int& number) noexcept;

//-------------------------------------------------------------
// SelectFolder

extern QString selectFolder_curPath;

extern QString selectFolder_labelText;
extern QString selectFolder_selectBtnText;
extern QString selectFolder_loadBtnText;
extern QString selectFolder_getExistingDir_titleText;

QString readLastSavedResourcePath() noexcept;
void writeSelectedResourcePath(const QString& path) noexcept;

//-------------------------------------------------------------
// ItemCompSetting

extern int itemCompSetting_defaultNumber;
extern QString itemCompSetting_curNumberText;
extern QString itemCompSetting_loadBtnText;
extern QVector<QString> itemCompSetting_titleTextSet;

#endif // GLOBAL_HPP
