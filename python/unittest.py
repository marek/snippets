
import unittest


"""MyTestClass
"""
class MyTestClass(unittest.TestCase):
  CONFIG = { 'foo': 123 }

  @classmethod
  def setUpClass(cls):
    # setup static settings
    pass

  def setUp(self):
    # do before each test
    pass

  def tearDown(self):
    pass

  def test_something(self):
    # add test here


if __name__ == '__main__':
    unittest.main()
