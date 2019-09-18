using System.Collections;
using UnityEngine;

public class PlayerSpawnBullet : ControlComponent {
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
        Vector2 tempVector = (Vector2)cachedVector;
        if (tempVector.magnitude > 1) {
            tempVector.Normalize();
        }

        if (tempVector.magnitude > 0) {
            shoot(tempVector);
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
}
