import numpy as np
import pandas as pd
import open3d as o3d
import pymeshlab as ml

pcd = o3d.io.read_point_cloud("pointcloud.ply")
# 1. Load the raw XYZ coordinates

pcd = pcd.voxel_down_sample(voxel_size=0.05)
# 2. Downsample the cloud (Crucial for large XYZ text files)

# 3. Estimate normals (Required for XYZ data to build a 3D model)
pcd.estimate_normals(search_param=o3d.geometry.KDTreeSearchParamHybrid(radius=0.1, max_nn=30))

# 4. Generate the 3D surface mesh (Poisson Reconstruction)
mesh, densities = o3d.geometry.TriangleMesh.create_from_point_cloud_poisson(pcd, depth=9)

# 5. Visualize the final 3D model
o3d.visualization.draw_geometries([mesh])









