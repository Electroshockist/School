using UnityEngine;

public class Enemy : MonoBehaviour {

    [SerializeField] private int turnX1;
    [SerializeField] private int turnX2;

    Vector3 orientation = Vector3.up;
    public Vector3 velocity;

    // Update is called once per frame
    void Update() {
        Vector3 pos = transform.position;

        if(pos.x <= turnX1) {
            velocity.x = Mathf.Abs(velocity.x);
        }
        else if(pos.x >= turnX2) {
            velocity.x = -Mathf.Abs(velocity.x);
        }

        float dt = Time.deltaTime;

        orientation = velocity.normalized;
        UpdateOrientation();
        pos += velocity * dt;

        transform.position = pos;
    }

    void UpdateOrientation() {
        Vector3 angle = new Vector3(0, 0, -Mathf.Atan2(orientation.x, orientation.y) * Mathf.Rad2Deg);
        transform.eulerAngles = angle;
    }

    public Vector3 GetVelocity() {
        return velocity;
    }
}
