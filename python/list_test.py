#!/usr/bin/python

import unittest
import list


class TestList(unittest.TestCase):

    def setUp(self):
        self.list = list.DoubleLinkedList()
        self.list.add(2)
        self.list.add(3)
        self.list.add(4)
        self.list.add(1)
        self.list.add(6)
        self.list.add(5)
    def test_add(self):
        self.assertEqual(self.list.currentNode.data,5)
    def test_print(self):
        nodes = [2,3,4,1,6,5]
        self.assertEqual(self.list.printList(),nodes)
    def test_head(self):
        self.assertEqual(self.list.head.data,2)
    def test_back(self):
        self.assertEqual(self.list.currentNode.back.data,6)
    def test_deleteHead(self):
        self.assertTrue(self.list.deleteNode(2))
        self.assertEqual(self.list.head.data,3)
    def test_delete(self):
        self.assertTrue(self.list.deleteNode(3))
        self.assertEqual(self.list.head.next.data,4)
    def test_deleteTail(self):
        self.assertTrue(self.list.deleteNode(5))
        self.assertEqual(self.list.currentNode.data,6)
    def test_deleteNotFound(self):
        self.assertFalse(self.list.deleteNode(19))
    def test_quicksort(self):
        sorted = [1,2,3,4,5,6]
        new = self.list.quicksort()
        self.assertEqual(new.printList(),sorted)


if __name__ == '__main__':
    suite = unittest.TestLoader().loadTestsFromTestCase(TestList)
    unittest.TextTestRunner(verbosity=2).run(suite)



