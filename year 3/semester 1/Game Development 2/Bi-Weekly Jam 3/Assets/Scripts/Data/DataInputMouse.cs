using UnityEngine;
using UnityEngine.Events;
using System;

[Serializable]
public class DataInputMouse : DataInput {
    [Header("Data")]
    [SerializeField] public DataVector2 dataNode;
    [Header("Events")]
    [SerializeField] private UnityEvent onMouseMove;

    public override void Start(Data data) {
        if(data.Has(dataNode))
            dataNode = data.GetVector2(dataNode.Name);
        else
            data.Add(dataNode);
    }

    public override void Update() {
        dataNode.Value = Vector2.zero;

        if(dataNode.Value != new Vector2(Input.mousePosition.x, Input.mousePosition.y)) {
            onMouseMove.Invoke();
            dataNode.Value = Input.mousePosition;
        }
    }
}
