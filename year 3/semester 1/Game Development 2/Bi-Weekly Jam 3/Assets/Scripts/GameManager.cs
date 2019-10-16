using UnityEngine;
using UnityEngine.UI;

public class GameManager : MonoBehaviour {

    Data data;
    [SerializeField]
    private Sprite empty, hidden, betray, cooperate;
    [SerializeField]
    private Image selectorRed, selectorBlue;
    [Header("Blue")]
    [SerializeField] DataBool blueBetray, blueSelected;
    [Header("Red")]
    [SerializeField] DataBool redBetray, redSelected;

    // Start is called before the first frame update
    void Start() {
    }

    private void onChoose() {

    }

    public void onBlueChoose() {
        blueSelected.Value = true;
    }

    public void onBlueBetray() {
        blueBetray.Value = true;
        onBlueChoose();
    }

    public void onRedChoose() {
        redSelected.Value = true;
    }

    public void onRedBetray() {
        redBetray.Value = true;
        onRedChoose();
    }

    private void reset() {
        setBlueEmpty();
        setRedEmpty();
    }


    void setBlueEmpty() {
        blueSelected.Value = false;
        blueBetray.Value = false;
        selectorBlue.sprite = empty;
    }

    void setRedEmpty() {
        redSelected.Value = false;
        redBetray.Value = false;
        selectorRed.sprite = empty;
    }

    void setBlueHidden() {
        blueSelected.Value = true;
    }

    void updateImages() {
        if (blueSelected.Value )
        if(blueSelected.Value) {
            selectorBlue.sprite = hidden;
        }
    }
}
