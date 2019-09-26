using UnityEngine;

public class Chaser2 : MonoBehaviour {
    public GameObject target;
    public float speed;
    public float maxAngularSpeed;

    Vector3 orientation = Vector3.up;

    // Use this for initialization
    void Start() {

    }

    // Update is called once per frame
    void Update() {

        // To do: Complete Update() to chase the targe with the angular speed limit (maxAngularSpeed)
        // * recommended steps: 
        // 1. implement the chasing that you did in Lab3.1
        // 2. limit the rotation (orientation). The rotation angle cannot be over the max angle based on maxAngularSpeed.
        float dt = Time.deltaTime;


        // To do: Get the direction(dir) towards the target. The direction should be a unit vector.
        Vector3 dir = target.transform.position - transform.position;

        //1.
        float availableAngle = maxAngularSpeed * dt;

        //2. theta = acos(A . B / |A||B|)
        float targetAngle = Mathf.Acos(
            Vector2.Dot(dir, orientation) / dir.magnitude * orientation.magnitude) * Mathf.Rad2Deg;

        dir.Normalize();


        if(targetAngle > availableAngle) {
            availableAngle *= checkRight(dir);
            dir.x = orientation.x * Mathf.Cos(availableAngle * Mathf.Deg2Rad) - orientation.y * Mathf.Sin(availableAngle * Mathf.Deg2Rad);
            dir.y = orientation.x * Mathf.Sin(availableAngle * Mathf.Deg2Rad) + orientation.y * Mathf.Cos(availableAngle * Mathf.Deg2Rad);
        }

        // Update orientation 
        orientation = dir;
        UpdateOrientation();

        Vector3 pos = transform.position;
        Vector3 velocity = orientation * speed;
        // To do: Update the current position (pos) using S_final = S_initial + v * t
        pos += velocity * dt;


        transform.position = pos;
    }

    void UpdateOrientation() {
        Vector3 angle = new Vector3(0, 0, -Mathf.Atan2(orientation.x, orientation.y) * Mathf.Rad2Deg);
        transform.eulerAngles = angle;
    }

    private int checkRight(Vector3 dir) {
        Vector2 normal = new Vector2(orientation.y, -orientation.x);

        return Vector2.Dot(dir, normal) > 0 ? -1 : 1;
    }
}
