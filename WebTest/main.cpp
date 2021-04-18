#include <QApplication>
#include <QLabel>
#include <QDir>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    QLabel w;
    QDir dir(QDir::currentPath());
    QFileInfoList list = dir.entryInfoList();
    QString text;
    for (auto&& cell : list)
        text += cell.absoluteFilePath() + " ";
    w.setText(text);
    w.show();
    return a.exec();
}