using UnityEngine;

public class BulletInput : InputComponent {

    [Header("Data Node")]
    [SerializeField] private string dataName = "inputVector2";

    public Vector2 tempVector = Vector2.zero;

    private DataNode cachedVector;

    public override void Gather(Data data) {
        data[dataName] = cachedVector = new DataNode();
    }

    public override void Input() {
        cachedVector.Assign(tempVector);
    }

    public void setVector(Vector2 v) {
        tempVector = v;
        print(v);
    }
}
