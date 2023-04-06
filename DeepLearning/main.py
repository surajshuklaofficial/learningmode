import tensorflow as tf
print('hi')
a = tf.constant([[1, 2, -3], [4, 5, 6]])
b = tf.constant([[0, 1, 2], [3, 4, 5]])
# b = tf.constant()

print(tf.subtract(a, b))

print(tf.maximum(a, 0))

