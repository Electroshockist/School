﻿using UnityEngine;

public class Evader : MonoBehaviour {
    public GameObject target;
    public float speed;

    Vector3 orientation = Vector3.up;

    // Use this for initialization
    void Start() {

    }

    // Update is called once per frame
    void Update() {
        float dt = Time.deltaTime;

        // To do: Get the direction(dir) pointing to this object from the target.
        // The direction is exactly an opposite direction vector of chasing.
        // The direction should be a unit vector.
        Vector3 dir = transform.position - target.transform.position;

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
}
