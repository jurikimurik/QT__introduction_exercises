#include <QDateTime>
#include "randomstring.h"

#include <chrono>

RandomString::RandomString(int len)
    :m_stringLength(len), m_randomString(QString()),
    m_Dre(std::chrono::system_clock::now().time_since_epoch().count()) {
}

void RandomString::setStringLength(int len) {
    m_stringLength = len;
}

int RandomString::getStringLenght() {
    return m_stringLength;
}

QString RandomString::generateString() {
    return generateString(m_stringLength);
}

QString RandomString::generateString(int len) {
    const int CHARSETSIZE(26);
    const char FIRSTCHAR('a');
    m_randomString = "";
    for(int i = 0; i < len; i++){
        std::uniform_int_distribution id((int)FIRSTCHAR, (int)FIRSTCHAR+CHARSETSIZE);
        QChar randChar = (char) id(m_Dre);
        m_randomString.append(randChar);
    }
    return m_randomString;
}

bool RandomString::isMatch(QString responseStr) {
    return (responseStr.compare(m_randomString)==0) ;
}

int RandomString::numCorrectChars(QString responseStr) {
    int numCorrect = 0;
    int totalNum = responseStr.size();
    if(totalNum >= m_randomString.size())
        totalNum = m_randomString.size();
    for(int i=0; i< totalNum;i++){
        if(responseStr.at(i)== m_randomString.at(i))
            numCorrect++;
    }
    return numCorrect;
}
