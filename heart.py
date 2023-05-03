import pandas as pd
import numpy as np
import tensorflow as tf
from tensorflow import keras
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score

# load data
df = pd.read_csv('cnn\Heart.csv')

# preprocess data
# drop rows with missing values
df = df.dropna()

# split data into features and target
X = df.drop(['target'], axis=1)
y = df['target']

# normalize data
X = (X - X.mean()) / X.std()

# split data into train and validation sets
X_train, X_val, y_train, y_val = train_test_split(X, y, test_size=0.2, random_state=42)

# build ANN model
model = keras.Sequential([
    keras.layers.Dense(128, activation='relu', input_shape=(X_train.shape[1],)),
    keras.layers.Dense(64, activation='relu'),
    keras.layers.Dense(1, activation='sigmoid')
])

# compile the model
model.compile(loss='binary_crossentropy',
              optimizer='adam',
              metrics=['accuracy', keras.metrics.Precision(), keras.metrics.Recall()])

# train the model
history = model.fit(X_train, y_train,
                    epochs=10,
                    batch_size=32,
                    verbose=1,
                    validation_data=(X_val, y_val))

# evaluate model performance on validation set
y_pred = model.predict(X_val)
y_pred = np.round(y_pred).flatten()
print('Accuracy:', accuracy_score(y_val, y_pred))
print('Precision:', precision_score(y_val, y_pred))
print('Recall:', recall_score(y_val, y_pred))
print('F1-score:', f1_score(y_val, y_pred))