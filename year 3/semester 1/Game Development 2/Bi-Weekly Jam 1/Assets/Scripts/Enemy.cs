using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy : MonoBehaviour {
    // Start is called before the first frame update
    void Start() {
        GetComponent<InputTransformDeltaToVector2>().target = GameObject.Find("Player").transform;
    }

    private void OnTriggerEnter2D(Collider2D collision) {
        if(collision.tag == "Player") {
            print("Player");
            collision.GetComponent<Player>().kill();
        }
        else if(collision.tag == "Bullet") {
            Destroy(collision.gameObject);
            Destroy(gameObject);
        }
    }
}
