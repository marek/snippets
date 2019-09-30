from io import StringIO
import unittest

class Node:
  def __init__(self, value):
    self.value = value
    self.next = None

  @staticmethod
  def reverse(root):
    previous = None
    current = root

    while current is not None:
      next = current.next
      current.next = previous
      previous = current
      current = next

    return current

  def __str__(self):
    io = StringIO()

    current = self
    while current is not None:
      io.write("{}->".format(current.value))
      current = current.next
    io.write("None")

    return io.getvalue()
