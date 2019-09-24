﻿using UnityEngine;

public class MonsterRandom : GridMovement {
    float timer;
    float pauseTime = 0.1f;

    int counter = 0;
    // Use this for initialization
    void Start() {

    }

    // Update is called once per frame
    void Update() {
        float dt = Time.deltaTime;
        timer -= dt;
        if (timer > 0) {
            return;
        }

        Vector3 movement = Vector3.zero;

        // To do : Replace Random.Range(1,9) with Perlin Noise function
        // * FYI: Random.Range(int min, int max) returns a random interger number between min[inclusive] and max[exclusive]
        // * For more details about Random.Range, https://docs.unity3d.com/ScriptReference/Random.Range.html
        int direction = (int)(1 + Mathf.PerlinNoise(counter++ * 0.1f + Time.time, 0.5f) * 7.9f);

        switch (direction) {
            case 1: // Up Left
                movement.x = -1;
                movement.y = 1;
                break;
            case 2: // Up
                movement.x = 0;
                movement.y = 1;
                break;
            case 3: // Up Right
                movement.x = 1;
                movement.y = 1;
                break;
            case 4: // Right
                movement.x = 1;
                movement.y = 0;
                break;
            case 5: // Down Right
                movement.x = 1;
                movement.y = -1;
                break;
            case 6: // Down
                movement.x = 0;
                movement.y = -1;
                break;
            case 7: // Down Left
                movement.x = -1;
                movement.y = -1;
                break;
            case 8: // Left
                movement.x = -1;
                movement.y = 0;
                break;
        }

        positionOnGrid += movement;
        base.Update();

        if (movement != Vector3.zero) {
            timer = pauseTime;
        }
    }
}
