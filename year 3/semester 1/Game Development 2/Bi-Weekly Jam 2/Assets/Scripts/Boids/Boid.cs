using System.Collections;
using UnityEngine;


public class Boid : MonoBehaviour {
    [SerializeField] private float avoidRadius, followRadius, alignStrength;
    [SerializeField] private Vector2 target;

    private RaycastHit2D rayHits;

    // Start is called before the first frame update
    void Start() {

    }

    // Update is called once per frame
    void Update() {

    }

    IEnumerator pollOthers() {
        Physics2D.CircleCastAll(transform.position,followRadius,);
        yield return new WaitForSeconds(0.5f);
        StartCoroutine(pollOthers());
    }
}
