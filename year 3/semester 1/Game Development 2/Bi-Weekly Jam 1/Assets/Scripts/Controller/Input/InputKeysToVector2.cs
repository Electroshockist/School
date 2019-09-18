using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class InputKeysToVector2 : InputComponent {
    [Header("Keys")]
    [SerializeField] private KeyCode up = KeyCode.W;
    [SerializeField] private KeyCode down = KeyCode.S;
    [SerializeField] private KeyCode left = KeyCode.A;
    [SerializeField] private KeyCode right = KeyCode.D;
    [Header("Data Node")]
    [SerializeField] private string dataName = "inputVector2";

    private DataNode cachedVector;

    public override void Gather(Data data) {
        data[dataName] = cachedVector = new DataNode();
    }

    public override void Input() {
        Vector2 v2 = Vector2.zero;

        if (UnityEngine.Input.GetKey(up))
            v2.y += 1;
        if (UnityEngine.Input.GetKey(down))
            v2.y = -1;
        if (UnityEngine.Input.GetKey(right))
            v2.x += 1;
        if (UnityEngine.Input.GetKey(left))
            v2.x = -1;
;

        v2.Normalize();

        cachedVector.Assign(v2);
    }
}
