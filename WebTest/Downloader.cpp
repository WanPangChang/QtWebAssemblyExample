#include "Downloader.h"
#include <QUrl>
#include <QDateTime>
#include <QDebug>

Downloader::Downloader(QObject *parent):
    QObject(parent)
{
    
}

Downloader::~Downloader()
{
    
}

const QString &Downloader::getData()
{
    return m_data;
}

void Downloader::doDownload(const QString& url)
{
    if (!m_manager)
    {
        m_manager = new QNetworkAccessManager(this);

        connect(m_manager, SIGNAL(finished(QNetworkReply*)),
                this, SLOT(replyFinished(QNetworkReply*)));
    }

    m_manager->get(QNetworkRequest(url));
}
    
void Downloader::replyFinished(QNetworkReply *reply)
{
    if (reply->error())
    {
        qDebug() << "[ERROR] " << __FUNCTION__;
        qDebug() << reply->errorString();
    }
    else
    {
        qDebug() << reply->header(QNetworkRequest::ContentTypeHeader).toString();
        qDebug() << reply->header(QNetworkRequest::LastModifiedHeader).toDateTime().toString();
        qDebug() << reply->header(QNetworkRequest::ContentLengthHeader).toULongLong();
        qDebug() << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug() << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
        
        m_data = reply->readAll();
        qDebug() << "DataSize:" << m_data.size();
        emit receData();
    }
    
    reply->deleteLater();
}
