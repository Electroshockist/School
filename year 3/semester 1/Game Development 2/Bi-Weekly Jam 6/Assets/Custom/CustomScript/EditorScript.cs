using UnityEditor;
using UnityEditorInternal;
using UnityEngine;

[CustomEditor(typeof(EditorDemo))]
public class EditorScript : Editor {
    private EditorDemo demo;

    private ReorderableList gameObjects;

    private void OnEnable() {
        demo = (EditorDemo)target;

        if(gameObjects == null) {
            gameObjects = new ReorderableList(serializedObject,
                serializedObject.FindProperty("gameObjects"),
                true, true, true, true);
        }

        gameObjects.drawHeaderCallback += DrawColourHeader;
        gameObjects.drawElementCallback += DrawColourElement;
        gameObjects.onAddCallback += AddColourElement;
        gameObjects.onRemoveCallback += RemoveColourElement;
    }

    private void OnDisable() {
        gameObjects.drawHeaderCallback -= DrawColourHeader;
        gameObjects.drawElementCallback -= DrawColourElement;
        gameObjects.onAddCallback -= AddColourElement;
        gameObjects.onRemoveCallback -= RemoveColourElement;
    }

    private void DrawHeader(Rect rect, string label) {
        GUI.Label(rect, label);
    }

    private void DrawColourHeader(Rect rect) {
        DrawHeader(rect, "Colours");
    }

    private void DrawColourElement(Rect rect, int index, bool active, bool focused) {
        SerializedProperty element = gameObjects.serializedProperty.GetArrayElementAtIndex(index);
        EditorGUI.PropertyField(rect, element);
    }

    private void AddColourElement(ReorderableList list) {
        demo.addGameObject(null);
        EditorUtility.SetDirty(target);
    }

    private void RemoveColourElement(ReorderableList list) {
        if(demo.GameObjects[list.index] != null && demo.GameObjects[list.index].name == "New Game Object")
            DestroyImmediate(demo.GameObjects[list.index]);
        demo.GameObjects.RemoveAt(list.index);
        EditorUtility.SetDirty(target);
    }

    public override void OnInspectorGUI() {
        base.OnInspectorGUI();

        gameObjects.DoLayoutList();

        serializedObject.ApplyModifiedProperties();
    }
}
