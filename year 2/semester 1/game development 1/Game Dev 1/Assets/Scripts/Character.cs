using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class Character : MonoBehaviour {

    Camera camera1;

    CharacterController cc;

    public Projectile projectilePrefab;
    public Transform projectileSpawnpoint;

    //player controller variables
    public float accel, topSpeed, rotationSpeed, jumpSpeed, horizontalSpeedModifier, gravity;

    /*calculates as a percentage of speed.
     A value of 1 would be 200% as fast.*/
    public float sprintSpeedModifier;

    float cameraRotation;

    Vector3 moveDirection = Vector3.zero;


    // Use this for initialization
    void Start () {
        if (accel <= 0) accel = 1.0f;

        if (gravity <= 0) gravity = -9.81f;

        if (topSpeed <= 0) topSpeed = 60.0f;

        if (rotationSpeed <= 0) rotationSpeed = 3.5f;

        if (jumpSpeed <= 0) jumpSpeed = 0.1f;

        if (horizontalSpeedModifier <= 0) horizontalSpeedModifier = 0.8f;

        if (sprintSpeedModifier <= 0) sprintSpeedModifier = 0.5f;

        //get player's camera
        camera1  = transform.Find("Main Camera").GetComponent<Camera>();

        cc = GetComponent<CharacterController>();
    }

    // Update is called once per frame
    void Update () {
        control();	
	}

    void control() {

        rotation();

        motion();

        Debug.Log(cc.isGrounded);

        //jumping
        if (Input.GetButtonDown("Jump") && cc.isGrounded) {
            moveDirection.y = 0;
            moveDirection.y = jumpSpeed;
        }

        //sprinting
        //todo: animate camera fov
        if (Input.GetButtonDown("Sprint")) camera1.fieldOfView += 15;
        if (Input.GetButtonUp("Sprint")) camera1.fieldOfView -= 15;
        if (Input.GetButton("Sprint")) moveDirection.z = Input.GetAxis("Vertical") * accel + Input.GetAxis("Vertical") * accel * sprintSpeedModifier;
        else moveDirection.z = Input.GetAxis("Vertical") * accel; 

        //bullets
        if (Input.GetButtonDown("Fire1")) fire();
    }

    void rotation() {
        //body rotation
        transform.Rotate(0, Input.GetAxis("Mouse X") * rotationSpeed, 0);

        //clamped vertical camera rotation
        cameraRotation += Input.GetAxis("Mouse Y") * rotationSpeed;

        cameraRotation = Mathf.Clamp(cameraRotation, -90, 90);

        camera1.transform.localEulerAngles = new Vector3(-cameraRotation, transform.localEulerAngles.x, transform.localEulerAngles.z);
    }

    void motion() {
        moveDirection.x = Input.GetAxis("Horizontal") * accel * horizontalSpeedModifier;

        moveDirection.z = Input.GetAxis("Vertical") * accel + Input.GetAxis("Vertical");

        moveDirection = transform.TransformDirection(moveDirection);

        if(!cc.isGrounded) moveDirection.y += gravity * Time.deltaTime;

        cc.Move(moveDirection);
    }

    void fire() {
        if (projectilePrefab && projectileSpawnpoint) Instantiate(projectilePrefab, projectileSpawnpoint.position, projectileSpawnpoint.rotation);
    }
}
