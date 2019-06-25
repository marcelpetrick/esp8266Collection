// own includes
#include <ResultContainer.h>

// Qt includes
#include <QtTest/QtTest>

class test_ResultContainer: public QObject
{
    Q_OBJECT

private slots:

    // initial test - if inserting works at all
    void testContruction();

    // test if the stringifying works properly
    void testGetResult();

    // test to verify if valid HTML is produced
    void testHTML();
};

// ------------------------------------------------------------------------

void test_ResultContainer::testContruction()
{
    ResultContainer klaus(10);
    auto const resultString = klaus.getHtml();

    // TODO
    QCOMPARE(resultString, std::string("not implemented")); // the suffix 1 makes it fail - good! :)
}

void test_ResultContainer::testGetResult()
{
    ResultContainer klaus(3);
    auto const resultString = klaus.getResultString();

    QCOMPARE(resultString, std::string(""));

    klaus.insert("MPE");
    QCOMPARE(klaus.getResultString(), std::string("MPE"));

    klaus.insert("AAA");
    QCOMPARE(klaus.getResultString(), std::string("MPE;AAA"));

    klaus.insert("BBB");
    QCOMPARE(klaus.getResultString(), std::string("MPE;AAA;BBB"));

    // first item should be discarded
    klaus.insert("CCC");
//    auto const debug = klaus.getResultString();
    QCOMPARE(klaus.getResultString(), std::string("AAA;BBB;CCC"));

    // first item should be discarded
    klaus.insert("DDD");
    QCOMPARE(klaus.getResultString(), std::string("BBB;CCC;DDD"));
}

void test_ResultContainer::testHTML()
{
    ResultContainer klaus(3);
    klaus.insert("MPE");
    klaus.insert("AAA");
    klaus.insert("BBB");
    klaus.insert("CCC");

    auto const html = klaus.getHtml();
    // TODO construct something
    std::string expectedHtml;
    QCOMPARE(html, expectedHtml);
}

// ------------------------------------------------------------------------

QTEST_GUILESS_MAIN(test_ResultContainer)
#include "test_ResultContainer.moc"
