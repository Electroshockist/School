using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraBehaviour : MonoBehaviour
{
    public bool isIncreasing = true;

    public Vector3 lowerOffset;
    public Vector3 upperOffset;
    public float timeToRotate = 30;
    public float currentTime = 15;

    public float offsetFromGJKComplexity = 1;
    public GJKManager gjkManager;

    // Update is called once per frame
    private Vector3 velocity;
    void Update()
    {

    }
}
