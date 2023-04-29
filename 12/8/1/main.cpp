#include <QApplication>
#include <QTextStream>
#include <QMetaObject>
#include <QMetaProperty>
#include <QMetaMethod>
#include <QVariant>
#include <QSpinBox>
#include <QProcess>
#include <QTimer>



QTextStream cout(stdout);

void printObject(const QObject* obj) {
    const QMetaObject* meta = obj->metaObject();
    cout << QString("class %1 : public %2")
                .arg(meta->className())
                .arg(meta->superClass()->className()) << Qt::flush;
    for(int i = 0; i < meta->propertyCount(); ++i) {
        const QMetaProperty qmp = meta->property(i);
        QVariant value = obj->property(qmp.name());
        if(value.toString().size() != 0) {
            cout << QString(" %1 %2 = %3")
                        .arg(qmp.typeName())
                        .arg(qmp.name())
                        .arg(value.toString())
                 << Qt::endl << Qt::flush;
        }
        cout << Qt::endl
             << Qt::flush;
    }

    for(int i = 0; i < meta->methodCount(); ++i)
    {
        const QMetaMethod qmm = meta->method(i);
        cout << QString("%1 %2(")
                    .arg(qmm.returnMetaType().name())
                    .arg(qmm.name());
        for(const QByteArray& elem : qmm.parameterTypes())
        {
            cout << QString(elem) << ", ";
        }
        cout << ")" << Qt::endl;
    }

    cout << Qt::flush;
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QSpinBox* spin = new QSpinBox();
    QProcess* process = new QProcess();
    QTimer* timer = new QTimer();

    printObject(spin);
    printObject(process);
    printObject(timer);
}
