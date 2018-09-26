using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class Character : MonoBehaviour {

    public CharacterController cc;
    public float speed;
    public float rotationSpeed;
    public float jumpSpeed;
    public float gravity;
    Vector3 moveDirection = Vector3.zero;

    public Projectile projectilePrefab;
    public Transform projectileSpawnpoint;

    // Use this for initialization
    void Start () {
        if (speed <= 0) speed = 6.0f;

        if (rotationSpeed <= 0) rotationSpeed = 3.5f;

        if (jumpSpeed <= 0) jumpSpeed = 10.0f;

        if (gravity <= 0) gravity = 9.81f;
	}
	
	// Update is called once per frame
	void Update () {
        control();
        castRay();		
	}

    void control() {
        //rotation
        transform.Rotate(0, Input.GetAxis("Mouse X") * rotationSpeed, 0);

        moveDirection.y -= gravity * Time.deltaTime;

        cc.Move(moveDirection * Time.deltaTime);

        //is on ground
        if (cc.isGrounded) {
            moveDirection = new Vector3(0, 0, Input.GetAxis("Vertical"));

            moveDirection = transform.TransformDirection(moveDirection);

            //movement
            moveDirection *= speed;
            if (Input.GetButtonDown("Jump")) {
                moveDirection.y = jumpSpeed;
            }
        }

        //bullets
        if (Input.GetButtonDown("Fire1")) {
            fire();
        }
    }
    void castRay() {
        RaycastHit hit;
        Debug.DrawRay(transform.position, transform.forward * 5.0f, Color.red);
        if (Physics.Raycast(transform.position, transform.forward, out hit, 5.0f)) {
            Debug.Log("Raycast hit" + hit.collider.name);
        }
    }
    void fire() {
        Debug.Log("pew");
        if (projectilePrefab && projectileSpawnpoint)
            Instantiate(projectilePrefab, projectileSpawnpoint.position, projectileSpawnpoint.rotation);
    }
}
