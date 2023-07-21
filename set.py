class Set:
    def __init__(self):
        self.list=[]
    
    def setData(self):
        n=int(input("Enter the number of element in set : "))
        for i in range(n):
            k=int(input("Enter the element of set : "))
            self.list.append(k)
    
    def getData(self):
        for i in self.list:
            print(i ,end=" ")
        print('')

    def setUnion (self ,b):
        union=[]
        for i in self.list:
            union.append(i)

        for i in b.list:
            if i not in union:
                union.append(i)
        return union
    
    def setIntersection (self,b):
        intersection=[]
        for i in self.list:
            if i in b.list:
                intersection.append(i)
        
        return intersection
    
    def Remove(self):
        n=int(input("Enter element to be remove :"))
        for i in self.list:
            if n==i:
                self.list.remove(n)
                print("Element found and deleted")
                return
        print("Element not in list")


    def contain(self):
        n=int(input("Enter the element to be search"))
        for i in self.list:
            if n==i:
                print("Element Found ")
                return 
        print("Element Not Found")

    def symm_diff(self, b):
        symm=[]
        for i in self.list:
            if i not in b.list:
                symm.append(i)
        return symm    
    
    def Size(self):
        i = 0
        for k in self.list:
            i=i+1
        return i

    
a=Set()
b = Set()

a.setData()
a.getData()

b.setData()
b.getData()

a.Remove()
a.getData()

b.contain()
b.getData()

unionA=[]
unionA=a.setUnion(b)
print(unionA)

intersectionA=[]
intersectionA=a.setIntersection(b)
print(intersectionA)


symmA=[]
symmA=a.symm_diff(b)
print(symmA)

size = a.Size()
print(size)