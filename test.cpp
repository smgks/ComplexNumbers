#include <QtTest/QtTest>
#include <QIODevice>
#include "complib.h"

class TestQString: public QObject
{
    Q_OBJECT
private slots:
    void absargv();
    void construct();
    void operators();
    void output();
    void setGet();
};

void TestQString::absargv()
{
    QCOMPARE(Complex(1).abs(), 1);
    QCOMPARE(Complex(1).arg(), 0);
    QCOMPARE(PolarComplex(1).abs(), 1);
    QCOMPARE(PolarComplex(1).arg(), 0);
    QCOMPARE(PolarComplex(Complex(1)).r(),1);
    QCOMPARE(PolarComplex(Complex(1)).fi(),0);
    QCOMPARE(qSin(.0),0);
    QCOMPARE(Complex(1).im(), Complex(PolarComplex(Complex(1))).im());
    QCOMPARE(Complex(1).re(), Complex(PolarComplex(Complex(1))).re());
}

void TestQString::construct()
{
    QCOMPARE(Complex(),Complex(0,0));
    QCOMPARE(Complex(1),Complex(Complex(1)));
    QCOMPARE(Complex(1),PolarComplex(Complex(1,0)));
    QCOMPARE(PolarComplex(PolarComplex(1)),Complex(PolarComplex(1,0)));
    QCOMPARE(PolarComplex(),PolarComplex(0,0));
    {
        Complex temp(1,1);
        Complex temp1 = temp;
        QCOMPARE(temp1,Complex(1,1));
        temp1 = temp = Complex(2,2);
        QCOMPARE(temp = Complex(2,2), Complex(2,2));
    }
    {
        PolarComplex temp(1,1);
        PolarComplex temp1 = temp;
        QCOMPARE(temp1,PolarComplex(1,1));
        temp1 = temp = PolarComplex(2,2);
        QCOMPARE(temp = PolarComplex(2,2), PolarComplex(2,2));
    }
}

void TestQString::operators()
{
    /*  +  */
    QCOMPARE(Complex(1) + Complex(1),Complex(2));
    QCOMPARE(Complex(1,1) + Complex(1,1),Complex(2,2));
    QCOMPARE(PolarComplex(Complex(1)) + PolarComplex(Complex(1)),Complex(2));
    QCOMPARE(PolarComplex(Complex(1,1)) + PolarComplex(Complex(1,1)),Complex(2,2));
    /*  -  */
    QCOMPARE(Complex(1) - Complex(1),Complex());
    QCOMPARE(Complex(1,1) - Complex(1,1),Complex());
    QCOMPARE(PolarComplex(Complex(1)) - PolarComplex(Complex(1)),Complex(0));
    QCOMPARE(PolarComplex(Complex(1,1)) - PolarComplex(Complex(1,1)),Complex(0));
    /*  *  */
    QCOMPARE(Complex(4) * Complex(2),Complex(8));
    QCOMPARE(Complex(2,3) * Complex(2,2),Complex(4,6));
    QCOMPARE(PolarComplex(Complex(4)) * PolarComplex(Complex(2)),Complex(8));
    QCOMPARE(PolarComplex(Complex(2,3)) * PolarComplex(Complex(2,2)),Complex(4,6));
    /*  /  */
    QCOMPARE(Complex(6) / Complex(5), Complex(1.2));
    {
        Complex temp(Complex(23,1) / Complex(2,1));
        temp.setRe(qRound(temp.re()*100));
        temp.setIm(qRound(temp.im()*100));

        QCOMPARE(temp,Complex(qRound(47/5.0*100),qRound(-21/5.0*100)));
    }
    QCOMPARE(PolarComplex(Complex(6)) / PolarComplex(Complex(5)), Complex(1.2));
    {
        Complex temp(PolarComplex(Complex(23,1)) / PolarComplex(Complex(2,1)));
        temp.setRe(qRound(temp.re()*100));
        temp.setIm(qRound(temp.im()*100));

        QCOMPARE(temp,Complex(qRound(47/5.0*100),qRound(-21/5.0*100)));
    }
}

void TestQString::output()
{
    QTextStream stream(stdout);
    stream << "output complex test " << Complex(1,1) << "\n";
    stream << "output complex test " << PolarComplex(1,1) << "\n";
    QCOMPARE(1,1);
}

void TestQString::setGet()
{
    {
        Complex tempComp;
        tempComp.setIm(1);
        tempComp.setRe(1);
        QCOMPARE(tempComp,Complex(1,1));
    }
    {
        PolarComplex tempPolar;
        tempPolar.setR(1);
        tempPolar.setFi(1);
        QCOMPARE(tempPolar,PolarComplex(1,1));
    }
}


QTEST_MAIN(TestQString)
#include "testqstring.moc"
