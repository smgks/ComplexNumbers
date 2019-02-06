#include "complib.h"

Complex::Complex(qreal r, qreal i)
{
    m_re = r;
    m_im = i;
}

Complex::Complex(PolarComplex polar)
{
    m_re = polar.r() * qCos(polar.fi());
    m_im = polar.r() * qSin(polar.fi());
 }

Complex::Complex(const Complex &num)
{
    m_re = num.re();
    m_im = num.im();
}

Complex Complex::operator+(const Complex &r)
{
    return Complex(m_re + r.re(), m_im + r.im());
}

Complex Complex::operator-(const Complex &r)
{
    return Complex(m_re - r.re(), m_im - r.im());
}

Complex Complex::operator*(const Complex &r)
{
    return Complex(m_re * r.re(), m_im * r.re());
}

Complex Complex::operator/(const Complex &r)
{
    qreal temp = r.re() * r.re() + r.im() * r.im();
    return Complex((m_re * r.re() + m_im * r.im()) / temp,
                   (m_im * r.re() - m_re * r.im()) / temp);
}

Complex Complex::operator=(const Complex &r)
{
    m_re = r.re();
    m_im = r.im();
    return *this;
}

bool Complex::operator==(const Complex &r) const
{
    return (qAbs<qreal>(m_re - r.re() < .000001) && (qAbs<qreal>(m_im - r.im()) < .000001));
}

bool Complex::operator==(const PolarComplex &r) const
{
    return (*this == Complex(r));
}

qreal Complex::abs() const
{
    return qSqrt((m_re * m_re) + (m_im * m_im));
}

qreal Complex::arg() const
{
    return qAtan2(m_im, m_re);
}

qreal Complex::re() const
{
    return m_re;
}

void Complex::setRe(qreal re)
{
    m_re = re;
}

qreal Complex::im() const
{
    return m_im;
}

void Complex::setIm(qreal im)
{
    m_im = im;
}

/* Polar */

PolarComplex::PolarComplex(qreal r, qreal i)
{
    m_r = r;
    m_fi = i;
}

PolarComplex::PolarComplex(Complex complex)
{
    m_r = complex.abs();
    m_fi = complex.arg();
}

PolarComplex::PolarComplex(const PolarComplex &num)
{
    m_r = num.r();
    m_fi = num.fi();
}

PolarComplex PolarComplex::operator+(const PolarComplex &r)
{
    return PolarComplex(Complex(*this) + Complex(r));
}

PolarComplex PolarComplex::operator-(const PolarComplex &r)
{
    return PolarComplex(Complex(*this) - Complex(r));
}

PolarComplex PolarComplex::operator*(const PolarComplex &r)
{
    return PolarComplex(Complex(*this) * Complex(r));
}

PolarComplex PolarComplex::operator/(const PolarComplex &r)
{
    return PolarComplex(Complex(*this) / Complex(r));
}

PolarComplex PolarComplex::operator=(const PolarComplex &r)
{
    m_r = r.r();
    m_fi = r.fi();
    return *this;
}

bool PolarComplex::operator==(const PolarComplex &r) const
{
    return (Complex(*this) == Complex(r));
}

bool PolarComplex::operator==(const Complex &r) const
{
    return (Complex(*this) == r);
}

qreal PolarComplex::abs() const
{
    return qSqrt(m_r * m_r + m_fi * m_fi);
}

qreal PolarComplex::arg() const
{
    return m_fi;
}

qreal PolarComplex::r() const
{
    return m_r;
}

void PolarComplex::setR(qreal r)
{
    m_r = r;
}

qreal PolarComplex::fi() const
{
    return m_fi;
}

void PolarComplex::setFi(qreal fi)
{
    m_fi = fi;
}
QTextStream &operator <<(QTextStream &s, const Complex &num)
{
    return s << num.re() << ((num.im() >= 0) ? " + " : " - ") << num.im() << "j";
}
QTextStream &operator <<(QTextStream &s, const PolarComplex &num)
{
    return s << num.r() << ((num.fi() >= 0) ? " + " : " - ") << num.fi() << "j";
}
