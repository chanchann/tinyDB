class Circle_queue(object):
    def __init__(self,length):
        self.length = length
        self.elems = [None] * length
        self.head = 0
        self.rear = 0
    def __str__(self):
        if self.isEmpty():
            return "This is a empty Queue"
        else:
            list = ''
            for i in self.elems[:]:
                if i is not None:
                    list += str(i) + ' '
            return list
    def isEmpty(self):
        return (self.head == self.rear and self.elems[self.head] is None)
    def isFull(self):
        return (self.head == self.rear and self.elems is not None)
    def initQueue(self,data):
        if len(data) > self.length:
            print('The data is too many!')
            return
        else:
            for i,m in enumerate(data):
                self.elems[i] = m
            self.rear = len(data)
    def enqueue(self,data):
        if self.isFull():
            return
        else:
            self.rear = (self.rear + 1) % self.length
            self.elems[self.rear] = data
    def dequeue(self):
        if self.isEmpty():
            return
        else:
            self.elems[self.head] = None
            self.head = (self.head + 1) % self.length