using System.Collections.Generic;
using UnityEngine;

public class DataInputController : MonoBehaviour {
    [Header("Keys")]
    [SerializeField] private List<DataInputKey> keys = new List<DataInputKey>();
    public DataInputKey GetKey(string name) { return keys.Find(key => key.Name == name); }

    [Header("KeysSticks")]
    [SerializeField] private List<DataInputKeyStick> keySticks = new List<DataInputKeyStick>();
    public DataInputKeyStick GetKeyStick(string name) { return keySticks.Find(stick => stick.Name == name); }

    [Header("KeyMice")]
    [SerializeField] private DataInputMouse mouseInput = new DataInputMouse();
    public DataInputMouse GetMouse(string name) { return mouseInput; }

    [Header("References")]
    [SerializeField] private Data data;

    // Start is called before the first frame update
    void Awake() {
        for(int i = keys.Count - 1; i >= 0; i--)
            keys[i].Start(data);
        for(int i = keySticks.Count - 1; i >= 0; i--)
            keySticks[i].Start(data);

        mouseInput.Start(data);
    }

    // Update is called once per frame
    void Update() {
        for(int i = keys.Count - 1; i >= 0; i--)
            keys[i].Update();
        for(int i = keySticks.Count - 1; i >= 0; i--)
            keySticks[i].Update();
        mouseInput.Update();
    }
}
