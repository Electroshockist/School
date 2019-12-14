using UnityEngine;

[RequireComponent(typeof(SpriteRenderer))]
public class DrawerTester : MonoBehaviour {
    SpriteRenderer s;
    public Color colour = Color.red, colour2;

    private void Start() {
        s = GetComponent<SpriteRenderer>();
    }

    // Update is called once per frame
    void Update() {
        print(colour);
        s.color = colour;
    }
}
