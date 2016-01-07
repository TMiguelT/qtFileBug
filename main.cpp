#include <iostream>
#include <QFile>
#include <QDir>
#include <QUrl>
#include <QDesktopServices>
#include <QDebug>

using namespace std;

int main() {

    //Create a QFile without a parent, open it and close it, then delete it.
    //Windows refuses to open the file because the file handle hasn't been freed
    QString fileName = QDir::tempPath() + "/withoutParent.txt";
    qDebug() << fileName;
    QFile *orphan = new QFile(fileName);
    orphan->open(QIODevice::WriteOnly);
    orphan->write("Written something");
    orphan->close();
    delete orphan;
    bool result = QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
    qDebug() << "Succeeded? " << result;
    qDebug() << QUrl::fromLocalFile(fileName);

    getchar();

    //Create a QFile with a parent, open it and close it, then delete it.
    //Windows opens the file because the file handle was in the parent, which has been deleted
    fileName = QDir::tempPath() + "/withParent.txt";
    qDebug() << fileName;

    QObject *parent = new QFile;
    QFile *child = new QFile(fileName, parent);
    child->open(QIODevice::WriteOnly);
    child->write("Written something else");
    child->close();
    delete parent;
    QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
    qDebug() << "Succeeded? " << result;
    qDebug() << QUrl::fromLocalFile(fileName);

    getchar();
}