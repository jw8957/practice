# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        left_head = left_tail = right_head = right_tail = None
        
        p = head
        while p is not None:
            if p.val >= x:
                if right_tail is None:
                    right_head = right_tail = p
                else:
                    right_tail.next = p
                    right_tail = p
            else:
                if left_tail is None:
                    left_tail = left_head = p
                else:
                    left_tail.next = p
                    left_tail = p
            p = p.next
            
        if right_tail is not None:
            right_tail.next = None

        if left_tail is not None:
            left_tail.next = right_head
        else:
            left_head = right_head
        
        return left_head


def InitializeLinkedList(list):
    head = ListNode(-1)
    p = head
    for item in list:
        # print(item)
        newNode = ListNode(item)
        p.next = newNode
        p = p.next
    
    return head.next

def PrintLinkedList(lList):
    p = lList
    while p is not None:
        print(p.val)
        p = p.next

if __name__ == '__main__':
    print ("main")
    lList = InitializeLinkedList([1,4,3,2,5,2])
    x = 3

    # PrintLinkedList(lList)

    solver = Solution()
    res = solver.partition(lList, x)

    PrintLinkedList(res)