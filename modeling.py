import numpy as np
import pandas as pd
import open3d as o3d
import pymeshlab as ml

#1. Load the raw XYZ coordinates
pcd = o3d.io.read_point_cloud("pointcloud.ply")
print(len(pcd.points))

#2. Downsample the cloud (Crucial for large XYZ text files)
pcd = pcd.voxel_down_sample(voxel_size=0.05)

#3. Visualize the final 3D model in point cloud format instead of mesh for now at least
o3d.visualization.draw_geometries([pcd], window_name="3D Model", width=800, height=600, left=50, top=50, point_show_normal=False)
