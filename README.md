TARE planner involves a hierarchical framework for highly efficient exploration - one level in the framework maintains data densely and computes a detailed path within a local planning horizon, another level maintains data sparsely and computes a coarse path at the global scale. The paths at both levels are joined together to form the exploration path. The framework draws the insight that detailed processing is most effective close to the vehicle, while coarse processing provides sufficient utility far away from the vehicle. The framework trades-off details at the global scale for computational speed. In practice, the framework prioritizes the exploration in the surroundings of the vehicle while keeping the global picture in mind.

Please use instructions on our [project page](https://www.cmu-exploration.com/tare-planner).

<p align="center">
  <img src="img/method.png" alt="Method" width="60%"/>
</p>

## Usage

The repository has been tested in Ubuntu 22.04 with ROS2 Humble and Ubuntu 24.04 with ROS2 Jazzy. Previously, due to usage of [OR-Tools](https://developers.google.com/optimization) library, the code only supports AMD64 architecture. A recent upgrade to the library made it compatible with both AMD64 and ARM computers. On ARM computers, please download the corresponding [binary release](https://github.com/google/or-tools/releases) for the target platform, for example, [or-tools_arm64_debian-11_cpp_v9.8.3296.tar.gz
](https://github.com/google/or-tools/releases/download/v9.8/or-tools_arm64_debian-11_cpp_v9.8.3296.tar.gz), extract it, and replace the ```include``` and ```lib``` folders under ```tare_planner/src/tare_planner/or-tools```. 

Follow instructions in [Autonomous Exploration Development Environment](http://cmu-exploration.com) to setup the development environment. Make sure to checkout the branch that matches the computer setup, compile, and download the simulation environments.

To setup TARE Planner, clone the repository.
```
git clone https://github.com/caochao39/tare_planner.git
```
In a terminal, go to the folder, checkout the 'humble-jazzy' branch, and compile.

```
cd tare_planner
git checkout humble-jazzy
colcon build --symlink-install --cmake-args -DCMAKE_BUILD_TYPE=Release
```
To run the code, go to the development environment folder in a terminal, source the ROS workspace, and launch.
```
source install/setup.sh
ros2 launch vehicle_simulator system_garage.launch
```
In another terminal, go to the TARE Planner folder, source the ROS workspace, and launch.
```
source install/setup.sh
ros2 launch tare_planner explore_garage.launch
```
Now, users should see autonomous exploration in action. To launch with a different environment, use the command lines below instead and replace '\<environment\>' with one of the environment names in the development environment, i.e. 'campus', 'indoor', 'garage', 'tunnel', and 'forest'.
```
ros2 launch vehicle_simulator system_<environment>.launch
ros2 launch tare_planner explore_<environment>.launch
```
To run TARE Planner in a [Matterport3D](https://niessner.github.io/Matterport) environment, follow instructions on the development environment page to setup the Matterport3D environment. Then, use the command lines below to launch the system and TARE Planner.
```
ros2 launch vehicle_simulator system_matterport.launch
ros2 launch tare_planner explore_matterport.launch
```

## Publications

- C. Cao, H. Zhu, Z. Ren, H. Choset, and J. Zhang. Representation Granularity Enables Time-Efficient Autonomous Exploration in Large, Complex Worlds. Science Robotics. vol. 8, no. 80, 2023.

- C. Cao, H. Zhu, H. Choset, and J. Zhang. TARE: A Hierarchical Framework for Efficiently Exploring Complex 3D Environments. Robotics: Science and Systems Conference (RSS). Virtual, July 2021. **Best Paper Award and Best System Paper Award**.

- C. Cao, H. Zhu, H. Choset, and J. Zhang: Exploring Large and Complex Environments
Fast and Efficiently. International Conference on Robotics and Automation (ICRA), Xi'an, China, June 2021.


## Application

TARE Planner was used by the [CMU-OSU Team](https://www.subt-explorer.com) in attending [DARPA Subterranean Challenge](https://www.subtchallenge.com). In the final competition which took place in Louisville Mega Cavern, KY, the team's robots conducted the most complete exploration across the site (26 out of 28 sectors) among all teams, winning a "Most Sectors Explored Award". Below is the result from Urban Circuit which took place in Satsop Nuclear Plant, WA. Our vehicle traveled over 886m in 1458s to explore the site, fully autonomously.
<p align="center">
  <img src="img/urban.jpg" alt="Urban Circuit" width="50%"/>
</p>

## Author

[Chao Cao](http://caochao.me) (ccao1@andrew.cmu.edu)

## Credit

[OR-Tools](https://developers.google.com/optimization) is from Google
