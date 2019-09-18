using UnityEngine;

public class InputPair : InputComponent {
    private int keyScalar = 0;
    private KeyCode currentActiveKey = KeyCode.None;

    public string dataName = "";

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
        if (UnityEngine.Input.GetKeyUp(currentActiveKey)) {
            currentActiveKey = KeyCode.None;
            keyScalar = 0;
        }

        if (UnityEngine.Input.GetKeyDown(positiveKey)) {
            currentActiveKey = positiveKey;
            keyScalar = 1;
        }

        if (UnityEngine.Input.GetKeyDown(negativeKey)) {
            currentActiveKey = negativeKey;
            keyScalar = -1;
        }

        print(currentActiveKey);

        return KeyScalar;
    }

    public override void Gather(Data data) {
        throw new System.NotImplementedException();
    }

    public override void Input() {
        throw new System.NotImplementedException();
    }
}
