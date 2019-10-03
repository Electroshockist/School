using System.Collections;
using UnityEngine;

public class Spawner : MonoBehaviour {
    [SerializeField] private float waitTime;
    [SerializeField] private int xScale, yScale;
    [SerializeField] private GameObject spawnable;
    // Start is called before the first frame update
    void Start() {
        StartCoroutine(spawn());
    }

    IEnumerator spawn() {
        while(isActiveAndEnabled) {
            int randX = (Random.Range(-1, 1)) >= 0 ? 1 : -1;
            int randY = (Random.Range(-1, 1)) >= 0 ? 1 : -1;

            Vector3 spawnPos = transform.position + new Vector3(xScale * randX, yScale * randY);

            print(randX + " " + randY);

            Instantiate(spawnable, spawnPos, Quaternion.identity);

            yield return new WaitForSeconds(waitTime);
        }
    }
}
