using System;
using System.Collections;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;


public class GameManager : MonoBehaviour {

    [Serializable]
    struct Player {
        public Image image;
        public DataBool select, betray;
        public DataInt score;
        public Text scoreText;

        public void reset() {
            select.Value = false;
            betray.Value = false;
        }
    }
    Data data;

    [SerializeField] Text roundsRemainingText;

    [SerializeField]
    private Sprite empty, hidden, betray, cooperate;

    [SerializeField]
    private Player red, blue;

    private bool canPlay = true;

    [SerializeField]
    DataInt roundsRemaining;

    //reset
    private void reset() {
        red.reset();
        blue.reset();

        blue.image.sprite = empty;
        red.image.sprite = empty;
    }

    private void onChoose(Player p) {
        if(canPlay) {
            p.select.Value = true;
            updateGameState();
        }
    }

    //image updaters
    void updateGameState() {
        if(checkBothSeleted(red, blue)) {
            updateScore();
            updateRoundsRemaining();
            StartCoroutine(waitToRefresh());
        }
        else {
            setHiddenImageFromStatus(blue);
            setHiddenImageFromStatus(red);
        }
    }

    bool checkBothSeleted(Player p, Player other) {
        if(p.select.Value && other.select.Value) {
            p.image.sprite = getImageFromChoice(p.betray.Value);
            other.image.sprite = getImageFromChoice(other.betray.Value);
            return true;
        }
        return false;
    }

    Sprite getImageFromChoice(bool betray) {
        if(betray) {
            return this.betray;
        }
        return cooperate;
    }

    void setHiddenImageFromStatus(Player p) {
        if(p.select.Value) {
            p.image.sprite = hidden;
        }
    }
    IEnumerator waitToRefresh() {
        canPlay = false;
        yield return new WaitForSeconds(1.5f);
        reset();
        if(roundsRemaining.Value <= 0) {
            SetReloadText();
            yield return new WaitForSeconds(3.5f);
            SceneManager.LoadScene(SceneManager.GetActiveScene().name);
        }
        canPlay = true;
    }

    private void SetReloadText() {
        string winText = "";
        if(red.score.Value > blue.score.Value) {
            winText = "Red wins! ";
        }
        else if(red.score.Value < blue.score.Value) {
            winText = "Blue wins! ";
        }
        else {
            winText = "It's a tie! ";
        }

        roundsRemainingText.text = winText + "Resetting Scene";
    }

    private void updateRoundsRemaining() {
        roundsRemaining.Value--;
        roundsRemainingText.text = "Rounds Remaining: " + roundsRemaining.Value;
    }

    //Score
    private void updateScore() {
        Vector2 score;
        score = checkScore(red, blue);

        red.score.Value += (int)score.x;
        blue.score.Value += (int)score.y;

        displayScore(red.scoreText, red.score.Value);
        displayScore(blue.scoreText, blue.score.Value);
    }

    private void displayScore(Text t, int currentScore) {
        t.text = "Score: " + currentScore;
    }

    private Vector2 checkScore(Player p, Player other) {
        //if both betray, return 0
        if(p.betray.Value && other.betray.Value) {
            return Vector2.zero;
        }

        //if neither betray return 2
        if(!p.betray.Value && !other.betray.Value) {
            return new Vector2(2, 2);
        }

        //if only one betrays, the betrayer gets 3 and the cooperator gets 1
        if(xorBetray(p, other)) {
            return new Vector2(3, 1);
        }
        return new Vector2(1, 3);
    }
    private bool xorBetray(Player p, Player other) {
        if(p.betray.Value && !other.betray.Value) {
            return true;
        }
        return false;
    }

    //event functions
    private void onBetray(Player p) {
        if(canPlay) {
            p.betray.Value = true;
            onChoose(p);
        }
    }

    public void onBlueChoose() {
        onChoose(blue);
    }

    public void onRedChoose() {
        onChoose(red);
    }

    public void onBlueBetray() {
        onBetray(blue);
    }

    public void onRedBetray() {
        onBetray(red);
    }
}
