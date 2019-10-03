using System.Collections;
using UnityEngine;

public class Nexus : MonoBehaviour {
    [SerializeField] private GameObject boid;
    [SerializeField] private float spawnTime;
    [SerializeField] private float health;
    private bool isBoidSpawnable = true;
    // Start is called before the first frame update
    void Start() {

    }

    // Update is called once per frame
    void Update() {
    }

    private void OnTriggerEnter2D(Collider2D collision) {
        if(collision.tag == "Boid") {
            if(isBoidSpawnable) {
                SpawnBoid();
            }
        }
    }

    void SpawnBoid() {
        StartCoroutine(onBoidSpawn());
        Instantiate(boid, transform);
    }

    IEnumerator onBoidSpawn() {
        isBoidSpawnable = false;
        yield return new WaitForSeconds(spawnTime);
        isBoidSpawnable = true;
    }

    public void damage(int damage) {
        health -= damage;
    }

}
