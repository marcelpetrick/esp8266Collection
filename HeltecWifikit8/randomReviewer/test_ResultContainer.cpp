// own includes
#include <ResultContainer.h>

// Qt includes
#include <QtTest/QtTest>

class test_ResultContainer: public QObject
{
    Q_OBJECT

private slots:
    // fake slot - remove later
    void toUpper();

    void testContruction();
};

// ------------------------------------------------------------------------

void test_ResultContainer::toUpper()
{
    // just fake
    QString str = "Hello";
    QCOMPARE(str.toUpper(), QString("HELLO"));
}

void test_ResultContainer::testContruction()
{
    ResultContainer klaus(10);
    auto const resultString = klaus.getHtml();

    QCOMPARE(resultString, std::string("not implemented1")); // the suffix 1 makes it fail - good! :)
}

// ------------------------------------------------------------------------

QTEST_GUILESS_MAIN(test_ResultContainer)
#include "test_ResultContainer.moc"
