using UnityEngine;
using System.Collections;

[RequireComponent(typeof(CharacterController))]
[RequireComponent(typeof(Animator))]
public class Character : MonoBehaviour {

    public float speed;
    public float jumpSpeed;
    public float rotateSpeed;

    float gravity = 9.8f;
    Vector3 moveDirection = Vector3.zero;

    Animator anim;
    CharacterController cc;

    // Converts and stores animator states to a numerical value
    int idleState = Animator.StringToHash("Base Layer.Idle");
    int walkState = Animator.StringToHash("Base Layer.Walking");
    int deathState = Animator.StringToHash("Base Layer.Death");


    // Animation state info using to find out what state the animator is in
    AnimatorStateInfo currentBaseState;


    // Stores references to all clips in Animator
    AnimatorClipInfo[] currentClipInfo;

    // Use this for initialization
    void Start () {
        Debug.Log(Physics.gravity);
        if(speed <= 0)
        {
            speed = 6.0f;
            Debug.Log("speed not set on " + name + ". Defaulting to " + speed);
        }

        if (jumpSpeed <= 0)
        {
            jumpSpeed = 8.0f;
            Debug.Log("jumpSpeed not set on " + name + ". Defaulting to " + jumpSpeed);
        }

        if (rotateSpeed <= 0)
        {
            rotateSpeed = 5.0f;
            Debug.Log("rotateSpeed not set on " + name + ". Defaulting to " + rotateSpeed);
        }

        anim = GetComponent<Animator>();
        if(!anim)
        {
            Debug.Log("No Animator Found on " + name);
        }

        cc = GetComponent<CharacterController>();
        if (!cc)
        {
            Debug.Log("No CharacterController Found on " + name);
        }


        //Fetch the current Animation clip information for the base layer
        currentClipInfo = anim.GetCurrentAnimatorClipInfo(0);

        //Access the Animation clip name
        Debug.Log(currentClipInfo[0].clip.name);

        //Access the current length of the clip
        Debug.Log(currentClipInfo[0].clip.length);

    }

    // Update is called once per frame
    void Update() {

        float moveForward = 0;

        if (cc.isGrounded) {
            moveForward = Input.GetAxis("Vertical");

            moveDirection = new Vector3(0, 0, moveForward);

            transform.Rotate(0, Input.GetAxis("Horizontal"), 0);

            moveDirection = transform.TransformDirection(moveDirection);
            moveDirection *= speed;

            if (Input.GetButton("Jump"))
                moveDirection.y = jumpSpeed;

            anim.SetBool("inAir", false);
        }
        else anim.SetBool("inAir", true);

        if (cc.velocity != Vector3.zero) anim.SetBool("moving", true);
        else anim.SetBool("moving", false);

        if (Input.GetMouseButtonDown(0)) anim.SetBool("punching", true);
        else anim.SetBool("punching", false);

        if (anim.GetBool("moving") || anim.GetBool("punching") || anim.GetBool("inAir")) anim.SetBool("dancing", false);
        else if (Input.GetKeyDown(KeyCode.LeftShift) ) anim.SetBool("dancing", true);

        moveDirection.y -= gravity * Time.deltaTime;

        cc.Move(moveDirection * Time.deltaTime);

        // What is the current Animator state
        currentBaseState = anim.GetCurrentAnimatorStateInfo(0);

        // Check if Character is in the moveState
        if (currentBaseState.fullPathHash == idleState) ;

        // Check if Character is in the idleState
        if (currentBaseState.fullPathHash == walkState) ;

        if (currentBaseState.fullPathHash == deathState) ;

    }
}
