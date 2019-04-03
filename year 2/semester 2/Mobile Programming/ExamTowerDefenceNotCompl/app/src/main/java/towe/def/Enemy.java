package towe.def;

/**
 * Enemy.java 
 * MIDTERM PROJECT "Tower Defence" 
 * * You may need to  modify this file to complete the project 
 * Please, include your name here:
 * You name:
 * Don't forget to comment any code you will add below
 * Your comments should start with your INITIALS!
 */

import java.util.Random;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Rect;

public class Enemy 
{
	public int x; 
	public int y; 

	public int speed;

	public int width;
	public int height;
	public GameView gameView;
	public Bitmap bmp;
	
	/** */
	public Enemy(GameView gameView, Bitmap bmp)
	{
		this.gameView = gameView;
		this.bmp = bmp;
		
		Random rnd = new Random();
		this.x = 1500;
		this.y = rnd.nextInt(300);
		this.speed = rnd.nextInt(10) +1;
		   
        this.width = 27;
        this.height = 40;
	}
	
	public void update()
	{
		x -= speed;
	}
	
	public void onDraw(Canvas c)
	{
		update();
		c.drawBitmap(bmp, x, y, null);
	}
}
