using System;
using UnityEngine;

[Serializable]
public class BoidAvoid : BoidInput {

    public override void Start(Data data) {
        base.Start(data);
    }

    public override void Update() {
        Vector2 steer = Vector2.zero;
        int count = 0;

        foreach (GameObject other in boids) {
            float d = Vector3.Distance(self.transform.position, other.transform.position);
            // Calculate vector pointing away from neighbor
            Vector2 diff = self.transform.position - other.transform.position;
            diff = diff.normalized * (1 - Mathf.Clamp01(diff.magnitude / radius));
            //diff /= d;
            steer += diff;
            count++;
        }
        if (count > 0) {
            steer /= count;
        }

        if (steer.magnitude > 0) {
            steer.Normalize();
            steer *= maxSpeed;
            steer -= self.GetComponent<Rigidbody2D>().velocity;
            if (steer.magnitude > maxForce) {
                steer.Normalize();
                steer *= maxForce;
            }
        }
        dataNode.Value = steer * strength;
    }
}
