using UnityEngine;

public class BoidController : MonoBehaviour {

    [SerializeField] private float acceleration, maxVelocity;
    [Header("Data")]
    [SerializeField] DataVector2 align;
    [SerializeField] DataVector2 avoid;
    [SerializeField] DataVector2 cohere;

    [Header("References")]
    [SerializeField] private Data data;
    [SerializeField] private Rigidbody2D rigidbody;
    // Start is called before the first frame update
    void Start() {
        align = data.Vector2(align);
        avoid = data.Vector2(avoid);
        cohere = data.Vector2(cohere);
    }

    // Update is called once per frame
    void Update() {
        Vector2 input = Vector3.zero;
        input += avoid.Value;
        input += align.Value;
        input += cohere.Value;


        //get mousepos
        Vector3 tempPos = new Vector3(Input.mousePosition.x, Input.mousePosition.y, 10);
        tempPos = Camera.main.ScreenToWorldPoint(tempPos);
        Vector2 mousePos = new Vector2(tempPos.x, tempPos.y);
        Vector2 pos = new Vector2(transform.position.x, transform.position.y);
        input += (mousePos - pos).normalized;
        input.Normalize();

        rigidbody.velocity += input * acceleration * Time.deltaTime;

        float angle = Mathf.Acos(Vector3.Dot(rigidbody.velocity.normalized, Vector3.up));

        transform.eulerAngles = new Vector3(0, 0, Mathf.Rad2Deg * angle * (rigidbody.velocity.x > 0 ? -1 : 1));
    }
}
