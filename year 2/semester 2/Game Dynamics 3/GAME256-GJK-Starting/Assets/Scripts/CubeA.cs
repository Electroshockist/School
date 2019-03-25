using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(CustomRigidbody))]
public class CubeA : MonoBehaviour {
    CustomRigidbody rb;
    float totaltime = 0;

    // Start is called before the first frame update
    void Start() {
        rb = GetComponent<CustomRigidbody>();        
    }

    // Update is called once per frame
    void Update() {
        totaltime += Time.deltaTime;
        rb.linear.V.x = 3 * Mathf.Sin(totaltime);
        rb.linear.V.y = 3 * Mathf.Cos(totaltime);
    }
}
