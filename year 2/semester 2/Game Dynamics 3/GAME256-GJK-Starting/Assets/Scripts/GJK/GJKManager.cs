using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GJKManager : MonoBehaviour {
    [Serializable]
    public struct GJKMeshHelper {
        public GJKMesh meshGJK;
        public Transform transform;
        public Mesh meshReference;
    }

    public UI ui;
    public static int maxVisibleSimplex, minVisibleSimplex;

    public GJKMeshHelper a;
    public GJKMeshHelper b;

    public GJKState state;

    void GJK() {
        a.meshGJK = new GJKMesh() { transform = a.transform, mesh = a.meshReference };
        b.meshGJK = new GJKMesh() { transform = b.transform, mesh = b.meshReference };

        state = new GJKState();
        state.isColliding = GJKAlgorithm.Intersects(a.meshGJK, a.meshGJK.transform, b.meshGJK, b.meshGJK.transform, state);
    }

    // Use this for initialization
    void Start() {
    }

    // Update is called once per frame
    void Update() {
        bool colliding = state.isColliding;

        GJK();

        GizmosDraw();
    }

    public Simplex simplex;
    void GizmosDraw() {
        // Minkowski Sum
        // Draw all the points in state.searchedSum
        // Iterate across mesh A iterate across mesh B and determine the Minkowski Sum
        Gizmos.color = Color.yellow;
        foreach (Vector3 A in a.meshReference.vertices) {
            foreach (Vector3 B in b.meshReference.vertices) {
                Gizmos.DrawSphere(a.transform.TransformPoint(A) + -b.transform.TransformPoint(B), 0.02f);
            }
        }

        // Support Function
        Vector3 pointA = a.meshGJK.GetFurthestPoint(GJKAlgorithm.direction);
        Vector3 pointB = b.meshGJK.GetFurthestPoint(-1 * GJKAlgorithm.direction);
        Gizmos.color = Color.green;
        Gizmos.DrawSphere(pointA, 0.05f);
        Gizmos.DrawSphere(pointB, 0.05f);

        Gizmos.color = Color.cyan;
        Gizmos.DrawLine(pointA, pointB);

        Gizmos.NewLine();
        Gizmos.color = Color.red;
        Gizmos.DrawLine(Vector3.zero, GJKAlgorithm.direction);

        // Drawing Simplicies
        if (state.simplices.Count < 1)
            return;

        Gizmos.NewLine();
 
        ui.SetVisibleSimplecies(this);
        print("Max/total: " + maxVisibleSimplex + "/" + state.simplices.Count + "\nMin: " + minVisibleSimplex);
        for (int o = maxVisibleSimplex - 1; o >= minVisibleSimplex; o--) {
            simplex = state.simplices[o];
            Vector3 a = simplex.vertices[0];

            // Point Drawer
            if (state.isColliding)
                Gizmos.color = Color.green;
            else
                Gizmos.color = Color.yellow;

            Gizmos.DrawSphere(a, 0.05f);

            // Line Drawer
            if (simplex.vertices.Count > 1) {
                for (int i = 1; i < simplex.vertices.Count; i++) {
                    Vector3 b = simplex.vertices[i];

                    Gizmos.DrawSphere(b, 0.05f);
                    Gizmos.DrawLine(a, b);

                    for (int j = i + 1; j < simplex.vertices.Count; j++) {
                        Vector3 c = simplex.vertices[j];

                        Gizmos.DrawSphere(c, 0.05f);
                        Gizmos.DrawLine(b, c);
                    }
                }
            }
        }

        Gizmos.color = Color.white;
        Gizmos.DrawSphere(Vector3.zero, 0.05f);
    }
}
