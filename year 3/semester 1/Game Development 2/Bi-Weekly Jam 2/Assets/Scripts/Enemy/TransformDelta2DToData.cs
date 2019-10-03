using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TransformDelta2DToData : MonoBehaviour
{
    [Header("Data")]
    [SerializeField] private DataVector2 dataNode;
    [Header("References")]
    [SerializeField] private Transform target;
    [SerializeField] private Data data;

    // Start is called before the first frame update
    void Start()
    {
        dataNode = data.Vector2(dataNode);
    }

    // Update is called once per frame
    void Update()
    {
        dataNode.Value = (target.position - transform.position).normalized;
    }
}
