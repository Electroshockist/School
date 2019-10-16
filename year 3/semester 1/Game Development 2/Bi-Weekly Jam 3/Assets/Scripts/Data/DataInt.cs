﻿using System;
using System.Collections.Generic;
using UnityEngine;

[Serializable]
public class DataInt : DataNode
{
    [SerializeField] private int value;

    public int Value {
        get {
            return value;
        }
        set { this.value = value; }

    }
}
