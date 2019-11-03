using System;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class Missle : MonoBehaviour {
	
    [Serializable]
	//holds a bunch of ray stuff
    private struct Ray {
        [HideInInspector]
        public bool isHitting, enabled;
        public float angle, length;
        public RaycastHit2D hit2D;
        public Color drawColor;

		//struct constructors don't exist, use this instead
        public void init() {
            isHitting = false;
            enabled = true;
        }
    }
	//this shit is for my game, dont add it
    public GameObject text;
    public GameObject target;
    Animator a;
    public bool isDead = false, canMove = true;
	
	//rocket speed
    public float speed;
	//fastest turning speed
    public float maxAngularSpeed;
	
	//the vector to get which the rocket is travelling to global space
    public Vector3 velocity = Vector3.zero;
    Vector3 orientation = Vector3.up;

	//sets wheter the rocket is player controlled
    [HideInInspector] public bool isPlayerControlled = true;

    //shortform for transform.position
	Vector3 pos;

	//rays. Defaulted to range of 2 with 35 and -35 degrees as default
    [SerializeField] private Ray rightRay;
    [SerializeField] private Ray leftRay;

    private void Start() {
        rightRay.init();
        leftRay.init();
		
		//game shit
        a = GetComponent<Animator>();
    }

    // Update is called once per frame
    void Update() {
		//dont use this
        if(isDead) {
            selfDestruct();
            return;
        }
		
		//dont use this if statement
        if(canMove) {
			//shortform
            pos = transform.position;
            Move(InterceptVector());
        }
    }

	//handles interceptor code(optionnal)
    private Vector3 InterceptVector() {
        if(target != null) {
            // 1.Calculate the relative velocity(closing velocity):
            //Vr = Vtarget – Vintercepter
            Vector3 vr = target.GetComponent<Enemy>().GetVelocity() - velocity;
            //2.Calculate the relative distance(range to close):
            //Sr = Starget – Sintercepter
            Vector3 sr = target.transform.position - transform.position;
            //3.Calculate the time to close
            //tc = | Sr |/| Vr |
            float tc = sr.magnitude / vr.magnitude;
            //4.Calculate the predicted position of the target.
            //St = Starget + Vtarget * tc
            return target.transform.position + target.GetComponent<Enemy>().velocity * tc;
        }
        return Vector3.zero;
    }

	//handles movement
    private void Move(Vector3 direction) {
		//detect if not player controlled
        if(!isPlayerControlled) {
            AI(direction);
        }
		//move based on velocity
        pos += velocity * Time.deltaTime;
        transform.position = pos;
    }

	//handles image rotation
    private void UpdateOrientation() {
        Vector3 angle = new Vector3(0, 0, -Mathf.Atan2(orientation.x, orientation.y) * Mathf.Rad2Deg);
        transform.eulerAngles = angle;
    }

	//checks whether enemy is to the right, get 1 if true and -1 if not
    private int checkRight(Vector3 dir) {
        Vector2 normal = new Vector2(orientation.y, -orientation.x);

        return Vector2.Dot(dir, normal) > 0 ? -1 : 1;
    }

//gets a vector relative to the orientation vector + an angle
    private Vector2 addAngleToOrientation(float angle) {
        return new Vector2(
             orientation.x * Mathf.Cos(angle * Mathf.Deg2Rad) - orientation.y * Mathf.Sin(angle * Mathf.Deg2Rad),
             orientation.x * Mathf.Sin(angle * Mathf.Deg2Rad) + orientation.y * Mathf.Cos(angle * Mathf.Deg2Rad)
            );
    }

	//check if a ray is currently hitting something
    private bool rayCast(Ray r) {
		//checks if ray is enabled
        if(r.enabled) {
			//get angle as ray's angle +orientation vector
            Vector2 angle = addAngleToOrientation(r.angle).normalized;
			//cast the ray
            r.hit2D = Physics2D.Raycast(pos, angle, 2.0f);
			//draw the ray
            Debug.DrawRay(pos, angle * r.length, r.drawColor);

			//check if the given ray is hitting an obstacle and is not null
            if(r.hit2D.collider != null && r.hit2D.collider.tag == "Obstacle") {
                r.isHitting = true;
            }
            else {
                r.isHitting = false;
            }
            return r.isHitting;
        }
		//if ray is disabled, act as if it's not hitting anything
        return false;
    }


	//handles AI
    private void AI(Vector3 direction) {
		//the rocket's direction isthe given direction - the rocket's position
        Vector3 dir = direction - transform.position;

		//the maximum turnable angle in the given timestep
        float availableAngle = maxAngularSpeed * Time.deltaTime;

		//the angle to be facing the target
        //theta = acos(A . B / |A||B|)
        float targetAngle = Mathf.Acos(
            Vector2.Dot(dir, orientation) / (dir.magnitude * orientation.magnitude)) * Mathf.Rad2Deg;

		//dir has to be normalized to make sure the rocket is always moving uniformly
        dir.Normalize();
		
        //raycasting
		//if the left ray is currently hitting
        if(rayCast(leftRay)) {
			//turn right
            dir = addAngleToOrientation(-availableAngle);
			//disable the right ray
            rightRay.enabled = false;
        }
        else {
			//enable the right ray
            rightRay.enabled = true;
        }
		
		//same, but for the right ray
        if(rayCast(rightRay)) {
            dir = addAngleToOrientation(availableAngle);
            leftRay.enabled = false;
        }
        else {
            leftRay.enabled = true;
        }
		
		//if neither ray is hitting, and the target angle > available angle, turn towards the target as far as it can
        if(targetAngle > availableAngle && !rightRay.isHitting && !leftRay.isHitting) {
            availableAngle *= checkRight(dir);
            dir = addAngleToOrientation(availableAngle);
        }

        // Update orientation 
        orientation = dir;
        UpdateOrientation();
		//set velocity
        velocity = orientation * speed;
    }

	//do shit when hit
    private void OnTriggerEnter2D(Collider2D collision) {
        text.SetActive(true);
        Text t = text.GetComponent<Text>();
        if(collision.gameObject.tag == "Enemy") {
            t.text = "You Win!";
            Destroy(collision.gameObject);
        }
        else {
            t.text = "You Lose!";
        }
        startAnim();
    }
    private void startAnim() {
        a.SetBool("isDead", true);
    }

	//relaod scene(for me)
    private void selfDestruct() {
        SceneManager.LoadScene(SceneManager.GetActiveScene().name);
    }
}
