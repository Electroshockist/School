using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Gizmos : MonoBehaviour {
    private static Gizmos active;
    private static Gizmos Active {
        get {
            if (!active)
                active = FindObjectOfType<Gizmos>();
            return active;
        }
        set {
            active = value;
        }
    }

    public static Color color = Color.white;


    private static int activeLine = -1;

    public static void DrawLine(Vector3 start, Vector3 end) {
        if (Active.lines.Count < 1)
            NewLine();

        if (Active.line.positionCount < 1 || Active.line.GetPosition(Active.line.positionCount - 1) != start) {
            Active.line.positionCount++;
            Active.line.SetPosition(Active.line.positionCount - 1, start);
        }

        Active.line.positionCount++;
        Active.line.startColor = Active.line.endColor = color;
        Active.line.SetPosition(Active.line.positionCount - 1, end);
    }

    public static void NewLine() {
        activeLine++;
        Active.lines.Add(Instantiate(Active.line));
    }


    public static void DrawSphere(Vector3 position, float radius) {
        for (int i = 0; i < Active.spheres.Count; i++) {
            if (Active.spheres[i] == null) {
                Active.spheres.RemoveAt(i);
                i--;
            }
        }

        if (!Active.spheres.Find(s => s.transform.position == position)) {
            MeshRenderer sphere = Instantiate(Active.sphere, position, new Quaternion());
            sphere.sharedMaterial = new Material(sphere.sharedMaterial);
            sphere.sharedMaterial.SetColor("_Color", color);
            sphere.transform.localScale = Vector3.one * radius;
            Active.spheres.Add(sphere.gameObject);
        }
    }

    public static void Clear() {
        foreach (GameObject sphere in Active.spheres) {
            DestroyImmediate(sphere);
        }



        Active.spheres.Clear();

        foreach (LineRenderer line in Active.lines) {
            DestroyImmediate(line.gameObject);
        }



        Active.lines.Clear();

    }




    public MeshRenderer sphere;
    public List<GameObject> spheres = new List<GameObject>();
    public LineRenderer line;
    public List<LineRenderer> lines = new List<LineRenderer>();

    // Use this for initialization
    void Start() {
        Active = this;
    }

    private void Update() {
        Clear();
    }
}
