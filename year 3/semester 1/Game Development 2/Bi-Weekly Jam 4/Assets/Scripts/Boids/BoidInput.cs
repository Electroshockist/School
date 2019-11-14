using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BoidInput : DataInput {
    protected GameObject self;
    protected float maxSpeed, maxForce;

    [Header("Data")]
    [SerializeField] protected float radius, strength = 1;
    [SerializeField] protected DataVector2 dataNode;

    protected List<GameObject> boids = new List<GameObject>();

    public void Init(GameObject self,float maxSpeed, float maxForce) {
        this.self = self;
        this.maxSpeed = maxSpeed;
        this.maxForce = maxForce;
    }

    public override void Start(Data data) {
        if (data.Has(dataNode))
            dataNode = data.GetVector2(dataNode.Name);
        else
            data.Add(dataNode);
    }

    public override void Update() {
    }

    public void pollOthers(Vector3 pos) {
        RaycastHit2D[] hits = Physics2D.CircleCastAll(pos, radius, Vector2.zero);
        boids.Clear();

        for (int i = 0; i < hits.Length; i++) {
            if (hits[i].collider.gameObject.GetComponent<BoidInputController>()) {
                if (hits[i].collider.gameObject != self) {
                    boids.Add(hits[i].collider.gameObject);
                }
            }
        }
    }
}
