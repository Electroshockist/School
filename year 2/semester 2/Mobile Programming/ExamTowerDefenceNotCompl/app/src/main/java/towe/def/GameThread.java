package towe.def;

/**
 * GameThread.java 
 * MIDTERM PROJECT "Tower Defence" 
 * If you change this file, include YOUR comments
 * * Your comments should start with your INITIALS!**
 */


import android.graphics.Canvas;

  public class GameThread extends Thread
	{
	
	    private GameView view;	 
	   
	    private boolean running = false;
	  
	    public GameThread(GameView view) 
	    {
	          this.view = view;
	    }
	  
	    public void setRunning(boolean run) 
	    {
	          running = run;
	    }
	 
	    public void run()
	    {
	        while (running)
	        {
	            Canvas canvas = null;
	            try
	            {
	                canvas = view.getHolder().lockCanvas();
	                synchronized (view.getHolder())
	                {
	                    // 
	                    view.onDraw(canvas);
	                    view.testCollision();
	                }
	            }
	            catch (Exception e) { }
	            finally
	            {
	                if (canvas != null)
	                {
	                	view.getHolder().unlockCanvasAndPost(canvas);
	                }
	            }
	        }
	    }
}