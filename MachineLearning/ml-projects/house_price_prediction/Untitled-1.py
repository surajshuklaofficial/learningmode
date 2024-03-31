# %%
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error
import pandas as pd
import numpy as np

import matplotlib.pyplot as plt

# %%
df = pd.read_csv("house_prices_preprocessed.csv")

# %%
# target = "Amount(in rupees)"
# y = df[target]
# t = df.drop(columns=[target], axis=1)
# # features = t.columns
# print(features)
# for i, feature in enumerate(features[:9]):
#     plt.subplot(3, 3, i+1)
#     plt.scatter(df[feature], y)
#     plt.title(feature)

# %%
target = "Amount(in rupees)"
y = np.array(df[target])
X = np.array(df.drop(columns=[target], axis=1))

del df 

# %%
# Get 60% of the dataset as the training set. Put the remaining 40% in temporary variables: x_ and y_.
X_train, X_, y_train, y_ = train_test_split(X, y, test_size=0.40, random_state=1)

# Split the 40% subset above into two: one half for cross validation and the other for the test set
X_cv, X_test, y_cv, y_test = train_test_split(X_, y_, test_size=0.50, random_state=1)

# Delete temporary variables
del X_, y_

print(f"the shape of the training set (input) is: {X_train.shape}")
print(f"the shape of the training set (target) is: {y_train.shape}\n")
print(f"the shape of the cross validation set (input) is: {X_cv.shape}")
print(f"the shape of the cross validation set (target) is: {y_cv.shape}\n")
print(f"the shape of the test set (input) is: {X_test.shape}")
print(f"the shape of the test set (target) is: {y_test.shape}")

# %%
# Initialize the class
scaler_linear = StandardScaler()

# Compute the mean and standard deviation of the training set then transform it
X_train = scaler_linear.fit_transform(X_train)

# print(X_train_scaled.shape)
mean_value = scaler_linear.mean_.squeeze()
std_value = scaler_linear.scale_.squeeze()


print(mean_value.shape, std_value.shape)
print(mean_value)
print(std_value)

# print(f"Computed mean of the training set: {mean_value:.2f}")
# print(f"Computed standard deviation of the training set: {std_value:.2f}")

# %%
lr_model = LinearRegression()
reg = lr_model.fit(X_train, y_train)

reg.score(X_train, y_train)

# %%
yhat = lr_model.predict(X_train)

print(f"training log_loss (using sklearn function): {mean_squared_error(y_train, yhat) / 2}")

# %%
X_cv = scaler_linear.transform(X_cv)

# print(f"Mean used to scale the CV set: {scaler_linear.mean_.squeeze():.2f}")
# print(f"Standard deviation used to scale the CV set: {scaler_linear.scale_.squeeze():.2f}")

# Feed the scaled cross validation set
yhat = lr_model.predict(X_cv)

# Use scikit-learn's utility function and divide by 2
print(f"Cross validation MSE: {mean_squared_error(y_cv, yhat) / 2}")

# %%
X_test = scaler_linear.transform(X_test)

# print(f"Mean used to scale the CV set: {scaler_linear.mean_.squeeze():.2f}")
# print(f"Standard deviation used to scale the CV set: {scaler_linear.scale_.squeeze():.2f}")

# Feed the scaled cross validation set
yhat = lr_model.predict(X_test)

# Use scikit-learn's utility function and divide by 2
print(f"Test MSE: {mean_squared_error(y_test, yhat) / 2}")


