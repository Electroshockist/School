using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class Character : MonoBehaviour {

    Camera camera1;

    public CharacterController cc;

    //player controller variables
    public float speed, rotationSpeed, jumpSpeed, horizontalSpeedModifier, sprintSpeedModifier, gravity;


    Vector3 moveDirection = Vector3.zero;

    public Projectile projectilePrefab;
    public Transform projectileSpawnpoint;

    // Use this for initialization
    void Start () {
        if (speed <= 0) speed = 6.0f;

        if (rotationSpeed <= 0) rotationSpeed = 3.5f;

        if (jumpSpeed <= 0) jumpSpeed = 5.0f;

        if (gravity <= 0) gravity = 9.81f;

        if (horizontalSpeedModifier <= 0) horizontalSpeedModifier = 0.8f;


        //get player's camera
        camera1  = transform.Find("Main Camera").GetComponent<Camera>();
    }

    // Update is called once per frame
    void Update () {
        control();	
	}

    void control() {
        //rotation
        transform.Rotate(0, Input.GetAxis("Mouse X") * rotationSpeed, 0);
        camera1.transform.Rotate(Input.GetAxis("Mouse Y") * rotationSpeed, 0, 0);

        moveDirection.y -= gravity * Time.deltaTime;

        cc.Move(moveDirection * Time.deltaTime);

        moveDirection = new Vector3(Input.GetAxis("Horizontal") * horizontalSpeedModifier, 0, Input.GetAxis("Vertical"));

        //is on ground
        if (cc.isGrounded) {

            moveDirection = transform.TransformDirection(moveDirection);

            //movement
            moveDirection *= speed +  sprintSpeedModifier;
            if (Input.GetButtonDown("Jump")) {
                moveDirection.y = jumpSpeed;
            }
        }
        else {
            moveDirection.x /= 2;
            moveDirection.z /= 2;
        }

        //bullets
        if (Input.GetButtonDown("Fire1")) {
            fire();
        }
    }

    void fire() {
        if (projectilePrefab && projectileSpawnpoint)
            Instantiate(projectilePrefab, projectileSpawnpoint.position, projectileSpawnpoint.rotation);
    }
}
