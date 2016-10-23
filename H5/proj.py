class BinaryTree(object):
    def __init__(self,left,right,value):
        self.right=right
        self.left=left
        self.value=value
        self.leftnum=0

    def BuildTree(self):
        s=raw_input()
        a,b=s.split(' ')
        a=int(a)
        b=int(b)
        if (a==-1 and b==-1):
            return 0
        else:
            if(not a==-1):
                self.left=BinaryTree(None,None,a)
                self.left.BuildTree()
            if(not b==-1):
                self.right=BinaryTree(None,None,b)
                self.right.BuildTree()

def CalNum(tree):
    if tree==None:
        return 0
    return 1+CalNum(tree.left)+CalNum(tree.right)


def printTree(tree):
    if(tree==None):
        return
    printTree(tree.left)
    print tree.value
    printTree(tree.right)

def FillTree(tree,a):
    if(tree==None):
        return 0
    tree.value=a[tree.leftnum]
    a.remove(a[tree.leftnum])
    FillTree(tree.left,a)
    FillTree(tree.right,a)

def PrintLevelTree(tree,b):
    TreeL=[]
    TreeL.append(tree)
    while(not len(TreeL)==0):
        t=TreeL[0]
        b.append(t.value)
        if(not t.left==None):
            TreeL.append(t.left)
        if(not t.right==None):
            TreeL.append(t.right)
        TreeL.remove(TreeL[0])

def Calleft(tree):
    if tree==None:
        return 0
    tree.leftnum=CalNum(tree.left)
    Calleft(tree.left)
    Calleft(tree.right)


n=raw_input()
root=BinaryTree(None,None,0)
root.BuildTree()
p=root

Calleft(root)

s=raw_input()
a=s.split(' ')
a=[int(x) for x in a]
a.sort()

FillTree(root,a)
b=[]
PrintLevelTree(root,b)
for i in range(len(b)-1):
    print b[i],
print b[len(b)-1]