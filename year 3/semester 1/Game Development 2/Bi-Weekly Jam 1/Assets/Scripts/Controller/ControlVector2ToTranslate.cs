using UnityEngine;

public class ControlVector2ToTranslate : ControlComponent {
    [Header("Speed")]
    [SerializeField] private float speed = 1;
    [Header("Data Node")]
    [SerializeField] private string dataName = "inputVector2";

    private DataNode cachedVector;
    public override void Gather(Data data) {
        cachedVector = data[dataName];
    }

    public override void Execute() {
        Vector2 tempVector = (Vector2)cachedVector;
        if (tempVector.magnitude > 1) {
            tempVector.Normalize();
        }

        transform.Translate(tempVector * speed);
    }
}
