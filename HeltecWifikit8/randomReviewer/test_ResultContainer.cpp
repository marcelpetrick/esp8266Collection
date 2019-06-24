// own includes
#include <ResultContainer.h>

// Qt includes
#include <QtTest/QtTest>

class test_ResultContainer: public QObject
{
    Q_OBJECT

private slots:
    void toUpper();
};

void test_ResultContainer::toUpper()
{
    // just fake
    QString str = "Hello";
    QCOMPARE(str.toUpper(), QString("HELLO"));
}

QTEST_MAIN(test_ResultContainer)
#include "test_ResultContainer.moc"
