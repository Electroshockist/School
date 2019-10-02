using System;
using UnityEngine;

[Serializable]
public class BoidCohere : BoidInput {

    public override void Start(Data data) {
        base.Start(data);
    }

    public override void Update() {
        // For the average position (i.e. center) of all nearby boids, calculate steering vector towards that position
        Vector3 sum = Vector3.zero;
        int count = 0;

        foreach (GameObject other in boids) {
                // To do : Calculate the sum of all the positions of the boids    
                sum += other.transform.position;

                count++;
        }

        if (count > 0) {
            Vector3 averagePos = Vector3.zero;
            // To do: Calculate the average position and steer toward the position
            averagePos = (sum / count);
            dataNode.Value = Seek(averagePos);
            return;
        }

        dataNode.Value = Vector3.zero;
    }

    Vector2 Seek(Vector2 target) {

        Vector2 pos = new Vector2(self.transform.position.x, self.transform.position.y);
        Vector2 desired = target - pos;
        desired.Normalize();
        desired /= maxSpeed;

        Vector3 steer = desired - self.GetComponent<Rigidbody2D>().velocity;
        if (steer.magnitude > maxForce) {
            steer.Normalize();
            steer *= maxForce;
        }

        return steer;
    }
}
