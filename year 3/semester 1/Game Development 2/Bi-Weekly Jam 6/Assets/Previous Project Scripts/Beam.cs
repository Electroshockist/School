using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

public class Beam : MonoBehaviour
{
    public float angle;
    public Vector3 dir;
    public Vector3 velocity;
    public float timer;
    public Rigidbody2D rigid;

    // Start is called before the first frame update
    void Start(){
        rigid = GetComponent<Rigidbody2D>();
    }

    // Update is called once per frame
    void Update()
    {
        timer -= Time.deltaTime;
        if (timer <= 0) {
            Destroy(gameObject);
        }
        
        rigid.velocity = velocity;

    }

    public void SetVelocity(float angle_, float speed_) {
        this.transform.Rotate(new Vector3(0.0f, 0.0f, angle_));
        dir = new Vector2(speed_ * Mathf.Cos(angle_ * Mathf.Deg2Rad), speed_ * Mathf.Sin(angle_ * Mathf.Deg2Rad));
        velocity = new Vector3(dir.x, dir.y, 0);
    }

}
