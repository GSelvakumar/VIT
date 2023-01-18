import numpy as np
import tensorflow as tf

X = [[25, 2], [5, 26], [3, 7]]
print(X)
print(np.array(X).shape)

Y = tf.multiply(X, 2)
Y = tf.add(Y, 2)

Z = tf.add(tf.multiply(X, 2), 2)

print(Z)