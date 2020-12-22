
#include "../hpp/Global.hpp"
#include <QSize>
#include <QString>
#include <QFile>
#include <QDir>
#include <QHash>
#include <QDateTime>

//-------------------------------------------------------------
// Dialog

QSize dialog_fixedSize = { 1024, 560 };
QString dialog_title = QObject::tr("计划清单");

QVector<QString> getAllChildDirNames() noexcept
{
    QVector<QString> childDirNames;

    if (selectFolder_curPath.isEmpty())
    {
        return childDirNames;
    }

    QDir dir(selectFolder_curPath);

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

QVector<QString> getAllChildFileNames(const QString& path) noexcept
{
    QVector<QString> childFileNames;

    if (path.isEmpty())
    {
        return childFileNames;
    }

    QDir dir(path);

    if (dir.exists())
    {
        dir.setFilter(QDir::Files);
        QFileInfoList list = dir.entryInfoList();

        foreach (QFileInfo fileInfo, list)
        {
            if (fileInfo.isFile())
            {
                QString name = fileInfo.fileName();
                childFileNames.push_back(name);
            }
        }
    }

    return childFileNames;
}

QVector<QString> selectFilesAlgorithm(const QVector<QString>& files,
                                      const int& number) noexcept
{
    QVector<QString> selectFiles;

    if (files.count() == 0 || number == 0)
    {
        return selectFiles;
    }

    QVector<uint> hashValueSet;
    hashValueSet.resize(number);

    for (int i = 0; i < hashValueSet.count(); ++i)
    {
        if (i == 0)
        {
            QString dateTime = QDateTime::currentDateTime().toString("yyyy.MM.dd MMMM dddd");
            hashValueSet[i] = qHash(dateTime);
        }
        else
        {
            hashValueSet[i] = qHash(~(hashValueSet[i - 1]) | (hashValueSet[i - 1] >> 1));
        }
    }

    QHash<uint, void*> sameIndex;

    for (int i = 0; i < hashValueSet.count(); ++i)
    {
        hashValueSet[i] = hashValueSet[i] % files.count();

        if (sameIndex.find(hashValueSet[i]) == sameIndex.end())
        {
            sameIndex.insert(hashValueSet[i], nullptr);
        }
    }

    for (auto constIter = sameIndex.constBegin(); constIter != sameIndex.constEnd(); ++constIter)
    {
        selectFiles.push_back(files[constIter.key()]);
    }

    return selectFiles;
}

//-------------------------------------------------------------
// SelectFolder

QString selectFolder_curPath;

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

        if (!byteArray.isEmpty())
        {
            path = byteArray;
        }

        file.close();
    }

    selectFolder_curPath = path;

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
