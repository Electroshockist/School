using System;
using System.Reflection;
using UnityEditor;
using UnityEngine;

[CustomPropertyDrawer(typeof(Color))]
public class ColourDrawer : PropertyDrawer {
    static string[] choices = new[] {
        "black",
        "white",
        "cyan",
        "clear",
        "gray",
        "magenta",
        "red",
        "yellow",
        "green",
        "blue",
        "Pick a colour"
    };

    static Color[] colors = new[] {
        Color.black,
        Color.white,
        Color.cyan,
        Color.clear,
        Color.gray,
        Color.magenta,
        Color.red,
        Color.yellow,
        Color.green,
        Color.blue
    };


    int choiceIndex = 10;

    int prevIndex = 10;

    public override float GetPropertyHeight(SerializedProperty property, GUIContent label) {
        //return base.GetPropertyHeight(property, label);
        return EditorGUIUtility.singleLineHeight;
    }

    public override void OnGUI(Rect position, SerializedProperty property, GUIContent label) {
        EditorGUI.BeginProperty(position, label, property);

        Color c = getValue(property);

        int indent = EditorGUI.indentLevel;
        EditorGUI.indentLevel = 0;

        Rect pos = new Rect(position.x, position.y, position.width, position.height);

        c = getColour();

        property.colorValue = c;

        choiceIndex = EditorGUI.Popup(pos, label.text + ": ", choiceIndex, choices);

        if(!onIndexChange()  && choiceIndex != 10) updateText(c);


        //property.serializedObject. = (SerializedObject)c;

        EditorGUI.indentLevel = indent;

        EditorGUI.EndProperty();
    }

    private Color getColour() {
        if(choiceIndex < colors.Length) {
            return colors[choiceIndex];
        }

        return Color.white;
    }

    private void updateText(Color c) {
        for(int i = colors.Length - 1; i >= 0; i--) {
            if(colors[i] == c) {
                setIndex(i);
            }
        }
    }

    private Color getValue(SerializedProperty property) {
        UnityEngine.Object o = property.serializedObject.targetObject;

        Type t = o.GetType();

        FieldInfo f = t.GetField(property.propertyPath);

        if(f != null) {
            return (Color)f.GetValue(o);
        }

        return Color.white;
    }

    private void setIndex(int index) {
        prevIndex = choiceIndex;
        choiceIndex = index;
    }

    private bool onIndexChange() {
        bool t = prevIndex != choiceIndex;

        prevIndex = choiceIndex;

        return t;
    }


}
