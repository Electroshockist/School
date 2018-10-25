using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Projectile : MonoBehaviour {
    public float projectileLifetime, projectileForce;
    Rigidbody rb;
    Rigidbody rootRb;

	// Use this for initialization
	void Start () {
        rootRb = GameObject.Find("Character").GetComponent<Rigidbody>();

        if (projectileLifetime <= 0) projectileLifetime = 5.0f;
        if (projectileForce <= 0) projectileForce = 10.0f;

        rb = GetComponent<Rigidbody>();
        if (!rb) rb = gameObject.AddComponent<Rigidbody>();

        rb.AddForce(transform.forward * projectileForce + rootRb.velocity, ForceMode.Impulse);

        Destroy(gameObject, projectileLifetime);		
	}
}
