import numpy as np
import matplotlib.pyplot as plt
import random

heads_tails = [0, 0]

fig, ax = plt.subplots(subplot_kw={'projection': 'polar'})

for i in range(100000):
    r = random.randint(1, 50)
    theta = random. randint(0, 180)
    ax.clear()
    ax.scatter(theta, r)
    ax.set_rmax(50)
    ax.set_thetamax(180)
    plt.pause(0.5)
