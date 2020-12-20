
#include "../hpp/Global.hpp"
#include <QSize>
#include <QString>
#include <QObject>
#include <QFile>
#include <QDir>

QSize dialogFixedSize = { 820, 560 };
QString dialogTitle = QObject::tr("计划清单");

QString dialog_selectFolderPart_labelText = QObject::tr("资源路径");
QString dialog_selectFolderPart_btnText = QObject::tr("选择");

QString getLastSavedResourcePath() noexcept
{
    QString path;

    QString __file = "/info/resource-path.txt";
    QString __path = QDir::currentPath();
    __file = __path.append(__file);

    QFile file(__file);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QByteArray byteArray = file.readLine();

        if (!byteArray.isNull())
        {
            path = byteArray;
        }

        file.close();
    }

    return path;
}
