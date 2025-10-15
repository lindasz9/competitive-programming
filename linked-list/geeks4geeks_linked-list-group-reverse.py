"""Node is defined as

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
"""

class Solution:
    def reverseKGroup(self, head, k):
        prev = None          # Previous node during traversal
        curr = head          # Current node during traversal
        first = head         # The first node of the current k-group
        second = None        # The start of the next k-group
        kk = 0               # Counter for nodes reversed in current group
        newhead = None       # Head of the new reversed list

        while True:
            # When k nodes are reversed or reached end of list
            if kk == k or not curr:
                # Mark the start of the next group only once
                if kk == k and not second:
                    second = curr
                # Connect the end of the previous group to the reversed current group
                elif newhead:
                    first.next = prev
                    first = second
                    second = curr
                # Set new head after reversing first group
                if not newhead:
                    newhead = prev
                prev = None
                kk = 0

            # End of list reached, return new head
            if not curr:
                return newhead

            # Reverse current node pointer
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
            kk += 1

"""
I was so happy when submitting this solution, 
because it was correct at first try! 
And this was considered a hard exercise.
And I didn't look at the solution at all! 
When writing the code and running custom made test inputs, 
I realized that I've made some mistakes, 
but I corrected all of them before submitting it, 
so I found and corrected all of the mistakes. 
I'm proud of myself.
"""
