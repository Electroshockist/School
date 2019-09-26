using UnityEngine;

public class Intercepter : MonoBehaviour {
    public GameObject target;
    public float speed;
    public float maxAngularSpeed;
    Vector3 velocity = Vector3.zero;
    Vector3 orientation = Vector3.up;

    // Use this for initialization
    void Start() {

    }

    // Update is called once per frame
    void Update() {
        // To do: Complete Update() to intercept the target
        // * recommended steps: 
        // 1. implement the chasing that you did in Lab3.1
        // 2. (Optional) implement the rotation limit that you did in Lab3.3
        // 3. calculate the predicted moving position and chase the predicted position instead of the actual position of the target.

       
        Move(InterceptVector());

    }

    private Vector3 InterceptVector() {
        // 1.Calculate the relative velocity(closing velocity):
        //Vr = Vtarget – Vintercepter
        Vector3 vr = target.GetComponent<Meteor>().GetVelocity() - velocity;
        //2.Calculate the relative distance(range to close):
        //Sr = Starget – Sintercepter
        Vector3 sr = target.transform.position - transform.position;
        //3.Calculate the time to close
        //tc = | Sr |/| Vr |
        float tc = sr.magnitude / vr.magnitude;
        //4.Calculate the predicted position of the target.
        //St = Starget + Vtarget * tc
        return target.transform.position + target.GetComponent<Meteor>().velocity * tc;
    }

    private void Move(Vector3 direction) {
        float dt = Time.deltaTime;

        Vector3 dir = direction - transform.position;

        float availableAngle = maxAngularSpeed * dt;

        //theta = acos(A . B / |A||B|)
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
