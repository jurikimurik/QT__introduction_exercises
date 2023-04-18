#include "xmltreemodel.h"
#include <QDebug>
#include <QStandardItem>
#include <QFile>

XmlTreeModel::XmlTreeModel(QObject *parent) :
    QStandardItemModel(parent),
    m_currentItem(0) {
}

//start
void XmlTreeModel::open(QString fileName) {
    QFile file (fileName);                           /* Zostanie zamknięty automatycznie po wyjściu z zakresu. */
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Nie mogę otworzyć pliku: " << fileName;
        abort();
    }
    m_streamReader.setDevice(&file);                 /* Rozpoczęcie parsowania — można użyć dowolnego QIODevice. */
    while (!m_streamReader.atEnd()) {
        QXmlStreamReader::TokenType tt = m_streamReader.readNext();
        switch (tt) {
            case QXmlStreamReader::StartElement: {
                QString name = m_streamReader.name().toString();
                QStandardItem* item = new QStandardItem(name);
                item->setData(m_streamReader.lineNumber(), 
                              LineStartRole);       /* Dane (data()) zdefiniowane przez programistę. */
                QXmlStreamAttributes attrs = m_streamReader.attributes();
                QStringList sl;
                sl << tr("Line# %1").arg(m_streamReader.lineNumber());
                foreach (QXmlStreamAttribute attr, attrs) {
                    QString line = QString("%1='%2'").arg(attr.name().toString())
                                    .arg(attr.value().toString());
                    sl.append(line);
                }
                item->setToolTip(sl.join("\n"));
                if (m_currentItem == 0) 
                   setItem(0, 0, item);                 /* Ustanowienie korzenia modelu. */
                else 
                   m_currentItem->appendRow(item);      /* Dodanie dziecka do aktualnego elementu. */
                m_currentItem = item;
                break; }
            case QXmlStreamReader::Characters: {
                QString tt = m_currentItem->toolTip();
                tt.append("\n");
                tt.append(m_streamReader.text().toString());
                m_currentItem->setToolTip(tt);
                break; }
            case QXmlStreamReader::EndElement: 
                m_currentItem->setData(m_streamReader.lineNumber(), LineEndRole);
                m_currentItem = m_currentItem->parent();      /* Przejście w górę drzewa. */
                break;
            case QXmlStreamReader::EndDocument:
            default:
                break;
        }
    }
}
