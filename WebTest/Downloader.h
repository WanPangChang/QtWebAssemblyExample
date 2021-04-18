#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class Downloader : public QObject
{
    Q_OBJECT
public:
    explicit Downloader(QObject *parent);
    virtual ~Downloader();
    
    const QString& getData();
    
    void doDownload();

signals:
    void receData();
    
public slots:
    void replyFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager* m_manager = {};
    QString m_data = {};
};

#endif // DOWNLOADER_H
