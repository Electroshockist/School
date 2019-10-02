using System;
using UnityEngine;

[Serializable]
public class BoidAlign : BoidInput {

    public override void Start(Data data) {
        base.Start(data);
    }

    public override void Update() {
        // For every nearby boid in the system, calculate the average velocity
        Vector2 sum = Vector3.zero;
        Vector2 steer = Vector2.zero;
        int count = 0;

        foreach (GameObject other in boids) {
            // Calculate the sum of all the velocities of the boids
            sum += other.GetComponent<Rigidbody2D>().velocity;
            count++;
        }

        if (count > 0) {
            // To do: Implement Rynolds: Steering = Desired - Velocity
            // The magnitude of steer should not be greater than maxForce
            sum.Normalize();
            Vector2 tempVel = sum * maxSpeed;
            if (steer.magnitude <= maxForce) {
                steer = tempVel - self.GetComponent<Rigidbody2D>().velocity;
            }
        }

        dataNode.Value = steer;
    }
}
