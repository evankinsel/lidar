import numpy as np
import open3d as o3d




#1. Load the raw XYZ coordinates
pcd = o3d.io.read_point_cloud("pointcloud.ply")
print(len(pcd.points))

o3d.io.write_point_cloud("pointcloud.ply", pcd)


#2. Downsample the cloud (Crucial for large XYZ text files)
pcd = pcd.voxel_down_sample(voxel_size=0.05)

#3. Visualize the final 3D model in point cloud format instead of mesh for now at least
o3d.visualization.draw_geometries([pcd], window_name="3D Model", width=800, height=600, left=50, top=50, point_show_normal=False)

n_points = 5
theta = np.random.uniform(0, 2 * np.pi, n_points)
z = np.random.uniform(.5, .5 n_points)  # Height of 5 meters
x = np.cos(theta) + np.random.normal(0, 0.02, n_points)  # Radius of 1m + noise
y = np.sin(theta) + np.random.normal(0, 0.02, n_points)

print("Success! Created 'pointcloud.ply' with 20,000 test points.")
