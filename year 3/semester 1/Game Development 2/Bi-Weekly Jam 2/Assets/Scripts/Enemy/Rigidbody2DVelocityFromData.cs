using UnityEngine;

public class Rigidbody2DVelocityFromData : MonoBehaviour {
    [Header("Data")]
    [SerializeField] private DataFloat dataSpeed;
    [SerializeField] private DataVector2 dataInput;
    [Header("References")]
    [SerializeField] private Data data;
    [SerializeField] private Rigidbody2D rigidbody;
    private Nexus nexus;

    // Start is called before the first frame update
    void Start() {

        nexus = GameObject.Find("Nexus").GetComponent<Nexus>();
        dataSpeed = data.Float(dataSpeed);
        dataInput = data.Vector2(dataInput);
    }

    // Update is called once per frame
    void Update() {
        if (!nexus.lost()) {
            rigidbody.velocity = dataInput.Value * dataSpeed.Value;
        }
        else {
            rigidbody.velocity = Vector2.zero;
            transform.eulerAngles = new Vector3(0, 0, transform.eulerAngles.z + 5.0f);
        }
    }
}
