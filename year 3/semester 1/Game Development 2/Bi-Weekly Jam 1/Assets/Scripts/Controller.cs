using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Controller : MonoBehaviour {
    public abstract class InputComponent {
        public abstract void Gather(Data data);
        public abstract void Input();
    }
    public abstract class ControlComponent {
        public abstract void Gather(Data data);
        public abstract void Execute();
    }

    [Header("Inputs")]
    [SerializeField]
    List<InputComponent> inputs = new List<InputComponent>();

    [Header("Controls")]
    [SerializeField]
    List<ControlComponent> controls = new List<ControlComponent>();


    private Data data = new Data();
    // Start is called before the first frame update
    void Start() {

        InputComponent[] inputComponents = GetComponents<InputComponent>();
        for (int i = inputComponents.Length - 1; i >= 0; i--) {
            if (!inputs.Contains(inputComponents[i])) {
                inputs.Add(inputComponents[i]);
            }
        }

        ControlComponent[] controlComponents = GetComponents<ControlComponent>();
        for (int i = controlComponents.Length - 1; i >= 0; i--) {
            if (!controls.Contains(controlComponents[i])) {
                controls.Add(controlComponents[i]);
            }
        }

        foreach(InputComponent input in inputs) input.Gather(data);
        foreach(ControlComponent control in controls) control.Gather(data);
    }

    // Update is called once per frame
    void Update() {
        foreach (InputComponent input in inputs) input.Input();
        foreach (ControlComponent control in controls) control.Execute();
    }
}
