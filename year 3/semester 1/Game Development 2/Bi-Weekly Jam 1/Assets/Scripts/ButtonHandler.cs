using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class ButtonHandler : MonoBehaviour{

    public void onPLay() {
        SceneManager.LoadScene("Game");
    }
    public void onQuit() {
        print("quit");
        Application.Quit();
    }
}
