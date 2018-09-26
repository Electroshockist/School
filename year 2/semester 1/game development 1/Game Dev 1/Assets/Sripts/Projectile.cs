using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Projectile : MonoBehaviour {
    public float projectileLifetime, projectileForce;
    Rigidbody rb;

	// Use this for initialization
	void Start () {
        if (projectileLifetime <= 0) projectileLifetime = 5.0f;
        if (projectileForce <= 0) projectileForce = 10.0f;

        rb = GetComponent<Rigidbody>();
        if (!rb) rb = gameObject.AddComponent<Rigidbody>();

        rb.AddForce(transform.forward * projectileForce, ForceMode.Impulse);

        Destroy(gameObject, projectileLifetime);
		
	}
}
