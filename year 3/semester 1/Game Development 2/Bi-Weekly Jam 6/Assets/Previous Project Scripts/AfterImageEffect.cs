using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AfterImageEffect : MonoBehaviour
{
    public GameObject parent;
    public float timer;

    private float tempTimer;
    private int imageIterator;

    public GameObject afterImagePrefab;
    public GameObject[] afterImages;

    // Start is called before the first frame update
    void Start()
    {

        tempTimer = timer;
        imageIterator = 0;

        for(int i = afterImages.Length - 1; i >= 0; i--)
        {
            afterImages[i] = Instantiate(afterImagePrefab, parent.transform.position, parent.transform.rotation);
        }
    }

    // Update is called once per frame
    void Update()
    {
        if (imageIterator >= afterImages.Length - 1)
        {
            imageIterator = 0;
        }


        if (tempTimer <= 0)
        {
            tempTimer = timer;
            
            afterImages[imageIterator].GetComponent<SpriteRenderer>().sprite = parent.gameObject.GetComponent<SpriteRenderer>().sprite;
            afterImages[imageIterator].transform.rotation = parent.transform.rotation;
            afterImages[imageIterator].transform.position = parent.gameObject.transform.position;
            //afterImages[imageIterator].gameObject.GetComponent<Animator>().SetBool("isTransparent", false);
            imageIterator++;
        }
        else
        {
           //afterImages[imageIterator].gameObject.GetComponent<Animator>().SetBool("isTransparent", true);
            tempTimer -= Time.deltaTime;
        }
    }
}
