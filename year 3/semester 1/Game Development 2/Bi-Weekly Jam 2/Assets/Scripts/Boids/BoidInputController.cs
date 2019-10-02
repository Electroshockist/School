using System.Collections;
using UnityEngine;

public class BoidInputController : MonoBehaviour {
    [SerializeField] float maxSpeed;
    [SerializeField] float maxForce;

    [SerializeField] float pollTime;

    [Header("Align Input")]
    [SerializeField] BoidAlign align = new BoidAlign();

    [Header("Avoid Input")]
    [SerializeField] BoidAvoid avoid = new BoidAvoid();

    [Header("Cohere Input")]
    [SerializeField] BoidCohere cohere = new BoidCohere();

    [Header("References")]
    [SerializeField] private Data data;
    // Start is called before the first frame update
    void Start() {
        align.Init(gameObject, maxSpeed, maxForce);
        avoid.Init(gameObject, maxSpeed, maxForce);
        cohere.Init(gameObject, maxSpeed, maxForce);

        align.Start(data);
        avoid.Start(data);
        cohere.Start(data);

        StartCoroutine(waitToPoll());
    }

    // Update is called once per frame
    void Update() {
        align.Update();
        avoid.Update();
        cohere.Update();
    }

    private IEnumerator waitToPoll() {
        align.pollOthers(transform.position);
        avoid.pollOthers(transform.position);
        cohere.pollOthers(transform.position);

        yield return new WaitForSeconds(pollTime);

        StartCoroutine(waitToPoll());
    }
}
