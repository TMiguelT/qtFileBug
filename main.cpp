#include <iostream>
#include <QFile>
#include <QDir>
#include <QUrl>
#include <QDesktopServices>

using namespace std;

int main() {

    //Create a QFile without a parent, open it and close it, then delete it.
    //Windows refuses to open the file because the file handle hasn't been freed
    QFile *orphan = new QFile(QDir::temp().path() + "/withoutParent.txt");
    orphan->open(QIODevice::WriteOnly);
    orphan->write("Written something");
    orphan->close();
    delete orphan;
    QDesktopServices::openUrl(QUrl(orphan->fileName()));

    getchar();

    //Create a QFile with a parent, open it and close it, then delete it.
    //Windows opens the file because the file handle was in the parent, which has been deleted
    QObject *parent = new QFile;
    QFile *child = new QFile(QDir::temp().path() + "/withParent.txt", parent);
    child->open(QIODevice::WriteOnly);
    orphan->write("Written something else");
    child->close();
    delete parent;
    QDesktopServices::openUrl(QUrl(orphan->fileName()));

    getchar();
}