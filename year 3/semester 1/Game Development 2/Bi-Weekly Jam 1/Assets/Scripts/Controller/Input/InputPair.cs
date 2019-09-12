using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class InputPair : MonoBehaviour {
    private int keyScalar = 0;
    private KeyCode currentActiveKey = KeyCode.None;

    public int KeyScalar {
        get { return keyScalar; }
    }
    public KeyCode CurrentActiveKey {
        get { return currentActiveKey; }
    }

    [Header("Keys")]
    [SerializeField] private KeyCode positiveKey;
    [SerializeField] private KeyCode negativeKey;

    public int UpdateKeys() {
        if (Input.GetKeyUp(currentActiveKey)) {
            currentActiveKey = KeyCode.None;
            keyScalar = 0;
        }

        if (Input.GetKeyDown(positiveKey)) {
            currentActiveKey = positiveKey;
            keyScalar = 1;
        }

        if (Input.GetKeyDown(negativeKey)) {
            currentActiveKey = negativeKey;
            keyScalar = -1;
        }

    }
}
