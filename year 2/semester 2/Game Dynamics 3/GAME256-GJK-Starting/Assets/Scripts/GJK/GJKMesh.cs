using System.Collections.Generic;
using UnityEngine;

public class GJKMesh : IConvexRegion
{
    public Transform transform;
    public Mesh mesh;
    public List<Vector3> vertices;

    public Vector3 GetFurthestPoint(Vector3 direction)
    {
        // TODO: Implement support point function for mesh
        return Vector3.zero;
    }
}