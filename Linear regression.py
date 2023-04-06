import csv
import numpy as np
import matplotlib.pyplot as plt
import math
import time
import copy



def compute_model_output(x,w,b):

    f_wb= np.dot(w.T,x) + b

    return f_wb

def derivative_cost(f_wb , x_train , y_train):

    m= x_train.shape[1]

    dj_dw= 1/m * np.sum(np.dot((f_wb-y_train), x_train.T), axis=1)
    dj_db= 1/m * np.sum(f_wb-y_train)

    return dj_db,dj_dw

def gradient_descent(w,b,dj_dw, dj_db, alpha):

    w = copy.deepcopy(w)
    b = copy.deepcopy(b)

    w = w - alpha*dj_dw
    b = b - alpha*dj_db

    return w,b

def linear_regression_model(x_train, y_train, w_init, b_init, alpha, no_of_iterations):

    w= w_init
    b= b_init
    l_f_wb= []

    for i in range(no_of_iterations):
        m= x_train.shape[0]
        for j in range(m):
        
            f_wb= compute_model_output(x_train[j],w,b)
            dj_dw,dj_db= derivative_cost(f_wb , x_train , y_train)
            w,b= gradient_descent(w, b, dj_dw[j], dj_db[j], alpha)
            print(f"loop{i}", dj_dw[j])
            l_f_wb.append(f_wb)
            # print(l_f_wb.shape)

    return l_f_wb

x_train= []
y_train= []
with open('kc_house_data.csv', 'r') as file:
    reader= csv.reader(file)
    for row in reader:
        x_train.append([row[1][:8]] +row[3:])
        y_train.append(row[2])
                    # print(i[j])

x_train = x_train[1:]
y_train = y_train[1:]
print(y_train[:5])
print(x_train[:5])

# # clearing the dataset 
# x_train= np.array(x_train[1: ])
# y_train = np.array(y_train[1:])
# # print(x_train[:5])

# # print(x_train)
# x_train = x_train.T
# # x_train = np.array(x_train, dtype= float)
# x_train = x_train.astype('float64')

# # print("AAAAAAAAAAAAA")
# # print(x_train[:5])

# # y_train= np.array(y_train[1 : ], dtype=float)
# y_train = y_train.astype('float64')
# # print(y_train[:5])

# # intialzing parameters
# w_init= np.ones((x_train.shape[0] , 1), dtype=float) 
# b_init= np.zeros((1, x_train.shape[1]), dtype=float)

# # print(w_init.shape, b_init.shape)

# alpha = 0.001

# l_f_wb = linear_regression_model(x_train, y_train, w_init, b_init, alpha, 100)

# print(l_f_wb) 

