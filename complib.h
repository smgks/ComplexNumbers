#ifndef COMPLIB_H
#define COMPLIB_H
#include <QObject>
#include <QtMath>
#include <QTextStream>

class PolarComplex;

class Complex{
    Q_PROPERTY(qreal re MEMBER m_re READ re WRITE setRe)
    Q_PROPERTY(qreal im MEMBER m_im READ im WRITE setIm)
public:
    explicit Complex(qreal r = 0, qreal i = 0);
    Complex(PolarComplex polar);
    Complex(const Complex& num);
    Complex operator+(const Complex &r);
    Complex operator-(const Complex &r);
    Complex operator*(const Complex &r);
    Complex operator/(const Complex &r);
    Complex operator=(const Complex &r);
    bool operator==(const Complex &r) const;
    bool operator==(const PolarComplex &r) const;
    qreal abs() const;
    qreal arg() const;
    qreal re() const;
    void setRe(qreal re);
    qreal im() const;
    void setIm(qreal imq);
    friend QTextStream &operator <<(QTextStream &s, const Complex &num);
protected:
    qreal m_re;
    qreal m_im;
};

class PolarComplex{
public:
    explicit PolarComplex(qreal r = 0, qreal i = 0);
    PolarComplex(Complex complex);
    PolarComplex(const PolarComplex& num);
    PolarComplex operator+(const PolarComplex &r);
    PolarComplex operator-(const PolarComplex &r);
    PolarComplex operator*(const PolarComplex &r);
    PolarComplex operator/(const PolarComplex &r);
    PolarComplex operator=(const PolarComplex &r);
    bool operator==(const PolarComplex &r) const;
    bool operator==(const Complex &r) const;
    qreal abs() const;
    qreal arg() const;
    qreal r() const;
    void setR(qreal r);
    qreal fi() const;
    void setFi(qreal fi);
    friend QTextStream &operator <<(QTextStream &s, const PolarComplex &num);
protected:
    qreal m_r;
    qreal m_fi;
};

#endif // COMPLIB_H
