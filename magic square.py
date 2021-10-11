# -*- coding: utf-8 -*-
"""
Created on Tue Jun  8 19:58:06 2021
magic square
@author: Madhusudan Joshi
"""
def magicsquare(n):
    ms=[]
    for i in range(n):
        l=[]
        for j in range(n):
           l.append(0) 
        ms.append(l) 
        
  
    i=int(n/2)
    j=int(n-1)
    num=n*n
    count=1
    while(count<=num):
        if(i==-1 and j==n):
            j=n-2
            i=0
        else:
            if(j==n):
                j=0
            if(i<0):
                i=n-1
        if(ms[i][j]!=0):
            j=j-2
            i=i+1
            continue
        else:
            ms[i][j]=count
            count=count+1
        i=i-1
        j=j+1
     
    for i in range(n): 
        for j in range(n):
            print(ms[i][j],end=" ")
        print(" ")
        
n=int(input("Enter the size supported for magic square: "))
magicsquare(n)
print("magic number= ",int((n*(n**2+1)/2)))
