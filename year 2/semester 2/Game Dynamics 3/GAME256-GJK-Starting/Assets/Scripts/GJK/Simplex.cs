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

    public Edge FindClosestEdge() {
        Edge edge = new Edge();

        Vector3 a = vertices[0];
        Vector3 b = vertices[1];

        Vector3 ab = b - a;

        Vector3 ao = -a;

        edge.normal = ab.TripleCross(ao).normalized;
        edge.distance = Vector3.Dot(ab,ao);
        edge.index = 1;

        for(int i = 1; i < vertices.Count; i++) {
            int j = (i + 1) % vertices.Count;

            a = vertices[i];
            b = vertices[j];

            ab = b - a;
            ao = -a;

            float distance = Vector3.Dot(ab, ao);
            if (distance < edge.distance) {
                edge.distance = distance;
                edge.normal = ab.TripleCross(ao);
                edge.index = j;
            }
        }
        return edge;
    }
}
