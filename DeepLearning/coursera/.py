n = int(input("Enter the number :"))

if n!= 1:
    pass

else :
    print(2, end=" ")
    
    prime_number = False
    for i in range(1, n+1):
        for j in range(2, i-1):
            if i%j == 0:
                prime_number = False
                break

            else : 
                prime_number = True
            
        if prime_number == True:
            print(i,end=" ")

        else : 
            pass
    