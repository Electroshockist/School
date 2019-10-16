using System;
using UnityEngine;

[Serializable]
public class DataBool : DataNode {
    [SerializeField] private bool value;


    public bool Value {
        get {
            return value;
        }
        set { this.value = value; }
    }
}
