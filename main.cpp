#include "data.h"
#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

#include <functional>

void iterateOverEnumValues(const std::function<void(TempClass::VisionModuleType, const char *)> &lambda)
{
    QMetaEnum metaEnum = QMetaEnum::fromType<TempClass::VisionModuleType>();
    for(int i = 0; i < metaEnum.keyCount(); ++i)
    {
        TempClass::VisionModuleType value = static_cast<TempClass::VisionModuleType>(metaEnum.value(i));
        const char *name = metaEnum.key(i);
        lambda(value, name);
    }
}

int main(int argc, char *argv[])

{
    QApplication a(argc, argv);
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    qRegisterMetaType<TempClass::VisionModuleType>();

    MainWindow w;

    w.show();
    iterateOverEnumValues([](TempClass::VisionModuleType value, const char *name) { qDebug() << "Enum value:" << name << " = " << static_cast<int>(value); });

    return a.exec();
}
