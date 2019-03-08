using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ToggleBackground : MonoBehaviour
{
    public Image background;

    public void ValueChanged(bool toggleState)
    {
        background.color = toggleState ? Color.clear : Color.white;
    }
}
