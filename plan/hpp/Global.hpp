
#ifndef GLOBAL_HPP
#define GLOBAL_HPP

class QSize;
class QString;

extern QSize dialogFixedSize;
extern QString dialogTitle;

extern QString dialog_selectFolderPart_labelText;
extern QString dialog_selectFolderPart_selectBtnText;
extern QString dialog_selectFolderPart_loadBtnText;

QString readLastSavedResourcePath() noexcept;
void writeSelectedResourcePath(const QString& path) noexcept;

#endif // GLOBAL_HPP
