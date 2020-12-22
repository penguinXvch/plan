
#include "../hpp/Global.hpp"
#include <QSize>
#include <QString>
#include <QFile>
#include <QDir>

//-------------------------------------------------------------
// Dialog

QSize dialog_fixedSize = { 1024, 560 };
QString dialog_title = QObject::tr("计划清单");

QVector<QString> getAllChildDirNames(const QString& path) noexcept
{
    QVector<QString> childDirNames;

    if (path.isEmpty())
    {
        return childDirNames;
    }

    QDir dir(path);

    if (dir.exists())
    {
        dir.setFilter(QDir::AllDirs);
        QFileInfoList list = dir.entryInfoList();

        foreach (QFileInfo fileInfo, list)
        {
            if (fileInfo.isDir())
            {
                QString name = fileInfo.fileName();

                if (name != "." && name != "..")
                {
                    childDirNames.push_back(name);
                }
            }
        }
    }

    return childDirNames;
}

//-------------------------------------------------------------
// SelectFolder

QString selectFolder_labelText = QObject::tr("资源路径");
QString selectFolder_selectBtnText = QObject::tr("选择");
QString selectFolder_loadBtnText = QObject::tr("加载");
QString selectFolder_getExistingDir_titleText = QObject::tr("选择目录");

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

//-------------------------------------------------------------
// ItemCompSetting

int itemCompSetting_defaultNumber = 1;
QString itemCompSetting_curNumberText = QObject::tr("当前数量");
QString itemCompSetting_loadBtnText = QObject::tr("加载");
QVector<QString> itemCompSetting_titleTextSet;
