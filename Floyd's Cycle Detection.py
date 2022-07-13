class Node:
    def __init__(self, Data):
        self.Data = Data
        self.next = None


class Linked_List:
    def __init__(self):
        self.head = None

    def insert(self, val):
        temp = Node(val)
        temp.next = self.head
        self.head = temp


    def detect_Cycle(self):
        slow_ptr = self.head
        fast_ptr = self.head
        while (fast_ptr and fast_ptr.next):
            slow_ptr = slow_ptr.next
            fast_ptr = fast_ptr.next.next
            if slow_ptr == fast_ptr:
                return True
        return False


List = Linked_List()
values = [20, 30, 40, 50, 60]
n = len(values)
for i in range(n - 1, -1, -1):
    List.insert(values[i])

List.head.next.next.next.next = List.head.next
if List.detect_Cycle():
    print("Cycle found")
else:
    print("No cycle found")


