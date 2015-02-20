#!/usr/bin/python

import unittest
import list


class TestList(unittest.TestCase):

    def setUp(self):
        self.list = list.DoubleLinkedList()
        self.list.add(3)
        self.list.add(4)
    def test_add(self):
        self.assertEqual(self.list.currentNode.data,4)
    def test_print(self):
        nodes = [3,4]
        self.assertEqual(self.list.printList(),nodes)
    def test_head(self):
        self.assertEqual(self.list.head.data,3)
    def test_back(self):
        self.assertEqual(self.list.currentNode.back.data,3)

if __name__ == '__main__':
    suite = unittest.TestLoader().loadTestsFromTestCase(TestList)
    unittest.TextTestRunner(verbosity=2).run(suite)



