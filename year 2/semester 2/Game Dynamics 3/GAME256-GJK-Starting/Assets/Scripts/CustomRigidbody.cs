using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CustomRigidbody : MonoBehaviour {
    [Serializable]
    public struct Linear {
        public Vector3 A, V, D;
    }
    [Serializable]
    public struct Angular {
        public Vector3 A, V, D;
    }

    public Linear linear;
    public Angular angular;

    private void Start() {
        linear.D = transform.position;
        angular.D = transform.eulerAngles;
    }

    private void FixedUpdate() {
        transform.SetPositionAndRotation(Move(), Rotate());
    }

    Vector3 Move() {
        linear.V += linear.A * Time.deltaTime;
        linear.D += linear.V * Time.deltaTime;

        return linear.D;
    }

    Quaternion Rotate() {
        angular.V += angular.A * Time.deltaTime;
        angular.D += angular.V * Time.deltaTime;

        float cosYaw, sinYaw, cosPitch, sinPitch, cosRoll, sinRoll;
        cosYaw = Mathf.Cos(angular.D.x / 2);
        sinYaw = Mathf.Sin(angular.D.x / 2);
        cosPitch = Mathf.Cos(angular.D.y / 2);
        sinPitch = Mathf.Sin(angular.D.y / 2);
        cosRoll = Mathf.Cos(angular.D.z / 2);
        sinRoll = Mathf.Sin(angular.D.z / 2);

        float qX, qY, qZ, qW;
        qW = cosYaw * cosPitch * cosRoll + sinYaw * sinPitch * sinRoll;
        qX = cosYaw * cosPitch * sinRoll - sinYaw * sinPitch * cosRoll;
        qY = sinYaw * cosPitch * sinRoll + cosYaw * sinPitch * cosRoll;
        qZ = sinYaw * cosPitch * cosRoll - cosYaw * sinPitch * sinRoll;

        return new Quaternion(qX, qY, qZ, qW);
    }
}
