class Hashing :
    def __init__(self):
        self.size=int(input("Enter the size of hash table : "))
        self.hashTable=[]
        self.count=0
        for i in range (self.size):
            self.hashTable.append("None")

    def display(self):
        print(self.hashTable) 

    def hashFun1(self, a):
        return a%self.size

    def isFull(self):
        if(self.count>=self.size):
            return True
        else:
            return False

    def isEmpty(self):
        if(self.count==0):
            return True
        return False
    
    def linearHashing(self):
        if(self.isFull()):
            print("Hash table is already full!!")
            return
        
        k= int(input("Enter the element to be added in hash table using Linear Hashing : "))

        pos= self.hashFun1(k)
        while(self.hashTable[pos]!="None"):
            print("Collision occur for %d at index %d "%(k,pos))
            pos=(pos+1)%self.size
        self.hashTable[pos]=k
        self.count+=1

    def linearSearch(self , k):
        pos = self.hashFun1(k)
        i=0
        while(i<self.size):
            if(self.hashTable[pos]!=k):
                pos=(pos+1)%self.size
            else:
                print("Element is present at index : ", pos)
                return pos
            i=i+1
        
        print("Element is not present in table !!")
        return -1

    def linearDelete(self):
        if(self.isEmpty()):
            print("Table is already empty !!")
            return
        k= int(input("Enter the element to be delete : "))

        # pos = self.hashFun1(k)
        # i=0
        # while(i<self.size):
        #     if(self.hashTable[pos]!=k):
        #         pos=(pos+1)%self.size
        #     else:
        #         self.hashTable[pos]="None"
        #         self.count-=1
        #         print("Element is present at index : ",pos)
        #         print("Element Deleted Successfully")
        #         return pos
        #     i=i+1
        # print("Element is not present !!")

        n=self.linearSearch(k)
        if(n!=-1):
            self.hashTable[n]="None"  
            self.count-=1  
            print("Element Deleted Successfully")


a = Hashing()

a.linearHashing()
a.linearHashing() 
a.linearHashing()
print(a.isFull())
a.display()
a.linearHashing()
a.display()
k= int(input("Enter the element to be search : "))
a.linearSearch(k)

a.linearDelete()
a.display()
