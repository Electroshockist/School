using UnityEngine;

public class Astronaut2 : MonoBehaviour {
    public float speed = 10;
    public float angularSpeed = 10;

    public GameObject model;
    public GameObject bullet;
    public Transform gun;

    float bulletTimer = 0;
    float bulletCoolDown = 1;
    // Use this for initialization
    void Start() {

    }

    // Update is called once per frame
    void Update() {
        float dt = Time.deltaTime;

        /*
                float translation = Input.GetAxis("Vertical") * speed;
                float rotation = Input.GetAxis("Horizontal") * angularSpeed;

                translation *= dt;
                rotation *= dt;
                transform.Translate(0, 0, translation);
                transform.Rotate(0, rotation, 0);
        */

        float translation = Input.GetAxis("Vertical") * speed;
        float rotation = Input.GetAxis("Horizontal") * angularSpeed;

        translation *= dt;
        rotation *= dt;
        transform.eulerAngles = new Vector3(transform.eulerAngles.x, transform.eulerAngles.y + rotation, transform.eulerAngles.z);

        transform.position += transform.forward * -translation;



        bulletTimer -= dt;
        if(Input.GetKeyDown(KeyCode.Space)) {
            if(bulletTimer < 0) {
                Debug.Log("Fire");
                bulletTimer = bulletCoolDown;
                Instantiate(bullet, gun.position, gun.transform.rotation);
            }
        }

    }
}
