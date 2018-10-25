using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class Character : MonoBehaviour {

    Camera camera1;

    public Rigidbody rb;

    public Projectile projectilePrefab;
    public Transform projectileSpawnpoint;

    //player controller variables
    public float speed, topSpeed, rotationSpeed, jumpForce, horizontalSpeedModifier;

    /*calculates as a percentage of speed.
     A value of 100 would be 200% as fast.*/
    public float sprintSpeedModifier;

    float cameraRotation;

    Vector3 moveDirection = Vector3.zero;


    // Use this for initialization
    void Start () {
        if (speed <= 0) speed = 60.0f;

        if (rotationSpeed <= 0) rotationSpeed = 3.5f;

        if (jumpForce <= 0) jumpForce = 50.0f;

        if (horizontalSpeedModifier <= 0) horizontalSpeedModifier = 0.8f;

        if (sprintSpeedModifier <= 0) sprintSpeedModifier = 0.5f;

        //get player's camera
        camera1  = transform.Find("Main Camera").GetComponent<Camera>();
    }

    // Update is called once per frame
    void Update () {
        control();	
	}

    void control() {
        //body rotation
        transform.Rotate(0, Input.GetAxis("Mouse X") * rotationSpeed, 0);

        //clamped vertical camera rotation
        cameraRotation += Input.GetAxis("Mouse Y") * rotationSpeed;

        cameraRotation = Mathf.Clamp(cameraRotation, -90, 90);

        camera1.transform.localEulerAngles = new Vector3(-cameraRotation, transform.localEulerAngles.x, transform.localEulerAngles.z );

        moveDirection.x = Input.GetAxis("Horizontal") * speed * horizontalSpeedModifier;

        rb.velocity += moveDirection * Time.deltaTime;

        //jumping
        if (Input.GetButtonDown("Jump")) rb.AddForce(0, jumpForce, 0);

        //sprinting
        //todo: animate camera fov
        if (Input.GetButtonDown("Sprint")) camera1.fieldOfView += 15;
        if (Input.GetButtonUp("Sprint")) camera1.fieldOfView -= 15;
        if (Input.GetButton("Sprint")) {
            moveDirection.z = Input.GetAxis("Vertical") * speed + Input.GetAxis("Vertical") * speed * sprintSpeedModifier;
            Debug.Log(camera1.fieldOfView);
        }
        else moveDirection.z = Input.GetAxis("Vertical") * speed;
        
        moveDirection = transform.TransformDirection(moveDirection);
        

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
