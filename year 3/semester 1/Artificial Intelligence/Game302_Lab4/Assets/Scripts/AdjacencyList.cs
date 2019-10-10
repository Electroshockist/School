using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AdjacencyList : MonoBehaviour {
    public GameObject[] nodes;
    //int[,] graph =
    //{
    //           //A, B, C, D, E
    //    /* A */{ 0, 1, 0, 0, 1 },
    //    /* B */{ 1, 0, 0, 0, 1 },
    //    /* C */{ 0, 0, 0, 0, 1 },
    //    /* D */{ 0, 0, 0, 0, 1 },
    //    /* E */{ 1, 1, 1, 1, 0 }
    //};
    List<int>[] adjacencyList;
    void Start()
    {
        // create an adjacencyList as List<int>[]
        adjacencyList = new List<int>[5];
        // create a list to contain the connected nodes
        adjacencyList[0] = new List<int>();
        adjacencyList[0].Add(1); // connects B(index=1) to A
        adjacencyList[0].Add(4); // connects E(index=4) to A

        // To do: set adjacencyList for the node B (index=1) to connect to A(index=0) and E(index=4)
        

        // To do: set adjacencyList for the node C to connect to E
        

        // To do: set adjacencyList for the node D to connect to E
        

        // To do: set adjacencyList for the node E to connect to A, B, C and D
        
    }
    
    // Update is called once per frame
    void Update()
    {
        for (int i = 0; i < adjacencyList.GetLength(0); i++)
        {
            foreach (int connectedNode in GetConnectedNodes(i))
            {
                Debug.DrawLine(nodes[i].transform.position, nodes[connectedNode].transform.position);
            }
        }
    }

    List<int> GetConnectedNodes(int fromNode)
    {
        List<int> connectedNodes = null;
        // To do: Get the connected node list from adjacencyList
        connectedNodes = adjacencyList[fromNode];        

        return connectedNodes;
    }
}
