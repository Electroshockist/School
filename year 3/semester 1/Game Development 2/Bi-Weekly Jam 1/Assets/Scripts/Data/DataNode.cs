using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public sealed class DataNode {
    public enum ValueType { NONE, INTERGER, FLOAT, VECTOR2 }
    private object value;
    private ValueType type;

    public void Assign(int v) {
        if (type == ValueType.NONE || type == ValueType.INTERGER || type == ValueType.FLOAT) {
            type = ValueType.INTERGER;
            value = v;
        }
    }

    public void Assign(float v) {
        if (type == ValueType.NONE || type == ValueType.INTERGER || type == ValueType.FLOAT) {
            type = ValueType.FLOAT;
            value = v;
        }
    }

    public void Assign(Vector2 v) {
        if (type == ValueType.NONE || type == ValueType.VECTOR2) {
            type = ValueType.VECTOR2;
            value = v;
        }
    }

    public static explicit operator int(DataNode node) {
        if (node.type == ValueType.INTERGER ||node.type == ValueType.FLOAT) {
            return (int)node.value;
        }
        else return 0;
    }

    public static explicit operator float(DataNode node) {
        if (node.type == ValueType.FLOAT || node.type == ValueType.FLOAT) {
            return (float)node.value;
        }
        else return 0;
    }

    public static explicit operator Vector2(DataNode node) {
        if (node.type == ValueType.NONE || node.type == ValueType.VECTOR2) {
            return (Vector2)node.value;
        }
        else return Vector2.zero;
    }
}
