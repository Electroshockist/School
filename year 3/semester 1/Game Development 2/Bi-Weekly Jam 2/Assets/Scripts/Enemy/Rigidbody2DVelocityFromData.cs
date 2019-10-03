using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Rigidbody2DVelocityFromData : MonoBehaviour
{
    [Header("Data")]
    [SerializeField] private DataFloat dataSpeed;
    [SerializeField] private DataVector2 dataInput;
    [Header("References")]
    [SerializeField] private Data data;
    [SerializeField] private Rigidbody2D rigidbody;

    // Start is called before the first frame update
    void Start()
    {
        dataSpeed = data.Float(dataSpeed);
        dataInput = data.Vector2(dataInput);
    }

    // Update is called once per frame
    void Update()
    {
        rigidbody.velocity = dataInput.Value * dataSpeed.Value;
    }
}
