using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System;

public class UI : MonoBehaviour
{
    public CustomSlider min, max;

    private void Start() {
        max.Value = 1;
    }

    // Update is called once per frame
    void Update() {
        if (min.isEnabled) {
            if (max.Value < min.Value) max.Value = min.Value;
        }
        if (max.isEnabled) {
            if (min.Value > max.Value) min.Value = max.Value;
        }
    }

    public void SetVisibleSimplecies(GJKManager GJK) {
        GJKManager.minVisibleSimplex = Mathf.RoundToInt((GJK.state.simplices.Count) * min.Value);
        GJKManager.maxVisibleSimplex = Mathf.RoundToInt((GJK.state.simplices.Count) * max.Value);
    }

}
