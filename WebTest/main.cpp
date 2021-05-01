#include <functional>
#include <boost/version.hpp>
#include <QtGlobal>
#include <QApplication>
#include <QFileSystemModel>
#include <QDir>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QTextStream>
#include <QPushButton>
#include <QDebug>
#include <QFileDialog>
#include <QTableView>
//#include <QSqlTableModel>
#include <QTabWidget>
#include "Downloader.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    
    auto mainWidget = new QWidget(nullptr);
    auto gridLayout = new QGridLayout(nullptr);
    mainWidget->setLayout(gridLayout);
    auto tabWidget = new QTabWidget(mainWidget);
    gridLayout->addWidget(tabWidget);
    
    auto pathSelected = new QLineEdit(mainWidget);
    
    auto contentSelected = new QTextEdit(mainWidget);
    contentSelected->setLineWrapMode(QTextEdit::NoWrap);
    
    auto selectPath = new QPushButton("Select Path", mainWidget);
    auto loadContent = new QPushButton("Load Content", mainWidget);
    auto saveContent = new QPushButton("Save Content", mainWidget);
    
    std::vector<QTextEdit*> textContents =
    {
        nullptr,
        nullptr,
    };
    
    for (auto&& textContent : textContents)
    {
        textContent = new QTextEdit(mainWidget);
        textContent->setLineWrapMode(QTextEdit::NoWrap);
    }

#if 0
    auto db = QSqlDatabase::addDatabase("QODBC3");
    auto connectString = QStringLiteral(R"(DRIVER=SQL Server; SERVER=localhost\SQLEXPRESS; DATABASE=SampleDatabase; Trusted_Connection=yes)");
    db.setDatabaseName(connectString);
    auto sqlTableModel = new SqlTableModel(mainWidget, db);
    auto tableView = new QTableView(mainWidget);
    tableView->setModel(sqlTableModel);

    {
        sqlTableModel->setEditStrategy(QSqlTableModel::OnFieldChange);
        sqlTableModel->database().open();
        sqlTableModel->setTable("SampleTable");
        sqlTableModel->select();
    }
#endif

    {
        std::vector<QString> addresses =
        {
            "https://wanpangchang.github.io/QtWebAssemblyExample/WebTest/Demo.csv",
            "https://dbhub.io/kcimg528/test.db",
        };
        
        for (size_t i = 0; i < textContents.size(); ++i)
        {
            auto&& address = addresses[i];
            auto&& textContent = textContents[i];
            auto downloader = new Downloader(mainWidget);
            downloader->doDownload(address);
            auto receData = [=]()
            {
                textContent->setText(downloader->getData());
            };
            QObject::connect(downloader, &Downloader::receData, receData);
        }
    }
    
    {
        std::vector<QString> kTitles = {"Path", "Downloader", "SQL"};
        std::vector<int> kNumOfCols = {2, 1, 1};
        std::vector<std::vector<QWidget*>> itemTable =
        {
            {
                selectPath,
                pathSelected,
                loadContent,
                saveContent,
                contentSelected,
            },
            {
                textContents[0],
                textContents[1],
            },
            {
#if 0
                tableView,
#else
                nullptr,
#endif
            },
        };
    
        for (size_t idx = 0; idx < kNumOfCols.size(); ++idx)
        {
            auto&& items = itemTable[idx];
            auto&& kNumOfCol = kNumOfCols[idx];
            auto&& kTitle = kTitles[idx];
            
            auto widgetLocal = new QWidget(mainWidget);
            auto layoutLocal = new QGridLayout();
            widgetLocal->setLayout(layoutLocal);
            tabWidget->addTab(widgetLocal, kTitle);
            
            int i = 0;
            for (auto&& item : items)
            {
                int r = i/kNumOfCol;
                int c = i%kNumOfCol;
                if (item)
                    layoutLocal->addWidget(item, r, c);
                ++i;
            }
        }
    }
    mainWidget->show();
    
    auto getOpenFileContentImpl = [=] (const QString &fileName, const QByteArray &fileContent)
    {
        pathSelected->setText(fileName);
        contentSelected->setText(fileContent);
    };
    
    auto onSelectPathClicked = [=]()
    {
        QFileDialog::getOpenFileContent("CSV (*.csv)", getOpenFileContentImpl);
    };
    
    auto onLoadContentClicked = [=]()
    {
        getOpenFileContentImpl("BOOST_VERSION.txt", QString::number(BOOST_VERSION).toLatin1());
    };
    
    auto onSaveContentClicked = [=]()
    {
#if QT_VERSION >= QT_VERSION_CHECK(5, 14, 0)
        QFileDialog::saveFileContent(contentSelected->toPlainText().toLatin1(), pathSelected->text());
#endif
    };

    QObject::connect(selectPath, &QPushButton::clicked, std::bind(onSelectPathClicked));
    QObject::connect(loadContent, &QPushButton::clicked, std::bind(onLoadContentClicked));
    QObject::connect(saveContent, &QPushButton::clicked, std::bind(onSaveContentClicked));
    
    return a.exec();
}
