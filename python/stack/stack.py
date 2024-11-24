class Node:
    def __init__(self, value, next):
        self.value = value
        self.next = next

class MyStack:

    def __init__(self):
        self.last = None
    
    def print_all_depth(self):
        current = self.last  # 스택의 마지막 노드부터 시작
        while current is not None:
            print(current.value)
            current = current.next  # 다음 노드로 이동

    def next(self):
        if self.last is not None:
            return self.last.next
        else:
            return None

    def push(self, value: int):
        if self.last is None:
            self.last = Node(value, None)
        else:
            self.last = Node(value, self.last)

    def pop(self):
        if self.last is None:
            return None  # 스택이 비어 있는 경우
        value = self.last.value  # 현재 마지막 노드의 값을 저장
        self.last = self.last.next  # 마지막 노드를 이전 노드로 변경
        return value


if __name__ == '__main__':
    st = MyStack()
    st.push(5)
    st.push(4)
    st.print_all_depth()
