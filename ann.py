from google.colab import drive
drive.mount('/content/drive')

import pandas as pd

# Load the dataset into a pandas dataframe
data = pd.read_csv('/content/drive/MyDrive/dataset.csv')

# Preprocess the data

# Split the data into training and testing sets
train_data, test_data = train_test_split(data, test_size=0.2)

# Prepare the data for training the model
train_data = train_data.to_numpy()
train_labels = train_data[:, -1]
train_data = train_data[:, :-1]

test_data = test_data.to_numpy()
test_labels = test_data[:, -1]
test_data = test_data[:, :-1]

from keras.models import Sequential
from keras.layers import Dense, Dropout

# Define the model architecture
model = Sequential()
model.add(Dense(128, input_dim=train_data.shape[1], activation='relu'))
model.add(Dropout(0.5))
model.add(Dense(64, activation='relu'))
model.add(Dropout(0.5))
model.add(Dense(1, activation='sigmoid'))

# Compile the model
model.compile(loss='binary_crossentropy', optimizer='adam', metrics=['accuracy'])

# Train the model
history = model.fit(train_data, train_labels, epochs=50, batch_size=64, validation_data=(test_data, test_labels))

# Evaluate the model on the testing set
test_loss, test_acc = model.evaluate(test_data, test_labels)
print('Test accuracy:', test_acc)

# Make predictions on new data
predictions = model.predict(new_data)
