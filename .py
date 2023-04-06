import csv
import numpy as np
import matplotlib.pyplot as plt
import copy

# extracting data from the file
def suitable_dataset(path):
    x_train=[]
    y_train=[]
    with open(path, 'r') as file:
        reader = csv.reader(file)
        # print(reader)
        for i in reader:
            n= len(i)
            m=[]
            for j in range(n):
                if j==2:
                    y_train.append(i[j])
                    continue

                elif j == 1:
                    i[j] = i[j][:7]
                    m.append(i[j])

                else:
                    m.append(i[j])
                    # print(i[j])
            x_train.append(m)

    # optimising the dataset suitable for the algorithm 
    x_train= np.array(x_train[1: ])
    x_train = x_train.T
    x_train = np.array(x_train, dtype= float)

    y_train= np.array(y_train[1 : ], dtype=float)
    y_train = y_train.reshape((1, y_train.shape[0]))

    return x_train, y_train

# initializing params
def initializing_params(x):
    """
    x ---> shape : (no of features, no of datasets)
    """
    w_init = np.ones((x.shape[0] , 1), dtype=float)
    # b_init = np.zeros((1, x.shape[1]), dtype=float)
    b_init = 0

    return w_init, b_init

# forward propagation
def compute_model_output(x, w, b):
    """
    x --> shape : (no of features, no of datasets)
    w --> shape : (no of features, 1)
    b --> shape : (no of features, 1)
    f_wb ---> shape : (1, no of datasets)
    """

    f_wb = np.dot(w.T, x) + b
    # print("f", f_wb.shape)
    return f_wb
    
# grads calculation
def derivative_cost(f_wb, x_train, y_train):
    """
    dj_dw = shape(1, no of features)
    dj_db =
    """
    m = x_train.shape[1]
    # print(np.dot((f_wb-y_train), x_train.T).shape)
    dj_dw= 1/m * np.dot((f_wb-y_train), x_train.T)
    dj_db= 1/m * np.sum(f_wb-y_train)

    # print('dw', dj_dw.shape)
    # print('db', dj_db.shape)

    return dj_dw,dj_db

# gradient descent
def gradient_descent(w,b,dj_dw, dj_db, alpha):

    w = copy.deepcopy(w)
    b = copy.deepcopy(b)

    # print("w", w.shape)
    

    w = w - alpha*dj_dw.T
    b = b - alpha*dj_db.T

    
    return w,b

# 
def linear_regression_model(x_train, y_train, alpha, no_of_iterations):

    w, b = initializing_params(x_train)
    l_dw=[]

    for i in range(no_of_iterations):

        f_wb = compute_model_output(x_train, w, b)
        dj_dw, dj_db = derivative_cost(f_wb, x_train, y_train)
        w,b= gradient_descent(w, b, dj_dw, dj_db, alpha)
        # print(f"loop{i}", dj_dw)
        l_dw.append(dj_dw[0])

    return w, b, l_dw

def predict(X, w, b):
    
    price = compute_model_output(X, w, b)
    return price
        
if __name__ == "__main__":

    # importing data
    path = 'kc_house_data.csv'
    x_train, y_train = suitable_dataset(path)   
    print("y",y_train.shape)
    # running optimisation model
    alpha = 5e-20
    w, b, l_dw = linear_regression_model(x_train, y_train, alpha, 100)

    # prediction
    i = 10
    x_test = x_train[:, i].reshape((x_train.shape[0], 1))
    x_train = x_train.T
    # print(x_train[:5])
    print(x_test)
    print("real", y_train[:,i])
    price = predict(x_test, w, b)
    print("k",price)


    plt.plot(l_dw)
    plt.show()