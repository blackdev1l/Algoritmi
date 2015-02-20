#!/usr/bin/python

class Node(object):
    """docstring for Node"""
    def __init__(self):
        data = None
        next = None

    def __str__(self):
        return str(self.data)

class LinkedList(object):
    """docstring for LinkedList"""
    def __init__(self):
        self.currentNode = None
        self.head = None

    def add(self,data):
        tmp = Node()
        tmp.data = data
        tmp.next = None
        if(self.currentNode is None):
            self.head = tmp
            self.currentNode = tmp
        else:
            self.currentNode.next = tmp
            self.currentNode = tmp

    def __str__(self):
        return str(self.currentNode.data)

    def printList(self):
        node = self.head
        while node:
            print(node)
            node = node.next



if __name__ == "__main__":
    x = LinkedList()
    x.add(2)
    x.add(3)
    x.printList()

