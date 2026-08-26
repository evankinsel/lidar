import numpy as np
import open3d as o3d

# 1. Load a point cloud data file (not a .py file)
pcd = o3d.io.read_point_cloud("input_cloud.ply")
print(f"Total points: {len(pcd.points)}") 
#len means the length of the array, which is the number of points in the point cloud.

# 2. This extracts the coordinates from sensor and turn into a NumPy array
points = np.asarray(pcd.points)


#"Voxel downsampling" is  when points falling within the same voxel boundaries are averaged into a single point."
pcd = pcd.voxel_down_sample(voxel_size=0.05)

# Stage 2: Safe Downsampling Guard
if len(points) <= target_count:
    # nothing should happen here 
    final_points = points
else:
    # Further downsampling should happen if it's still too heavy. (great than target_count)
    # If voxel downsampling left you with 5,000 points, but target is 1,000:
    step = len(points) // target_count
    final_points = points[::step][:target_count]
    
#3. Visualize the final 3D model in point cloud format instead of mesh for now at least
o3d.visualization.draw_geometries([pcd], window_name="3D Model", width=800, height=600, left=50, top=50, point_show_normal=False)

#4 
pcd.points = o3d.utility.Vector3dVector(final_points)
print(f"Final points after downsampling: {len(pcd.points)}")