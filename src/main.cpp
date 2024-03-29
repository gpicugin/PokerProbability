#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QLocale>
#include <QTranslator>

#include "AppEngine.h"
#include "HandsModel.h"
#include "TableModel.h"

int main(int argc, char *argv[])
{
    if (qEnvironmentVariableIsEmpty("QTGLESSTREAM_DISPLAY")) {
        qputenv("QT_QPA_EGLFS_PHYSICAL_WIDTH", QByteArray("213"));
        qputenv("QT_QPA_EGLFS_PHYSICAL_HEIGHT", QByteArray("120"));

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    }
    QGuiApplication app(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "PokerProbability_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    qmlRegisterType<HandsModel>("Hands", 1, 0, "HandsModel");
    qmlRegisterType<TableModel>("Table", 1, 0, "TableModel");


    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/qml/Application.qml"));
    QObject::connect(&engine,
                     &QQmlApplicationEngine::objectCreated,
                     &app,
                     [url](QObject *obj, const QUrl &objUrl)
                    {
                        if (!obj && url == objUrl)
                        QCoreApplication::exit(-1);
                    }, Qt::QueuedConnection);

    AppEngine appEngine;
    engine.rootContext()->setContextProperty("appEngine", &appEngine);

    engine.load(url);

    return app.exec();
}
