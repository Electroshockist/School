using System.Collections;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class Nexus : MonoBehaviour {

    [SerializeField] private GameObject boid, loseUI;
    [SerializeField] private Text healthText;
    [SerializeField] private float spawnTime;
    [SerializeField] private float health;
    private bool isBoidSpawnable = true;

    private void Update() {
        if (lost()) {
            loseUI.SetActive(true);
            if (Input.anyKeyDown) {
                SceneManager.LoadScene(SceneManager.GetActiveScene().name);
            }
        }
        else {
            healthText.text = "Health: " + health;
        }
    }

    private void OnTriggerEnter2D(Collider2D collision) {
        if (collision.tag == "Boid") {
            if (isBoidSpawnable) {
                SpawnBoid();
            }
        }
    }

    private void SpawnBoid() {
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

    public bool lost() {
        return health <= 0;
    }

}
