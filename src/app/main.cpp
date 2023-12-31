#include <QApplication>
#include "mainwindow.h"
#include <QHttpServer>
#include <Qdebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QHttpServer httpServer;
    httpServer.route("/", []() {
        return "Hello world";
    });

    const auto port = httpServer.listen(QHostAddress::LocalHost, 8080);
    if (!port) {
        qWarning() << QCoreApplication::translate("QHttpServerExample",
                                                   "Server failed to listen on a port.");
        return -1;
    }

    return app.exec();
} 