
#include "../hpp/Global.hpp"
#include <QSize>
#include <QString>
#include <QFile>
#include <QDir>

QSize dialogFixedSize = { 820, 560 };
QString dialogTitle = QObject::tr("计划清单");

QString dialog_selectFolderPart_labelText = QObject::tr("资源路径");
QString dialog_selectFolderPart_selectBtnText = QObject::tr("选择");
QString dialog_selectFolderPart_loadBtnText = QObject::tr("加载");

// [begin] ItemCompSetting

int itemCompSetting_defaultNumber = 3;
QString itemCompSetting_curNumberText = QObject::tr("当前数量");
QString itemCompSetting_loadBtnText = QObject::tr("加载");
QVector<QString> itemCompSetting_titleTextSet;

// [end] ItemCompSetting

QString readLastSavedResourcePath() noexcept
{
    QString path;

    QString __file = "resource-path.txt";
    QString __path = QDir::currentPath() + QString("/info/");
    __file = __path + __file;

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

void writeSelectedResourcePath(const QString& path) noexcept
{
    QString __file = "resource-path.txt";
    QString __path = QDir::currentPath() + QString("/info/");
    __file = __path + __file;

    QDir dir;

    if (!dir.exists(__path))
    {
        dir.mkpath(__path);
    }

    QFile file(__file);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        file.write(path.toUtf8());
        file.close();
    }
}
