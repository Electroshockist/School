using System;
using UnityEngine;

public class GJKManager : MonoBehaviour {
    [Serializable]
    public struct BoxHelper {
        public GJKMesh meshGJK;
        public Transform transform;
        public Mesh meshReference;
    }

    public BoxHelper a;
    public BoxHelper b;

    public GJKState state;

    public Simplex simplex;

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
    void GizmosDraw() {

        Gizmos.DrawSphere(Vector3.zero, 1);

        if (state.simplices.Count < 1)
            return;

        for (int o = state.simplices.Count - 1; o > state.simplices.Count - 1; o--) {
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
