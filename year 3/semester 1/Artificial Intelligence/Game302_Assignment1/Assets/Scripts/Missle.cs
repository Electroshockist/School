using System;
using System.Collections;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class Missle : MonoBehaviour {
    [Serializable]
    private struct Ray {
        [HideInInspector]
        public bool isHitting, enabled;
        public float angle, length;
        public RaycastHit2D hit2D;
        public Color drawColor;

        public void init() {
            isHitting = false;
            enabled = true;
        }
    }

    public GameObject text;
    public GameObject target;
    public float speed;
    public float maxAngularSpeed;
    public Vector3 velocity = Vector3.zero;
    Vector3 orientation = Vector3.up;

    [HideInInspector] public bool isPlayerControlled = true;

    Vector3 pos;

    [SerializeField] private Ray rightRay;
    [SerializeField] private Ray leftRay;

    private void Start() {
        rightRay.init();
        leftRay.init();
    }

    // Update is called once per frame
    void Update() {
        pos = transform.position;
        Move(InterceptVector());
    }

    private Vector3 InterceptVector() {
        // 1.Calculate the relative velocity(closing velocity):
        //Vr = Vtarget – Vintercepter
        Vector3 vr = target.GetComponent<Enemy>().GetVelocity() - velocity;
        //2.Calculate the relative distance(range to close):
        //Sr = Starget – Sintercepter
        Vector3 sr = target.transform.position - transform.position;
        //3.Calculate the time to close
        //tc = | Sr |/| Vr |
        float tc = sr.magnitude / vr.magnitude;
        //4.Calculate the predicted position of the target.
        //St = Starget + Vtarget * tc
        return target.transform.position + target.GetComponent<Enemy>().velocity * tc;
    }

    private void Move(Vector3 direction) {
        if(!isPlayerControlled) {
            AI(direction);
        }
        // To do: Update the current position (pos) using S_final = S_initial + v * t
        pos += velocity * Time.deltaTime;

        transform.position = pos;
    }

    private void UpdateOrientation() {
        Vector3 angle = new Vector3(0, 0, -Mathf.Atan2(orientation.x, orientation.y) * Mathf.Rad2Deg);
        transform.eulerAngles = angle;
    }

    private int checkRight(Vector3 dir) {
        Vector2 normal = new Vector2(orientation.y, -orientation.x);

        return Vector2.Dot(dir, normal) > 0 ? -1 : 1;
    }

    private Vector2 addAngleToOrientation(float angle) {
        return new Vector2(
             orientation.x * Mathf.Cos(angle * Mathf.Deg2Rad) - orientation.y * Mathf.Sin(angle * Mathf.Deg2Rad),
             orientation.x * Mathf.Sin(angle * Mathf.Deg2Rad) + orientation.y * Mathf.Cos(angle * Mathf.Deg2Rad)
            );
    }

    private bool rayCast(Ray r) {
        if(r.enabled) {
            Vector2 angle = addAngleToOrientation(r.angle).normalized;
            r.hit2D = Physics2D.Raycast(pos, angle, 2.0f);
            Debug.DrawRay(pos, angle * r.length, r.drawColor);

            if(r.hit2D.collider != null && r.hit2D.collider.tag == "Obstacle") {
                r.isHitting = true;
            }
            else {
                r.isHitting = false;
            }
            return r.isHitting;
        }
        return false;
    }

    private void AI(Vector3 direction) {
        Vector3 dir = direction - transform.position;

        float availableAngle = maxAngularSpeed * Time.deltaTime;

        //theta = acos(A . B / |A||B|)
        float targetAngle = Mathf.Acos(
            Vector2.Dot(dir, orientation) / dir.magnitude * orientation.magnitude) * Mathf.Rad2Deg;

        dir.Normalize();
        //raycasting

        if(rayCast(leftRay)) {
            dir = addAngleToOrientation(-availableAngle);
            rightRay.enabled = false;
        }
        else {
            rightRay.enabled = true;
        }

        if(rayCast(rightRay)) {
            dir = addAngleToOrientation(availableAngle);
            leftRay.enabled = false;
        }
        else {
            leftRay.enabled = true;
        }

        if(targetAngle > availableAngle && !rightRay.isHitting && !leftRay.isHitting) {
            availableAngle *= checkRight(dir);
            dir = addAngleToOrientation(availableAngle);
        }

        // Update orientation 
        orientation = dir;
        UpdateOrientation();
        velocity = orientation * speed;
    }

    private void OnTriggerEnter2D(Collider2D collision) {
        text.SetActive(true);
        Text t = text.GetComponent<Text>();
        if(collision.gameObject.tag == "Enemy") {
            t.text = "You Win!";
            Destroy(collision.gameObject);
        }
        else {
            t.text = "You Lose!";
        }
        Destroy(gameObject);
    }
}
