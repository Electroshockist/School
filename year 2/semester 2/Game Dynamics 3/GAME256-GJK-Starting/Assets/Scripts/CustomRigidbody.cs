using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CustomRigidbody : MonoBehaviour {

    [SerializeField]
    private Vector3 linA, linV, angA, angV;
    private Vector3 linD, angD;

    private void Start() {
        linD = transform.position;
        angD = transform.eulerAngles;
    }

    private void FixedUpdate() {
        transform.SetPositionAndRotation(Move(), Rotate());
    }

    Vector3 Move() {
        linV += linA * Time.deltaTime;
        linD += linV * Time.deltaTime;

        return linD;
    }

    Quaternion Rotate() {
        angV += angA * Time.deltaTime;
        angD += angV * Time.deltaTime;

        float cosYaw, sinYaw, cosPitch, sinPitch, cosRoll, sinRoll;
        cosYaw = Mathf.Cos(angD.x / 2);
        sinYaw = Mathf.Sin(angD.x / 2);
        cosPitch = Mathf.Cos(angD.y / 2);
        sinPitch = Mathf.Sin(angD.y / 2);
        cosRoll = Mathf.Cos(angD.z / 2);
        sinRoll = Mathf.Sin(angD.z / 2);

        float qX, qY, qZ, qW;
        qW = cosYaw * cosPitch * cosRoll + sinYaw * sinPitch * sinRoll;
        qX = cosYaw * cosPitch * sinRoll - sinYaw * sinPitch * cosRoll;
        qY = sinYaw * cosPitch * sinRoll + cosYaw * sinPitch * cosRoll;
        qZ = sinYaw * cosPitch * cosRoll - cosYaw * sinPitch * sinRoll;

        return new Quaternion(qX, qY, qZ, qW);
    }
}
