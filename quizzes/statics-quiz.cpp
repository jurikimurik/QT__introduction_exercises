class Wadget {
public:
    Wadget(double a, double b);
    void print();
    static double calculation();
    static int wadgetCount();

private:
    double m_d1, m_d2;
    static int m_wadgetCount;
};

Wadget::Wadget(double a, double b) : m_d1(a), m_d2(b) {
    m_wadgetCount++;
}

int Wadget::wadgetCount() {
    return m_wadgetCount;
}

double Wadget::calculation() {
    return m_wadgetCount;
}

int Wadget::m_wadgetCount = 0;
