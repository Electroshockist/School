using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Powerup : MonoBehaviour {

    private void OnTriggerEnter(Collider other) {
        if (other.tag == "Player") StartCoroutine(onPickup(other));
    }

    IEnumerator onPickup(Collider player) {
        player.GetComponent<Character>().speed *= 4f;

        GetComponent<MeshRenderer>().enabled = false;
        GetComponent<Collider>().enabled = false;

        yield return new WaitForSeconds(10);
        player.GetComponent<Character>().speed /= 4f;

        Destroy(this.gameObject);
    }


}
