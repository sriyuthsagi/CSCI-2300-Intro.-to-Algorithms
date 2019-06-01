import json
import random
import copy
datafile = open("lab5.dat", "r")
G = json.load(datafile)
datafile.close()

def pagerank1(G, d, t):
    
    A = 0
    Q = []
    for i in range(len(G)):
        Q.append(0)
    
    for t in range(T):
        P = random.randint(1,1001)/1000
        NEXT = 0;
        if (P < d):
            count = 0
            lst = []
            for i in G[A]:
                
                if (i == 1):
                    lst.append(count)
                count = count + 1
            
            NEXT = random.randint(1, len(lst)) - 1
        else:
            NEXT = random.randint(1, len(G[A])) - 1
        
        A = NEXT
        Q[A] = Q[A] + 1
    return Q
        


def pagerank2(G, d, t):
    
    Q = []
    
    for i in range(len(G)):
        Q.append(1/len(G))
    
    lst = []
    for i in range(len(G)):
        count = 0
        lstmini = []
        for j in G:
            
            if (j[i] == 1):
                lstmini.append(count)
            count = count + 1
        lst.append(lstmini)
    #print(lst)
    
    lst1 = []
    for i in range(len(G)):
        count = 0
        lstmini = []
        for j in G[i]:
            
            if (j == 1):
                lstmini.append(count)
            count = count + 1
        lst1.append(lstmini)
    #print(lst1)    
    
    for t in range(T):
        
        Qalt = copy.deepcopy(Q)
        
        for i in range(len(Q)):
            
            Q[i] = (1-d)/len(G)
            
            for j in range(len(lst[i])):
                Q[i] = Q[i] + (d * (Qalt[lst[i][j]] / len(lst1[j])))
    
    return Q







d = 0.9
T = 100000

result1 = pagerank1(G, d, T)
print(result1)

print()
print()
print()
print()
print()

result2 = pagerank2(G, d, T)
print(result2)


"""
count = 0
            lst1 = []
            for i in G[i]:
                
                if (i == 1):
                    lst1.append(count)
                count = count + 1            
            
            Q[i] = (1-d)/len(G)
            
            for j in range(len(G)):
                Q[i] = Q[i] + (d * (Qalt[j])/len(lst1))
"""