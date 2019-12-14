using System;
using System.Collections.Generic;
using UnityEngine;

public class EditorDemo : MonoBehaviour {
    [SerializeField, HideInInspector] List<GameObject> gameObjects;

    public List<GameObject> GameObjects {
        get => gameObjects;
    }
    // Start is called before the first frame update
    void Start() {

    }

    // Update is called once per frame
    void Update() {

    }

    public void addGameObject(GameObject gameObject) {
        gameObjects.Add(gameObject);
    }
}
