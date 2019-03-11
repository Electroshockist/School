using System.Collections.Generic;
using UnityEngine;

public class GJKMesh : IConvexRegion {
    public Transform transform;
    public Mesh mesh;
    public List<Vector3> vertices;

    public Vector3 GetFurthestPoint(Vector3 direction) {
        // TODO: Implement support point function for mesh

        Vector3 small = Vector3.zero;

        if (vertices == null) {
            //bring all vertices into V3 list
            vertices = new List<Vector3>(mesh.vertices);
        }
        float greatest = float.PositiveInfinity;

        for (int i = 0; i < vertices.Count; i++) {
            //convert to world space since GJK uses world space
            Vector3 tempvec = transform.TransformPoint(vertices[i]);            
            float point = Vector3.Dot(tempvec, direction);
            if (point > greatest) {
                greatest = point;
                small = vertices[i];
            }
        }

        return small;
    }
}