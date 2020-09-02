
class ListNode : 
    def __init__(self): 
        self.data = None
        self.next = None
  
# A Binary Tree node  
class TreeNode : 
    def __init__(self): 
        self.data = None
        self.left = None
        self.right = None


head_ref = None


def countNodes(head: ListNode) -> int:
    cur = head
    num_nodes = 0
    while cur:
        num_nodes += 1
        cur = cur.next
    return num_nodes


def sortedListToBSTUtil(n: int) -> TreeNode:
    global head_ref

    if n <= 0:
        return None

    left = sortedListToBSTUtil(int(n/2))
    root = newNode(head_ref.data)
    root.left = left
    head_ref = head_ref.next
    root.right = sortedListToBSTUtil(n - int(n/2) - 1)
    return root


def sortedListToBST() -> TreeNode:
    global head_ref
    n = countNodes(head_ref);
    print("\number of nodes: {}".format(n))
    return sortedListToBSTUtil(n)


def push(head, new_data):
    new_node = ListNode()
    new_node.data = new_data
    new_node.next = head
    head = new_node
    return head


def printList(node):
    while node != None:
        print(node.data, end=" ")
        node = node.next


def newNode(data):
    node = TreeNode()
    node.data = data
    node.left = None
    node.right = None
    return node


def preOrder(node):
    if node == None:
        return
    print(node.data, end=" ")
    preOrder(node.left)
    preOrder(node.right)


def inOrder(node):
    if node == None:
        return
    inOrder(node.left)
    print(node.data, end=" ")
    inOrder(node.right)


head_ref = None
head_ref = push(head_ref, 9)
head_ref = push(head_ref, 5)
head_ref = push(head_ref, 0)
head_ref = push(head_ref, -3)
head_ref = push(head_ref, -10)

printList(head_ref)
root = sortedListToBST()
print("\nPreOrder traversal of constructed BST ")
preOrder(root)
