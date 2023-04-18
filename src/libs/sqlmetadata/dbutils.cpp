#include "dbutils.h"

// TODO: Sprawdź, czy inne znaki też należy poprzedzić znakiem ucieczki!

QString DbUtils::escape(QString str) {
    return str.replace("\"", "\\\"");
}

