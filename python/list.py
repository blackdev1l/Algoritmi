#!/usr/bin/python

class Node(object):
    """docstring for Node"""
    def __init__(self):
        data = None
        next = None
        back = None

    def __str__(self):
        return str(self.data)

class DoubleLinkedList(object):
    """docstring for DoubleLinkedList"""
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
            tmp.back = self.currentNode
            self.currentNode = tmp

    def __str__(self):
        return str(self.currentNode.data)

    def printList(self):
        nodes = []
        node = self.head
        while node:
            nodes.append(node.data)
            node = node.next
        return nodes

    def deleteNode(self,data):
        node = self.head
        while node:
            if(node.data is data):
                tmp = node
                if(node is self.head):
                    node.next.back = None
                    self.head = node.next
                elif(node is self.currentNode):
                    node.back.next = None
                    self.currentNode = node.back
                else:
                    node.back.next = node.next
                    tmp.next.back = node.back
                return True
            node = node.next
        return False


