using UnityEngine;

public static class GJKAlgorithm {
    public static Vector3 direction;
    //public void SetDirectionX(string s) {
    //    float x;
    //    float.TryParse(s, out x);
    //    direction = new Vector3(x, direction.y, direction.z);
    //}

    //public void SetDirectionY(string s) {
    //    float y;
    //    float.TryParse(s, out y);
    //    direction = new Vector3(direction.x, y, direction.z);
    //}

    //public void SetDirectionZ(string s) {
    //    float z;
    //    float.TryParse(s, out z);
    //    direction = new Vector3(direction.x, direction.y, z);
    //}

    public static bool Intersects(IConvexRegion regionOne, Transform oneTrans, IConvexRegion regionTwo, Transform twoTrans, GJKState state) {
        // Get an initial point on the Minkowski difference.
        Vector3 s = Support(regionOne, regionTwo, twoTrans.position - oneTrans.position, state);

        // Create our initial simplex.
        Simplex simplex = new Simplex(s);

        // TODO: Choose an initial direction.
        direction = (oneTrans.position - twoTrans.position).normalized;

        state.simplices.Add(new Simplex(simplex.vertices.ToArray()));

        // Choose a maximim number of iterations to avoid an 
        // infinite loop during a non-convergent search.
        int maxIterations = 32;

        for (int i = 0; i < maxIterations; i++) {
            // Get our next simplex point toward the origin.
            Vector3 a = Support(regionOne, regionTwo, direction, state);

            // If we move toward the origin and didn't pass it 
            // then we never will and there's no intersection.
            if (a.IsInOppositeDirection(direction)) {
                return false;
            }

            // otherwise we add the new point to the simplex and process it.
            simplex.Add(a);
            state.simplices.Add(new Simplex(simplex.vertices.ToArray()));
            // Here we either find a collision or we find the closest feature of
            // the simplex to the origin, make that the new simplex and update the direction
            // to move toward the origin from that feature.
            if (ProcessSimplex(simplex, ref direction)) {
                return true;
            }
        }
        // If we still couldn't find a simplex 
        // that contains the origin then we
        // "probably" have an intersection.
        return true;
    }

    /// <summary>
    /// Finds a collision or the closest feature of the simplex to the origin, 
    /// and updates the simplex and direction.
    /// </summary>
    static bool ProcessSimplex(Simplex simplex, ref Vector3 direction) {
        if (simplex.Count == 2) {
            return ProcessLine(simplex, ref direction);
        }
        else if (simplex.Count == 3) {
            return ProcessTriangle(simplex, ref direction);
        }
        else {
            return ProcessTetrehedron(simplex, ref direction);
        }
    }

    /// <summary>
    /// Determines which Veronoi region of a line segment 
    /// the origin is in, utilizing the preserved winding
    /// of the simplex to eliminate certain regions.
    /// </summary>
    static bool ProcessLine(Simplex simplex, ref Vector3 direction) {
        // TODO: Process Line
        return false;
    }

    /// <summary>
    /// Determines which Veronoi region of a triangle 
    /// the origin is in, utilizing the preserved winding
    /// of the simplex to eliminate certain regions.
    /// </summary>
    static bool ProcessTriangle(Simplex simplex, ref Vector3 direction) {
        // TODO: Process Triangle
        return false;
    }

    /// <summary>
    /// Determines which Veronoi region of a tetrahedron
    /// the origin is in, utilizing the preserved winding
    /// of the simplex to eliminate certain regions.
    /// </summary>
    static bool ProcessTetrehedron(Simplex simplex, ref Vector3 direction) {
        // TODO: Process Tetrahedron
        return false;
    }

    /// <summary>
    /// Calculates the furthest point on the Minkowski 
    /// Sum along a given direction.
    /// </summary>
    static Vector3 Support(IConvexRegion regionOne, IConvexRegion regionTwo, Vector3 direction, GJKState state) {
        // TODO: Get support point
        Vector3 supportPoint = Vector3.zero;
        // A + (-B)
        supportPoint = regionOne.GetFurthestPoint(direction) + (-1 * regionTwo.GetFurthestPoint(-1 * direction));
        state.searchedSum.Add(supportPoint);
        return supportPoint;
    }
}