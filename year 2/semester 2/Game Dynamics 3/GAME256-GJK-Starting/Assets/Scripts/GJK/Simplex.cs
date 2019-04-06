using System;
using System.Collections.Generic;
using UnityEngine;

[Serializable]
public class Simplex {
    [Serializable]
    public struct SimplexDirection{
        Vector3 origin;
        Vector3 direction;
    };


    public List<Vector3> vertices = new List<Vector3>();
    public List<SimplexDirection> directions = new List<SimplexDirection>();
    public List<Vector3> supports = new List<Vector3>();

    public int Count {
        get { return vertices.Count; }
    }

    public Simplex Clone() {
        Simplex simplex = new Simplex {
            directions = new List<SimplexDirection>(directions.ToArray()),
            supports = new List<Vector3>(supports.ToArray()),
            vertices = new List<Vector3>(vertices.ToArray())
        };

        return simplex;
    }

    public Vector3 this[int i]
    {
        get { return vertices[i]; }
    }

    public void Add(Vector3 vertex)
    {
        vertices.Add(vertex);
    }

    public void Remove(Vector3 vertex)
    {
        vertices.Remove(vertex);
    }
}
