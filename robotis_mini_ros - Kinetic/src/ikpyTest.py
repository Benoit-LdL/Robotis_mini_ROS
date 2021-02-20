#!/usr/bin/env python
import ikpy
from ikpy.chain import Chain
import numpy as np
import ikpy.utils.plot as plot_utils

my_chain = Chain.from_urdf_file("/home/pi/Desktop/ikpy-master/resources/poppy_ergo.URDF")

target_position = [ 0.1, -0.2, 0.1]

print("The angles of each joints are : ", my_chain.inverse_kinematics(target_position))

real_frame = my_chain.forward_kinematics(my_chain.inverse_kinematics(target_position))
print("Computed position vector : %s, original position vector : %s" % (real_frame[:3, 3], target_frame[:3, 3]))

# Optional: support for 3D plotting in the NB
# If there is a matplotlib error, uncomment the next line, and comment the line below it.
#%matplotlib inline
#%matplotlib widget
import matplotlib.pyplot as plt
fig, ax = plot_utils.init_3d_figure()
my_chain.plot(my_chain.inverse_kinematics(target_position), ax, target=target_vector)
plt.xlim(-0.1, 0.1)
plt.ylim(-0.1, 0.1)
