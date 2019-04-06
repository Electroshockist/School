using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

[RequireComponent(typeof(Slider))]
public class CustomSlider : MonoBehaviour
{
    public Slider slider;
    public bool isEnabled;

    public float Value {
        get {
            return slider.value;
        }
        set {
            slider.value = value;
        }
    }
    // Start is called before the first frame update
    void Start() {
        slider = GetComponent<Slider>();
        isEnabled = false;
    }

    public void Enable() {
        isEnabled = true;
    }

    public void Disable() {
        isEnabled = false;
    }
}
