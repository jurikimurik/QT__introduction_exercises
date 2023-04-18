#include <QtCore>
#include <dynoprops.h>
//start id=inventory
QString DynoProps::propsInventory() {
   static const QMetaObject* meta = metaObject();
   QStringList res;
   res << "Stałe właściwości:";
   QString propData;
   for(int i = 0; i < meta->propertyCount(); ++i) {
      res << QString("%1\t%2").arg(QString(meta->property(i).name()))
              .arg(meta->property(i).read(this).toString());         /* Równie dobrze moglibyśmy użyć w tym miejscu property(propName). */
   }
   res << "Dynamiczne właściwości:";  

   foreach(QByteArray dpname, dynamicPropertyNames()) {
      res << QString("%1\t%2").arg(QString(dpname))
              .arg(property(dpname).toString());
   }
   return res.join("\n");
}
 
//end
//start id=serial
/** To uproszczony przykład, w którym zakładamy, że klasa 
 nie dziedziczy z innej klasy z właściwościami.
 Gdyby tak było, na początku pętli skorzystalibyśmy 
 z QMetaObject::propertyOffset() a nie z 0 
 i użylibyśmy operatorów strumieniowych z klasy bazowej. */
 QDataStream& operator<< (QDataStream& os, const DynoProps& dp) {
   static const QMetaObject* meta = dp.metaObject();
   for(int i = 0; i < meta->propertyCount(); ++i) {
        const char* name = meta->property(i).name();
        os << QString::fromLocal8Bit(name)              /* Serializacja char* jako QString. */
           << dp.property(name);
   }
   qint32 N(dp.dynamicPropertyNames().count());         /* Serializacja int. */
   os << N;
   foreach(QByteArray propname, dp.dynamicPropertyNames()) {
      os << QString::fromLocal8Bit(propname) << dp.property(propname);
   }
   return os;
 }
 
 QDataStream& operator>> (QDataStream& is, DynoProps& dp) {
   static const QMetaObject* meta = dp.metaObject();
   QString propname;
   QVariant propqv;
   int propcount(meta->propertyCount());
   for(int i = 0; i < propcount; ++i) {
      is >> propname;
      is >> propqv;
      dp.setProperty(propname.toLocal8Bit(), propqv);   /* Deserializacja (odczyt) char* przy użyciu odwróconej konwersji QString. */
   }
   qint32 dpcount;
   is >> dpcount;
   for(int i = 0; i < dpcount; ++i) {
      is >> propname;
      is >> propqv;
      dp.setProperty(propname.toLocal8Bit(), propqv);
   }
   return is;
 }
//end





