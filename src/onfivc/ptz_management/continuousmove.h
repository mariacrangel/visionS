#ifndef CONTINUOUSMOVE_H
#define CONTINUOUSMOVE_H
#include <QObject>
#include <QtXml/QDomElement>
namespace ONVIF {
    class ContinuousMove : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QString profileToken READ profileToken WRITE setProfileToken)
        Q_PROPERTY(float panTiltX READ panTiltX WRITE setPanTiltX)
        Q_PROPERTY(float panTiltY READ panTiltY WRITE setPanTiltY)
        Q_PROPERTY(QString panTiltSpace READ panTiltSpace WRITE setPanTiltSpace)
        Q_PROPERTY(float zoomX READ zoomX WRITE setZoomX)
        Q_PROPERTY(QString zoomSpace READ zoomSpace WRITE setZoomSpace)
        Q_PROPERTY(QString timeout READ timeout WRITE setTimeout)
        Q_PROPERTY(bool result READ result WRITE setResult)

    public:
        explicit ContinuousMove(QObject *parent = NULL);
        virtual ~ContinuousMove();

        QDomElement toxml();
        QString profileToken() const
        {
            return m_profileToken;
        }

        float panTiltX() const
        {
            return m_panTiltX;
        }

        float panTiltY() const
        {
            return m_panTiltY;
        }

        QString panTiltSpace() const
        {
            return m_panTiltSpace;
        }

        float zoomX() const
        {
            return m_zoomX;
        }

        QString zoomSpace() const
        {
            return m_zoomSpace;
        }

        bool result() const
        {
            return m_result;
        }

        QString timeout() const
        {
            return m_timeout;
        }

    public slots:
        void setProfileToken(QString arg)
        {
            m_profileToken = arg;
        }

        void setPanTiltX(float arg)
        {
            m_panTiltX = arg;
        }

        void setPanTiltY(float arg)
        {
            m_panTiltY = arg;
        }

        void setPanTiltSpace(QString arg)
        {
            m_panTiltSpace = arg;
        }

        void setZoomX(float arg)
        {
            m_zoomX = arg;
        }

        void setZoomSpace(QString arg)
        {
            m_zoomSpace = arg;
        }

        void setResult(bool arg)
        {
            m_result = arg;
        }

        void setTimeout(QString arg)
        {
            m_timeout = arg;
        }

    private:
        QString m_profileToken;
        float m_panTiltX;
        float m_panTiltY;
        QString m_panTiltSpace;
        float m_zoomX;
        QString m_zoomSpace;
        bool m_result;
        QString m_timeout;
    };
}
#endif // CONTINUOUSMOVE_H
