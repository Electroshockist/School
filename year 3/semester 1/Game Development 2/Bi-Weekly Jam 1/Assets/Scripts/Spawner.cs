using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Spawner : MonoBehaviour {

    public GameObject enemy;

    public float timeToSpawn;

    public Transform[] spawners = new Transform[4];

    float timeSinceLastSpawn = 0;

    // Start is called before the first frame update
    void Start() {
        Spawn();
    }

    // Update is called once per frame
    void Update() {
        if (timeSinceLastSpawn >= timeToSpawn) {
            Spawn();
            timeSinceLastSpawn = 0;
            return;
        }

        timeSinceLastSpawn += Time.deltaTime;
    }

    void Spawn() {
        int r = Random.Range(0, spawners.Length-1);
        Instantiate(enemy, spawners[r]);
    }
}
