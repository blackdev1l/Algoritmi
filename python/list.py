#!/usr/bin/python

from random import shuffle
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
            #print(node)
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

    def quicksort(self,nums=None):
        newList = DoubleLinkedList()
        nums = self.printList()

        result = self.sort(nums)
        for n in result:
            newList.add(n)
        return newList

    def sort(self,nums):
        less = []
        equal = []
        greater = []
        if(len(nums) > 1):
            pivot = nums[0]
            for n in nums:
                if(n < pivot):
                    less.append(n)
                if( n is pivot):
                    equal.append(n)
                if(n > pivot):
                    greater.append(n)
            return(self.sort(less)+equal+self.sort(greater))
        else:
            return nums
