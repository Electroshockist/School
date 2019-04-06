using UnityEngine;

static class PhysicsExtensionMethods
{
    public static bool IsInSameDirection(this Vector3 vector, Vector3 otherVector)
    {
        return Vector3.Dot(vector, otherVector) > 0;
    }

    public static bool IsInOppositeDirection(this Vector3 vector, Vector3 otherVector)
    {
        return Vector3.Dot(vector, otherVector) < 0;
    }

    public static Vector3 TripleCross(this Vector3 a, Vector3 b) {
        return Vector3.Cross(Vector3.Cross(a, b), a);
        //return b * Vector3.Dot(a, b) - a * Vector3.Dot(a, b);
    }
}