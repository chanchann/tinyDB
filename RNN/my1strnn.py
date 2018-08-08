# Recurrent Neural Network

# Part 1 - Data Preprocessing

# Importing the libraries
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.preprocessing import MinMaxScaler
from keras.models import Sequential
from keras.layers import Dense
from keras.layers import LSTM
from keras.layers import Dropout

# Importing the training set
dataset_train = pd.read_csv('/Users/QZhu/Desktop/DS1090code/RNN/Google_Stock_Price_Train.csv')
training_set = dataset_train.iloc[:, 1:2].values

plt.plot(training_set)

# regression based prediction
# y=ax+b??

# Feature Scaling
# normalization [x-min(x)]/ [max(x) - min(x)]
sc = MinMaxScaler(feature_range = (0, 1))
training_set_scaled = sc.fit_transform(training_set)

plt.plot(training_set_scaled)

# Creating a data structure with 60 timesteps (memory) and 1 output
X_train = []
y_train = []
for i in range(60, 1258):
    X_train.append(training_set_scaled[i-60:i, 0])
    y_train.append(training_set_scaled[i, 0])
X_train, y_train = np.array(X_train), np.array(y_train)

plt.plot(X_train)
plt.plot(y_train)

# Reshaping
# matrix to tensor
# [batch size, timestep, input dimension]
X_train = np.reshape(X_train, (X_train.shape[0], X_train.shape[1], 1))

# Part 2 - Building the RNN

# Importing the Keras libraries and packages

# Initialising the RNN
my1stRNN = Sequential()

# Adding the first LSTM layer and some Dropout regularisation
my1stRNN.add(LSTM(50, return_sequences = True, input_shape = (X_train.shape[1], 1)))
#my1stRNN.add(Dropout(0.2))

# Adding a second LSTM layer and some Dropout regularisation
my1stRNN.add(LSTM(50, return_sequences = True))
#my1stRNN.add(Dropout(0.2))

# Adding a third LSTM layer and some Dropout regularisation
my1stRNN.add(LSTM(50, return_sequences = True))
#my1stRNN.add(Dropout(0.2))

# Adding a fourth LSTM layer and some Dropout regularisation
my1stRNN.add(LSTM(50))
#my1stRNN.add(Dropout(0.2))

# Adding the output layer
my1stRNN.add(Dense(output_dim = 1))

# Compiling the RNN
my1stRNN.compile(optimizer = 'adam', loss = 'mean_squared_error')

# Fitting the RNN to the Training set
my1stRNN.fit(X_train, y_train, nb_epoch = 10, batch_size = 32)

# Part 3 - Making the predictions and visualising the results

# Getting the real stock price of 2017
dataset_test = pd.read_csv('/Users/QZhu/Desktop/DS1090code/RNN/Google_Stock_Price_Test.csv')
#real_stock_price = dataset_test.iloc[:, 1:2].values
real_stock_price = np.append(dataset_train.iloc[:, 1:2].values,  dataset_test.iloc[:, 1:2].values);

# Getting the predicted stock price of 2017
# dataset_total = pd.concat((dataset_train['Open'], dataset_test['Open']), axis = 0)
# inputs = dataset_total[len(dataset_total) - len(dataset_test) - 60:].values
inputs = real_stock_price
inputs = inputs.reshape(-1,1)
inputs = sc.transform(inputs)
X_test = []
for i in range(60, len(inputs)):
    X_test.append(inputs[i-60:i, 0])
X_test = np.array(X_test)
X_test = np.reshape(X_test, (X_test.shape[0], X_test.shape[1], 1))
predicted_stock_price = my1stRNN.predict(X_test)
predicted_stock_price = sc.inverse_transform(predicted_stock_price)

# Visualising the results
plt.plot(real_stock_price[60:,], color = 'red', label = 'Real Google Stock Price')
plt.plot(predicted_stock_price, color = 'blue', label = 'Predicted Google Stock Price')
plt.title('Google Stock Price Prediction')
plt.xlabel('Time')
plt.ylabel('Google Stock Price')
plt.legend()
plt.show()
