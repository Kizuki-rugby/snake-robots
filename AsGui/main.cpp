#include "asgui.h"
#include "pagestack.h"
#include <QApplication>
#include <QStackedLayout>
#include <QComboBox>
#include <QStackedWidget>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QObject>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "AsGui_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    PageStack ps;
    return a.exec();
}
