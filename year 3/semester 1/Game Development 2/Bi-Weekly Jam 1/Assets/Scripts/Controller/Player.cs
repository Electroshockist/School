using System.Collections;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Player : ControlComponent {
    public GameObject DeathMenu;
    private bool isDead = false;

    [Header("Bullet")]
    [SerializeField] GameObject bullet;
    [Header("Wait Time")]
    [SerializeField] private float waitTime;
    private bool canShoot = true;

    [Header("Data Node")]
    [SerializeField] private string dataName = "inputVector2";

    private DataNode cachedVector;
    public override void Gather(Data data) {
        cachedVector = data[dataName];
    }

    public override void Execute() {
        if (!isDead) {
            Vector2 tempVector = (Vector2)cachedVector;
            if (tempVector.magnitude > 1) {
                tempVector.Normalize();
            }

            if (tempVector.magnitude > 0) {
                shoot(tempVector);
            }
        }
        else {
            if (Input.GetKey(KeyCode.Space)) {
                SceneManager.LoadScene(SceneManager.GetActiveScene().name);
            }
        }
    }

    private void shoot(Vector2 v) {
        if (canShoot) {
            bullet.GetComponent<BulletInput>().setVector((Vector2)cachedVector);
            Transform t = transform;
            GameObject tempG = Instantiate(bullet, transform.position, Quaternion.identity);
            StartCoroutine(waitForSpawn());
            StartCoroutine(killAfterTime(tempG));
        }
    }

    private IEnumerator waitForSpawn() {
        canShoot = false;
        yield return new WaitForSeconds(0.5f);
        canShoot = true;
    }

    private IEnumerator killAfterTime(GameObject g) {
        print(g);
        yield return new WaitForSeconds(3.0f);
        Destroy(g);
    }

    public void kill() {
        DeathMenu.SetActive(true);
        gameObject.GetComponent<ControlVector2ToTranslate>().speed = 0;
        isDead = true;
        print(isDead);
    }
}
