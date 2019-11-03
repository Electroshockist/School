using System.Collections;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour {
    // Update is called once per frame
    public Missle missle;
    void Update() {
        if(missle.isPlayerControlled) {
            if(Input.GetKey(KeyCode.LeftArrow)) {
                missle.velocity = new Vector3(-3, 0, 0);
            }
            else if(Input.GetKey(KeyCode.RightArrow)) {
                missle.velocity = new Vector3(3, 0, 0);
            }
            else {
                missle.velocity = Vector3.zero;
            }

            if(Input.GetKey(KeyCode.Space)) {
                missle.isPlayerControlled = false;
            }
        }

    }

}
