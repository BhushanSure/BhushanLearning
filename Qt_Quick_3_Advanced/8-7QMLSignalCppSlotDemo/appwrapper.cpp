#include <QDebug>
#include "appwrapper.h"

AppWrapper::AppWrapper(QObject *parent) : QObject(parent)
{

}

bool AppWrapper::initialize()
{
    mEngine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (mEngine.rootObjects().isEmpty())
        return false;

    QObject * rootObject = mEngine.rootObjects()[0];
    connect(rootObject,SIGNAL(qmlSignal(QString,QVariant)),
            this,SLOT(respondToClick(QString,QVariant)));

    return true;
}

void AppWrapper::respondToClick(QString msg, const QVariant &object)
{
    qDebug() << "The message is : " << msg;

    QObject * mObject = object.value<QObject*>();

    qDebug() << "The property is : " << mObject->property("mProp").toString();


}
