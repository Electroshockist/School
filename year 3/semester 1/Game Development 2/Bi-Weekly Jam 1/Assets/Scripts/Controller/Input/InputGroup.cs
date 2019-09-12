using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class InputGroup : MonoBehaviour {

    private KeyCode currentActiveKey;

    public KeyCode CurrentActiveKey {
        get { return currentActiveKey; } 
    }

    [Header("Keys")]
    [SerializeField] private KeyCode[] keycodes;

    public void UpdateKeys() {
        if (Input.GetKeyUp(currentActiveKey)) currentActiveKey = KeyCode.None;
        for (int i = keycodes.Length; i >=0; i--) {
            if (Input.GetKeyDown(keycodes[i])) {
                currentActiveKey = keycodes[i];
            }
        }

    }
}
