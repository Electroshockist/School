using UnityEditor;
using UnityEngine;
using UnityEngine.UIElements;
using System.Collections.Generic;

public class QuickTool : EditorWindow
{
    private static List<GameObject> prefabs = new List<GameObject>();

    [MenuItem("Quickbar/Open _%#T")]
    public static void ShowWindow()
    {
        GetPrefabs();
        QuickTool tool = GetWindow<QuickTool>();

        tool.titleContent = new GUIContent("Object Quick Create");
        tool.minSize = new Vector2(256, 64);
    }

    private void OnEnable()
    {
        VisualElement root = rootVisualElement;

        root.styleSheets.Add(Resources.Load<StyleSheet>("Quick_Style"));

        VisualTreeAsset tree = Resources.Load<VisualTreeAsset>("Quick_Main");
        tree.CloneTree(root);

        UQueryBuilder<Button> buttons = root.Query<Button>();
        buttons.ForEach(SetupButton);
    }

    private void SetupButton(Button button)
    {
        VisualElement icon = button.Q(className: "quicktool-button-icon");
        string path = "Icons/" + button.parent.name;
        Texture2D image = Resources.Load<Texture2D>(path);

        icon.style.backgroundImage = image;
        button.clickable.clicked += () => CreateObject(button.parent.name);
        button.tooltip = button.parent.name;
    }

    private void CreateObject(string type)
    {
        GameObject o;

        switch (type)
        {
            case "Mouse":
                o = Instantiate(GetPrefab("Mouse"));
                break;
            case "Cat":
                o = Instantiate(GetPrefab("Cat"));
                break;
            case "AfterImage":
                o = Instantiate(GetPrefab("AfterImage"));
                break;
            case "Beam":
                o = Instantiate(GetPrefab("Beam"));
                break;
            case "light":
                o = ObjectFactory.CreateGameObject("light", typeof(Light));
                break;
            case "object":
                o = ObjectFactory.CreateGameObject("object");
                break;
            default:
                o = ObjectFactory.CreatePrimitive(PrimitiveType.Cube);
                break;
        }

        o.transform.position = Vector3.zero;
        Selection.activeGameObject = o;
    }

    private static void GetPrefabs()
    {
        string[] search_results = System.IO.Directory.GetFiles("Assets/Quick/Editor/Resources/Prefabs/", "*.prefab", System.IO.SearchOption.AllDirectories);

        for (int i = 0; i < search_results.Length; i++)
        {
            Object prefab = null;
            prefab = AssetDatabase.LoadAssetAtPath(search_results[i], typeof(GameObject));
            prefabs.Add(prefab as GameObject);

            //Debug.Log(prefabs[i].name + " " + prefabs.Count);
        }
    }

    public static GameObject GetPrefab(string name)
    {
        foreach (GameObject g in prefabs)
        {
            if (g.name == name)
            {
                return g;
            }
        }

        return null;
    }
}
