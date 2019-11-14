using UnityEngine;

public class Enemy : MonoBehaviour {
    [SerializeField] private int damage;
    // Start is called before the first frame update
    void Start() {

    }

    // Update is called once per frame
    void Update() {

    }
    private void OnTriggerEnter2D(Collider2D collision) {
        if(collision.tag == "Nexus") {
            collision.gameObject.GetComponent<Nexus>().damage(damage);
        }
        Destroy(gameObject);
    }
}
