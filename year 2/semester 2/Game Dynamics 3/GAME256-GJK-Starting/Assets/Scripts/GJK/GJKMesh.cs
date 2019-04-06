using System.Collections.Generic;
using UnityEngine;

public class GJKMesh : IConvexRegion {
    public Transform transform;
    public Mesh mesh;
    public List<Vector3> vertices;

    public Vector3 GetFurthestPoint(Vector3 direction) {
        // TODO: Implement support point function for mesh
        // GetFurthest Point in Direction
        if (vertices == null) {
            vertices = new List<Vector3>(mesh.vertices);
        }

        float highestNum = -1;
        Vector3 farthestPoint = transform.TransformPoint(vertices[0]); ;
        float dotProduct = highestNum = Vector3.Dot(farthestPoint, direction);

        for (int i = 1; i < mesh.vertices.Length; i++) {
            Vector3 point = transform.TransformPoint(vertices[i]);
            dotProduct = Vector3.Dot(point, direction);
            if (dotProduct > highestNum) {
                highestNum = dotProduct;
                farthestPoint = point;
            }
        }

        return farthestPoint;
    }
}