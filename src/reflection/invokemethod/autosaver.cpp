void AutoSaver::saveIfNecessary() {
    if (!QMetaObject::invokeMethod(parent(), "save")) {
        qWarning() << "AutoSaver: błąd w trakcie wywyoływania save() u rodzica";
    }
}