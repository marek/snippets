
/**
 * In a single test source file add this to link to an auto-generated
 * main()
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestTarget
#include <boost/test/unit_test.hpp>

// ---------------------------------------------------------------------------

/**
 * Unit test files follow this format.
 */
#include <boost/test/unit_test.hpp>


/**
 * If needed override protected/private methods in a local class
 */
class TestClass : public marek::RealClass
{
  public:
    TestClass() : RealClass("") {

    }
    void func(int foo) {
      RealClass::func(foo);
    }
};

BOOST_AUTO_TEST_SUITE( real_class_suite )

/*
Test func()
 */
BOOST_AUTO_TEST_CASE( test_func)
{
    TestClass tc = TestClass();
    tc.func();

    BOOST_TEST(...);
    BOOST_TEST(...);
    BOOST_TEST(...);
}


BOOST_AUTO_TEST_SUITE_END()
